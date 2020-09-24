/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Wed Sep 23 11:12:49 2020
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *timeLabel;
    QPushButton *pushButtonMenu;
    QPushButton *pushButtonMy;
    QPushButton *pushButtonMin;
    QPushButton *pushButtonMax;
    QPushButton *pushButtonQuit;
    QLabel *labelBack1;
    QLabel *labelBack2;
    QPushButton *pushButtonPlay;
    QPushButton *pushButtonBefore;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonSound;
    QSlider *horizontalSlider;
    QSlider *SliderJDT;
    QListWidget *listPlay;
    QPushButton *pushButtonLRC;
    QPushButton *pushButtonSingle;
    QPushButton *pushButtonList;
    QLabel *labelPlayType;
    QComboBox *comboBoxStyle;
    QLabel *labelSongName;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1024, 600);
        Widget->setMouseTracking(false);
        timeLabel = new QLabel(Widget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(60, 520, 251, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Nirmala UI"));
        timeLabel->setFont(font);
        timeLabel->setStyleSheet(QString::fromUtf8("color:white;"));
        pushButtonMenu = new QPushButton(Widget);
        pushButtonMenu->setObjectName(QString::fromUtf8("pushButtonMenu"));
        pushButtonMenu->setGeometry(QRect(731, 11, 52, 49));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/fenlei.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonMenu->setIcon(icon);
        pushButtonMenu->setIconSize(QSize(50, 50));
        pushButtonMenu->setFlat(true);
        pushButtonMy = new QPushButton(Widget);
        pushButtonMy->setObjectName(QString::fromUtf8("pushButtonMy"));
        pushButtonMy->setGeometry(QRect(789, 11, 51, 49));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonMy->setIcon(icon1);
        pushButtonMy->setIconSize(QSize(50, 50));
        pushButtonMy->setFlat(true);
        pushButtonMin = new QPushButton(Widget);
        pushButtonMin->setObjectName(QString::fromUtf8("pushButtonMin"));
        pushButtonMin->setGeometry(QRect(851, 11, 49, 49));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonMin->setIcon(icon2);
        pushButtonMin->setIconSize(QSize(50, 50));
        pushButtonMin->setFlat(true);
        pushButtonMax = new QPushButton(Widget);
        pushButtonMax->setObjectName(QString::fromUtf8("pushButtonMax"));
        pushButtonMax->setGeometry(QRect(906, 11, 49, 49));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonMax->setIcon(icon3);
        pushButtonMax->setIconSize(QSize(50, 50));
        pushButtonMax->setFlat(true);
        pushButtonQuit = new QPushButton(Widget);
        pushButtonQuit->setObjectName(QString::fromUtf8("pushButtonQuit"));
        pushButtonQuit->setGeometry(QRect(961, 11, 49, 49));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonQuit->setIcon(icon4);
        pushButtonQuit->setIconSize(QSize(50, 50));
        pushButtonQuit->setFlat(true);
        labelBack1 = new QLabel(Widget);
        labelBack1->setObjectName(QString::fromUtf8("labelBack1"));
        labelBack1->setGeometry(QRect(0, 0, 1024, 70));
        labelBack2 = new QLabel(Widget);
        labelBack2->setObjectName(QString::fromUtf8("labelBack2"));
        labelBack2->setGeometry(QRect(0, 500, 1024, 100));
        pushButtonPlay = new QPushButton(Widget);
        pushButtonPlay->setObjectName(QString::fromUtf8("pushButtonPlay"));
        pushButtonPlay->setGeometry(QRect(469, 501, 100, 100));
        pushButtonPlay->setIconSize(QSize(90, 90));
        pushButtonPlay->setCheckable(false);
        pushButtonPlay->setFlat(true);
        pushButtonBefore = new QPushButton(Widget);
        pushButtonBefore->setObjectName(QString::fromUtf8("pushButtonBefore"));
        pushButtonBefore->setGeometry(QRect(371, 506, 92, 88));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/beforesong.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonBefore->setIcon(icon5);
        pushButtonBefore->setIconSize(QSize(80, 80));
        pushButtonBefore->setFlat(true);
        pushButtonNext = new QPushButton(Widget);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(577, 506, 92, 88));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/nextsong.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonNext->setIcon(icon6);
        pushButtonNext->setIconSize(QSize(80, 80));
        pushButtonNext->setFlat(true);
        pushButtonSound = new QPushButton(Widget);
        pushButtonSound->setObjectName(QString::fromUtf8("pushButtonSound"));
        pushButtonSound->setGeometry(QRect(810, 520, 51, 51));
        pushButtonSound->setIconSize(QSize(50, 50));
        pushButtonSound->setFlat(true);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(870, 530, 131, 31));
        horizontalSlider->setSizeIncrement(QSize(0, 0));
        horizontalSlider->setFocusPolicy(Qt::StrongFocus);
        horizontalSlider->setContextMenuPolicy(Qt::DefaultContextMenu);
        horizontalSlider->setAcceptDrops(false);
        horizontalSlider->setLayoutDirection(Qt::LeftToRight);
        horizontalSlider->setAutoFillBackground(false);
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
" \n"
"border: 0px solid #bbb;\n"
" \n"
"}\n"
" \n"
"QSlider::sub-page:horizontal {\n"
" \n"
"background: rgb(220,20,60);\n"
" \n"
"border-radius: 0px;\n"
" \n"
"margin-top:8px;\n"
" \n"
"margin-bottom:8px;\n"
" \n"
"}\n"
" \n"
"QSlider::add-page:horizontal {\n"
" \n"
"background: rgb(255,255, 255);\n"
" \n"
"border: 0px solid #777;\n"
" \n"
"border-radius: 2px;\n"
" \n"
"margin-top:8px;\n"
" \n"
"margin-bottom:8px;\n"
" \n"
"}\n"
" \n"
"QSlider::handle:horizontal {\n"
" \n"
"background: rgb(220,20,60);\n"
" \n"
"border: 1px solid rgb(255,153,102);\n"
" \n"
"width: 30px;\n"
" \n"
"height:20px;\n"
" \n"
"border-radius: 7px;\n"
" \n"
"margin-top:2px;\n"
" \n"
"margin-bottom:2px;\n"
" \n"
"}\n"
" \n"
"QSlider::handle:horizontal:hover {\n"
" \n"
"background: rgb(255,128,6);\n"
" \n"
"border: 1px solid rgba(102,102,102,102);\n"
" \n"
"border-radius: 7px;\n"
" \n"
"}\n"
" \n"
"QSlider::sub-page:horizontal:disabled {\n"
" \n"
"background: #bbb;\n"
" \n"
"border-color: #999;\n"
" \n"
"}"
                        "\n"
