#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QPoint>
#include <QTimer>
#include "USBCamera.h"
#include "preview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
  
private:
	Ui::MainWindow *ui;
	preview *m_previw;
	int m_previwindex;
	QDesktopWidget desktop;
	QPropertyAnimation* animation;
	QTimer *remainTimer;
	QTimer *m_timer;
	CUSBCamera *m_ucam;
	bool isShow;

	void showAnimation();
private slots:
	void closeAnimation();
	void TimeDone();
};

#endif // MAINWINDOW_H
