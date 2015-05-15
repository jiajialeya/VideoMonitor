#include "preview.h"
#include "ui_preview.h"

preview::preview(CUSBCamera *ucam, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::preview),
	m_ucam(ucam)
{
    ui->setupUi(this);
	m_timer = new QTimer(this);
	m_timer->start(20);
	connect( m_timer, SIGNAL(timeout()), this, SLOT(TimeDone()));
	//设置显示视频用的Label  
	m_imageLabel = new QLabel(this);  
	ui->verticalLayout->addWidget(m_imageLabel);  
}

preview::~preview()
{
    delete ui;
	delete m_timer;
	delete m_imageLabel;
}

void preview::paintEvent(QPaintEvent *e)  
{  
	Mat img;
	m_ucam->GetImgResult().clone().copyTo(img);
	if(img.empty())
	{
		return;
	}

	QImage image = mat_to_qimage_cpy(img); 
	m_imageLabel->setPixmap(QPixmap::fromImage(image));  
	m_imageLabel->resize(image.size());  
	m_imageLabel->show();  
}  

void preview::TimeDone()
{ 
	this->update();
}

QImage preview::mat_to_qimage_cpy(cv::Mat &mat, int qimage_format)
{
	if(mat.type() == CV_8UC3)
	{        
		cv::cvtColor(mat, mat, CV_BGR2RGB);

		return QImage((uchar*)(mat.data), mat.cols, mat.rows, mat.step, QImage::Format_RGB888);  
	}

	if(mat.type() == CV_8U)
	{
		return QImage((uchar*)(mat.data), mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
	}

	if(mat.type() == CV_8UC4)
	{        
		if(qimage_format == -1)
		{
			return QImage((uchar*)(mat.data), mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		}
		else
		{
			return QImage((uchar*)(mat.data), mat.cols, mat.rows, mat.step, QImage::Format(qimage_format));
		}
	}
	return QImage();
}
