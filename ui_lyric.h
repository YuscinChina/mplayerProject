/********************************************************************************
** Form generated from reading UI file 'lyric.ui'
**
** Created: Tue Sep 22 16:58:25 2020
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYRIC_H
#define UI_LYRIC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lyric
{
public:
    QPushButton *pushButtonClose;
    QLabel *labelPicture;
    QLabel *labelLyricName;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelLyric01;
    QLabel *labelLyric02;
    QLabel *labelLyric03;
    QLabel *labelLyric04;
    QLabel *labelLyric05;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelSong01;
    QLabel *labelSong02;

    void setupUi(QWidget *lyric)
    {
        if (lyric->objectName().isEmpty())
            lyric->setObjectName(QString::fromUtf8("lyric"));
        lyric->resize(1024, 600);
        pushButtonClose = new QPushButton(lyric);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(0, 0, 1024, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/lyricClose.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonClose->setIcon(icon);
        pushButtonClose->setIconSize(QSize(300, 30));
        pushButtonClose->setFlat(true);
        labelPicture = new QLabel(lyric);
        labelPicture->setObjectName(QString::fromUtf8("labelPicture"));
        labelPicture->setGeometry(QRect(30, 90, 381, 391));
        labelPicture->setFrameShape(QFrame::Box);
        labelLyricName = new QLabel(lyric);
        labelLyricName->setObjectName(QString::fromUtf8("labelLyricName"));
        labelLyricName->setGeometry(QRect(430, 60, 581, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(8);
        labelLyricName->setFont(font);
        labelLyricName->setFrameShape(QFrame::Box);
        labelLyricName->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(lyric);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(440, 220, 531, 271));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelLyric01 = new QLabel(layoutWidget);
        labelLyric01->setObjectName(QString::fromUtf8("labelLyric01"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font1.setPointSize(6);
        labelLyric01->setFont(font1);
        labelLyric01->setFrameShape(QFrame::NoFrame);
        labelLyric01->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelLyric01);

        labelLyric02 = new QLabel(layoutWidget);
        labelLyric02->setObjectName(QString::fromUtf8("labelLyric02"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font2.setPointSize(7);
        labelLyric02->setFont(font2);
        labelLyric02->setFrameShape(QFrame::NoFrame);
        labelLyric02->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelLyric02);

        labelLyric03 = new QLabel(layoutWidget);
        labelLyric03->setObjectName(QString::fromUtf8("labelLyric03"));
        labelLyric03->setFont(font2);
        labelLyric03->setFrameShape(QFrame::NoFrame);
        labelLyric03->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelLyric03);

        labelLyric04 = new QLabel(layoutWidget);
        labelLyric04->setObjectName(QString::fromUtf8("labelLyric04"));
        labelLyric04->setFont(font2);
        labelLyric04->setFrameShape(QFrame::NoFrame);
        labelLyric04->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelLyric04);

        labelLyric05 = new QLabel(layoutWidget);
        labelLyric05->setObjectName(QString::fromUtf8("labelLyric05"));
        labelLyric05->setFont(font1);
        labelLyric05->setFrameShape(QFrame::NoFrame);
        labelLyric05->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelLyric05);

        widget = new QWidget(lyric);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(560, 120, 311, 91));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelSong01 = new QLabel(widget);
        labelSong01->setObjectName(QString::fromUtf8("labelSong01"));
        labelSong01->setFont(font2);
        labelSong01->setFrameShape(QFrame::NoFrame);
        labelSong01->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelSong01);

        labelSong02 = new QLabel(widget);
        labelSong02->setObjectName(QString::fromUtf8("labelSong02"));
        labelSong02->setFont(font2);
        labelSong02->setFrameShape(QFrame::NoFrame);
        labelSong02->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelSong02);


        retranslateUi(lyric);

        QMetaObject::connectSlotsByName(lyric);
    } // setupUi

    void retranslateUi(QWidget *lyric)
    {
        lyric->setWindowTitle(QApplication::translate("lyric", "Form", 0, QApplication::UnicodeUTF8));
        pushButtonClose->setText(QString());
        labelPicture->setText(QString());
        labelLyricName->setText(QString());
        labelLyric01->setText(QString());
        labelLyric02->setText(QString());
        labelLyric03->setText(QString());
        labelLyric04->setText(QString());
        labelLyric05->setText(QString());
        labelSong01->setText(QString());
        labelSong02->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class lyric: public Ui_lyric {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYRIC_H
