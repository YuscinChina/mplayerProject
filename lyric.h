#ifndef LYRIC_H
#define LYRIC_H

#include <QWidget>

namespace Ui {
class lyric;
}

class lyric : public QWidget
{
    Q_OBJECT

public:
    Ui::lyric *ui;
    explicit lyric(QWidget *parent = 0);
    ~lyric();

private:
    //Ui::lyric *ui;
};

#endif // LYRIC_H
