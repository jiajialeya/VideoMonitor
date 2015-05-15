#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint | Qt::FramelessWindowHint);//不在任务栏显示，隐藏菜单栏
	ui->centralWidget->setTabsClosable(false);

	m_ucam = new CUSBCamera(320,240);
	m_ucam->StartGrab();
	m_ucam->StartProc();

	m_previw = new preview(m_ucam, this);
	m_previwindex = ui->centralWidget->addTab(m_previw, tr("通知"));

	this->move((desktop.availableGeometry().width()-this->width()),desktop.availableGeometry().height());//初始化位置到右下角

	isShow = false;
	animation=new QPropertyAnimation(this,"pos");

	m_timer = new QTimer(this);
	m_timer->start(40);
	connect( m_timer, SIGNAL(timeout()), this, SLOT(TimeDone()));
}

MainWindow::~MainWindow()
{
	m_ucam->StopProc();
	m_ucam->StopGrab();
	delete m_ucam;
	delete m_previw;
	delete m_timer;
	delete animation;
	animation=NULL;
}

//弹出动画
void MainWindow::showAnimation()
{
	//显示弹出框动画
	animation->setDuration(1000);
	animation->setStartValue(QPoint(this->x(),this->y()));
	animation->setEndValue(QPoint((desktop.availableGeometry().width()-this->width()),(desktop.availableGeometry().height()-this->height())));
	animation->start();
}
//关闭动画
void MainWindow::closeAnimation()
{
	//弹出框回去动画
	animation->setDuration(2000);
	animation->setStartValue(QPoint(this->x(),this->y()));
	animation->setEndValue(QPoint((desktop.availableGeometry().width()-this->width()),desktop.availableGeometry().height()));
	animation->start();
}

void MainWindow::TimeDone()
{
	if(m_ucam->GetShowStatus() && !isShow)
	{
		showAnimation(); //开始显示右下角弹出框
	}
	if(!m_ucam->GetShowStatus() && isShow)
	{
		closeAnimation();
		m_ucam->ClcCountNum();
	}
	isShow = m_ucam->GetShowStatus();
}
