#include "lyric.h"
#include "ui_lyric.h"
#include <iostream>
#include <QLabel>

lyric::lyric(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lyric)
{
    ui->setupUi(this);
    setWindowFlags (Qt::FramelessWindowHint);
}
lyric::~lyric()
{
    delete ui;
}




