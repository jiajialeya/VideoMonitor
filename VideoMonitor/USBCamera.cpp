#include "USBCamera.h"


CUSBCamera::CUSBCamera(int width, int height):
	m_width(width),
	m_height(height)
{
	m_status = 0;
	m_waitForProc = false;
	m_capture.open(0);
	bg_model.setBool("detectShadows",true);
	bg_model.setDouble("backgroundRatio",0.7);
	isShow = false;
	m_count = 0;
}


CUSBCamera::~CUSBCamera(void)
{
}

unsigned int _stdcall CUSBCamera::GrabThread(void* lpParam)
{
	CUSBCamera* p = (CUSBCamera*)lpParam;

	while((p->m_status & STATUS_GRAB) == STATUS_GRAB)
	{
		//int64 t = getTickCount();
		p->m_capture >> p->m_img;

		if(!p->m_img.empty())
		{
			p->m_waitForProc = true;
		}
		Sleep(1);
		//t = getTickCount() - t;
		//printf("Time elapsed(GrabThread): %fms\n", t*1000/getTickFrequency());

	}
	return 0;
}

void CUSBCamera::StartGrab()
{
	if((m_status & STATUS_GRAB) == 0)
	{
		m_status ^= STATUS_GRAB;
		m_grabHandle = (HANDLE)_beginthreadex(NULL, 0, GrabThread, (void*)this, 0, 0);
	}
}

void CUSBCamera::StopGrab()
{
	if((m_status & STATUS_GRAB) == STATUS_GRAB)
	{
		m_status ^= STATUS_GRAB;
		WaitForSingleObject(m_grabHandle, INFINITE);
	}
}

unsigned int _stdcall CUSBCamera::ProcThread(void* lpParam)
{
	CUSBCamera* p = (CUSBCamera*)lpParam;
	Mat img;
	while((p->m_status & STATUS_PROC) == STATUS_PROC)
	{
		if(p->m_waitForProc)
		{
			p->m_img.copyTo(img);

			//int64 t = getTickCount();

			p->MoveDetect(img);

			/*t = getTickCount() - t;
			printf("Time elapsed(ProcThread): %fms\n", t*1000/getTickFrequency());*/
		}
		Sleep(80);
	}

	return 0;
}

void CUSBCamera::StartProc()
{
	if((m_status & STATUS_PROC) == 0)
	{
		m_status ^= STATUS_PROC;
		m_waitForProc = false;
		m_procHandle = (HANDLE)_beginthreadex(NULL, 0, ProcThread, (void*)this, 0, 0);
	}
}

void CUSBCamera::StopProc()
{
	if((m_status & STATUS_PROC) == STATUS_PROC)
	{
		m_status ^= STATUS_PROC;
		WaitForSingleObject(m_procHandle, INFINITE);
	}
}

void CUSBCamera::MoveDetect(Mat &img)
{
	Mat fgmask, fgimg;
	Mat element;

	bg_model(img, fgmask);
	//过滤孤点噪声
	element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(1, 1));
	morphologyEx(fgmask, fgmask, MORPH_OPEN, element);

	//连通区域
	element = getStructuringElement(MORPH_RECT, Size(7, 7), Point(3, 3));
	morphologyEx(fgmask, fgmask, MORPH_CLOSE, element);

	fgimg = Scalar::all(0);
	img.copyTo(fgimg, fgmask);


	Mat mask;
	fgmask.copyTo(mask);
	vector<vector<Point>> contours0;
	//轮廓检测
	findContours(mask, contours0, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	int Xmin = 50000;
	int Ymin = 50000;
	int Xmax = 0;
	int Ymax = 0;	
	isShow = false;
	bool tmp = false;
	for(unsigned int i = 0; i < contours0.size(); i++)
	{
		double area = contourArea(contours0[i]);
		if(area > 200)
		{
			Rect rec = boundingRect(contours0[i]);
			if(Xmin > rec.x) Xmin = rec.x;
			if(Ymin > rec.y) Ymin = rec.y;
			if(Xmax < rec.x + rec.width) Xmax = rec.x + rec.width;
			if(Ymax < rec.y + rec.height) Ymax = rec.y + rec.height;
			tmp = true;
		}
	}
	if(tmp)  //有动目标
	{
		m_count++;
		if(m_count > 3)  //连续三次出现
		{
			isShow = true;
		}
	}

	rectangle(fgimg, Point(Xmin, Ymin), Point(Xmax, Ymax), cv::Scalar(0,0,255), 1.5);
	float bit1 = img.cols*1.0/m_width;
	float bit2 =  img.rows*1.0/m_height;
	float bit;

	bit = bit1 > bit2 ? bit1 : bit2;
	int wid = img.cols * 1 / bit / 4;
	wid *= 4;
	int hei = img.rows *1 / bit / 4;
	hei *= 4;
	resize(fgimg, m_imgshow, Size(wid, hei), 1, 1);
}