" \n"
"QSlider::add-page:horizontal:disabled {\n"
" \n"
"background: #eee;\n"
" \n"
"border-color: #999;\n"
" \n"
"}\n"
" \n"
"QSlider::handle:horizontal:disabled {\n"
" \n"
"background: #eee;\n"
" \n"
"border: 1px solid #aaa;\n"
" \n"
"border-radius: 4px;\n"
" \n"
"}"));
        horizontalSlider->setSingleStep(0);
        horizontalSlider->setSliderPosition(99);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::NoTicks);
        horizontalSlider->setTickInterval(10);
        SliderJDT = new QSlider(Widget);
        SliderJDT->setObjectName(QString::fromUtf8("SliderJDT"));
        SliderJDT->setGeometry(QRect(12, 471, 1000, 31));
        SliderJDT->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
" \n"
"border: 0px solid #bbb;\n"
" \n"
"}\n"
" \n"
"QSlider::sub-page:horizontal {\n"
" \n"
"background: rgb(220,20,60);\n"
" \n"
"border-radius: 0px;\n"
" \n"
"margin-top:8px;\n"
" \n"
"margin-bottom:8px;\n"
" \n"
"}\n"
" \n"
"QSlider::add-page:horizontal {\n"
" \n"
"background: rgb(255,255, 255);\n"
" \n"
"border: 0px solid #777;\n"
" \n"
"border-radius: 2px;\n"
" \n"
"margin-top:8px;\n"
" \n"
"margin-bottom:8px;\n"
" \n"
"}\n"
" \n"
"QSlider::handle:horizontal {\n"
" \n"
"background: rgb(220,20,60);\n"
" \n"
"border: 1px solid rgb(255,153,102);\n"
" \n"
"width: 30px;\n"
" \n"
"height:80px;\n"
" \n"
"border-radius: 7px;\n"
" \n"
"margin-top:2px;\n"
" \n"
"margin-bottom:2px;\n"
" \n"
"}\n"
" \n"
"QSlider::handle:horizontal:hover {\n"
" \n"
"background: rgb(255,128,6);\n"
" \n"
"border: 1px solid rgba(102,102,102,102);\n"
" \n"
"border-radius: 7px;\n"
" \n"
"}\n"
" \n"
"QSlider::sub-page:horizontal:disabled {\n"
" \n"
"background: #bbb;\n"
" \n"
"border-color: #999;\n"
" \n"
"}"
                        "\n"
