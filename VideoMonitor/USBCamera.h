#pragma once
#include <windows.h>
#include <process.h>
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#define STATUS_GRAB			0x0001
#define STATUS_PROC			0x0002


class CUSBCamera
{
public:
	CUSBCamera(int width, int height);
	~CUSBCamera(void);
private:
	//多线程变量
	int m_status;
	HANDLE m_grabHandle;
	HANDLE m_procHandle;
	bool m_waitForProc;

	VideoCapture m_capture;
	Mat m_img;
	Mat m_imgshow;
	int m_width;
	int m_height;

	BackgroundSubtractorMOG2 bg_model;
	bool isShow;
	int m_count;
public:
	void StartGrab();
	void StopGrab();
	void StartProc();
	void StopProc();
	Mat GetImgResult(void){return m_imgshow;}
	bool GetShowStatus(void){return isShow;}
	void ClcCountNum(){m_count = 0;}
private:
	static unsigned int _stdcall GrabThread(void* lpParam);
	static unsigned int _stdcall ProcThread(void* lpParam);

	void MoveDetect(Mat &img);
};

