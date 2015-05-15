/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jan 23 15:04:51 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QTabWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Managerview;
    QAction *action_aboutProgram;
    QAction *Preview;
    QAction *Mapview;
    QAction *action_fourview;
    QAction *action_nineview;
    QAction *action_sixview;
    QAction *Systemview;
    QAction *actionAa;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *OpenFile;
    QTabWidget *centralWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(289, 207);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/file/camera1.png"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        Managerview = new QAction(MainWindow);
        Managerview->setObjectName(QString::fromUtf8("Managerview"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/file/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8("set.png"), QSize(), QIcon::Normal, QIcon::On);
        Managerview->setIcon(icon1);
        action_aboutProgram = new QAction(MainWindow);
        action_aboutProgram->setObjectName(QString::fromUtf8("action_aboutProgram"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/file/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/new/prefix1/Resources/set.png"), QSize(), QIcon::Normal, QIcon::On);
        action_aboutProgram->setIcon(icon2);
        Preview = new QAction(MainWindow);
        Preview->setObjectName(QString::fromUtf8("Preview"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/file/display.png"), QSize(), QIcon::Normal, QIcon::Off);
        Preview->setIcon(icon3);
        Mapview = new QAction(MainWindow);
        Mapview->setObjectName(QString::fromUtf8("Mapview"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/file/map.png"), QSize(), QIcon::Normal, QIcon::Off);
        Mapview->setIcon(icon4);
        action_fourview = new QAction(MainWindow);
        action_fourview->setObjectName(QString::fromUtf8("action_fourview"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/file/2x2.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_fourview->setIcon(icon5);
        action_nineview = new QAction(MainWindow);
        action_nineview->setObjectName(QString::fromUtf8("action_nineview"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/file/3x3.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_nineview->setIcon(icon6);
        action_sixview = new QAction(MainWindow);
        action_sixview->setObjectName(QString::fromUtf8("action_sixview"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/file/6.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_sixview->setIcon(icon7);
        Systemview = new QAction(MainWindow);
        Systemview->setObjectName(QString::fromUtf8("Systemview"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/file/computer.png"), QSize(), QIcon::Normal, QIcon::Off);
        Systemview->setIcon(icon8);
        actionAa = new QAction(MainWindow);
        actionAa->setObjectName(QString::fromUtf8("actionAa"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        OpenFile = new QAction(MainWindow);
        OpenFile->setObjectName(QString::fromUtf8("OpenFile"));
        centralWidget = new QTabWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\270\211\347\273\264\351\207\215\345\273\272", 0, QApplication::UnicodeUTF8));
        Managerview->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\350\247\206\345\233\276", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Managerview->setToolTip(QApplication::translate("MainWindow", "\350\256\276\345\244\207\350\247\206\345\233\276", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_aboutProgram->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\345\256\230\347\275\221", 0, QApplication::UnicodeUTF8));
        Preview->setText(QApplication::translate("MainWindow", "\351\242\204\350\247\210\350\247\206\345\233\276", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Preview->setToolTip(QApplication::translate("MainWindow", "\351\242\204\350\247\210\350\257\225\345\233\276", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        Mapview->setText(QApplication::translate("MainWindow", "\345\234\260\345\233\276\350\247\206\345\233\276", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Mapview->setToolTip(QApplication::translate("MainWindow", "\345\234\260\345\233\276\350\247\206\345\233\276", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_fourview->setText(QApplication::translate("MainWindow", "\345\233\233\345\210\206\345\261\217", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_fourview->setToolTip(QApplication::translate("MainWindow", "\345\233\233\345\210\206\345\261\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_nineview->setText(QApplication::translate("MainWindow", "\344\271\235\345\210\206\345\261\217", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_nineview->setToolTip(QApplication::translate("MainWindow", "\344\271\235\345\210\206\345\261\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_sixview->setText(QApplication::translate("MainWindow", "\345\205\255\345\210\206\345\261\217", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_sixview->setToolTip(QApplication::translate("MainWindow", "\345\205\255\345\210\206\345\261\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        Systemview->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Systemview->setToolTip(QApplication::translate("MainWindow", "\347\263\273\347\273\237\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAa->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\347\233\221\350\247\206\347\202\271", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("MainWindow", "\351\242\204\350\247\210\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\256\241\347\220\206\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        action_4->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        action_5->setText(QApplication::translate("MainWindow", "\344\272\213\344\273\266\350\256\260\345\275\225\350\241\250", 0, QApplication::UnicodeUTF8));
        OpenFile->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