" \n"
"QSlider::add-page:horizontal:disabled {\n"
" \n"
"background: #eee;\n"
" \n"
"border-color: #999;\n"
" \n"
"}\n"
" \n"
"QSlider::handle:horizontal:disabled {\n"
" \n"
"background: #eee;\n"
" \n"
"border: 1px solid #aaa;\n"
" \n"
"border-radius: 4px;\n"
" \n"
"}"));
        SliderJDT->setMaximum(100);
        SliderJDT->setOrientation(Qt::Horizontal);
        SliderJDT->setTickPosition(QSlider::NoTicks);
        listPlay = new QListWidget(Widget);
        listPlay->setObjectName(QString::fromUtf8("listPlay"));
        listPlay->setGeometry(QRect(50, 92, 391, 371));
        pushButtonLRC = new QPushButton(Widget);
        pushButtonLRC->setObjectName(QString::fromUtf8("pushButtonLRC"));
        pushButtonLRC->setGeometry(QRect(750, 520, 51, 51));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/shouqi.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonLRC->setIcon(icon7);
        pushButtonLRC->setIconSize(QSize(50, 50));
        pushButtonLRC->setFlat(true);
        pushButtonSingle = new QPushButton(Widget);
        pushButtonSingle->setObjectName(QString::fromUtf8("pushButtonSingle"));
        pushButtonSingle->setGeometry(QRect(600, 380, 75, 75));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/danqu.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSingle->setIcon(icon8);
        pushButtonSingle->setIconSize(QSize(70, 70));
        pushButtonList = new QPushButton(Widget);
        pushButtonList->setObjectName(QString::fromUtf8("pushButtonList"));
        pushButtonList->setGeometry(QRect(825, 380, 75, 75));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/xunhuan.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonList->setIcon(icon9);
        pushButtonList->setIconSize(QSize(70, 70));
        labelPlayType = new QLabel(Widget);
        labelPlayType->setObjectName(QString::fromUtf8("labelPlayType"));
        labelPlayType->setGeometry(QRect(600, 330, 300, 41));
        labelPlayType->setFrameShape(QFrame::NoFrame);
        labelPlayType->setAlignment(Qt::AlignCenter);
        comboBoxStyle = new QComboBox(Widget);
        comboBoxStyle->setObjectName(QString::fromUtf8("comboBoxStyle"));
        comboBoxStyle->setGeometry(QRect(0, 0, 191, 61));
        labelSongName = new QLabel(Widget);
        labelSongName->setObjectName(QString::fromUtf8("labelSongName"));
        labelSongName->setGeometry(QRect(580, 180, 371, 71));
        labelSongName->setLayoutDirection(Qt::LeftToRight);
        labelSongName->setFrameShape(QFrame::Box);
        labelSongName->setAlignment(Qt::AlignCenter);
        labelBack1->raise();
        labelBack2->raise();
        pushButtonMenu->raise();
        pushButtonMy->raise();
        pushButtonMin->raise();
        pushButtonMax->raise();
        pushButtonQuit->raise();
        pushButtonPlay->raise();
        pushButtonBefore->raise();
        pushButtonNext->raise();
        timeLabel->raise();
        pushButtonSound->raise();
        horizontalSlider->raise();
        SliderJDT->raise();
        listPlay->raise();
        pushButtonLRC->raise();
        pushButtonSingle->raise();
        pushButtonList->raise();
        labelPlayType->raise();
        comboBoxStyle->raise();
        labelSongName->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QString());
        pushButtonMenu->setText(QString());
        pushButtonMy->setText(QString());
        pushButtonMin->setText(QString());
        pushButtonMax->setText(QString());
        pushButtonQuit->setText(QString());
        labelBack1->setText(QString());
        labelBack2->setText(QString());
        pushButtonPlay->setText(QString());
        pushButtonBefore->setText(QString());
        pushButtonNext->setText(QString());
        pushButtonSound->setText(QString());
        pushButtonLRC->setText(QString());
        pushButtonSingle->setText(QString());
        pushButtonList->setText(QString());
        labelPlayType->setText(QString());
        comboBoxStyle->clear();
        comboBoxStyle->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\344\270\273\351\242\2301", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\344\270\273\351\242\2302", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\344\270\273\351\242\2303", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\344\270\273\351\242\2304", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\344\270\273\351\242\2305", 0, QApplication::UnicodeUTF8)
        );
        labelSongName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
