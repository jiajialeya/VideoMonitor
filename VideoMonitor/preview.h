#ifndef PREVIEW_H
#define PREVIEW_H

#include <QWidget>
#include "USBCamera.h"
#include <QPaintEvent>  
#include <QTimer>  
#include <QPainter>  
#include <QPixmap>  
#include <QLabel>  
#include <QImage> 

namespace Ui {
class preview;
}

class preview : public QWidget
{
    Q_OBJECT
    
public:
    explicit preview(CUSBCamera *ucam, QWidget *parent = 0);
    ~preview();
    
private:
    Ui::preview *ui;
	QTimer *m_timer;
	CUSBCamera *m_ucam;
	QLabel *m_imageLabel;  
private:
	QImage mat_to_qimage_cpy(cv::Mat &mat, int qimage_format = -1);
private slots:
	void TimeDone();
protected:  
	void paintEvent(QPaintEvent *e);
};

#endif // PREVIEW_H
