#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
#include <vector>
#include <map>
#include <QString>
#include <pthread.h>
#include <QListWidgetItem>
#include "lyric.h"
#include "ui_lyric.h"

using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    friend void *sendCmdFunc(void *arg);
    friend void *recvPipeMsg(void *arg);
    friend void *playingLyric(void *arg);

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void startMplayer(void);//开启mplayer播放器
    void mplayerInit(void);//初始化mplayer播放器
    void createPthread(void);//创建线程
    bool flag_cut;//切换标识符
    int onoffSound;//音量开关
    char songName[128];//存放歌曲名
    char lyricName[128];//存放正在播放的歌词名
    map<int,string> mapLyricPlay;//map容器用于解析歌词
    int nowTime;//播放时间
    int allTime;//总时间
    int lyricCount;//歌词计数
    int mapCount;//map容器的计数
    int playType;//播放类型
    void pthreadCancel(void);
    lyric *ly;


private:
    Ui::Widget *ui;
    int fifo_fd;//定义有名管道文件描述符
    vector<QString> song;//定义vector容器用于存放歌曲名
    vector<QString> songlyric;//定义vector容器存放歌词名
    int currentIndex;//用于播放歌曲计数
    pthread_t tidGetTime;
    pthread_t tidRecvPipe;
    pthread_t tidPlayLyric;
    int fd[2];//无名管道两个端口

public slots:
    void nextSong(void);//下一曲
    void cutButton(void);//切歌
    void setSound(void);//设置声音
    void beforeSong(void);//上一曲
    void lyricOpen(void);//打开歌词
    void closeLyric(void);//关闭歌词
    void singlePlay(void);//单曲循环1
    void listPlay(void);//列表播放2
    void setSlideValue(void);//拖拽进度条
signals:
    void sendTimePos(char *time1,char *time2);
    void sendSlider(char *time);
private slots:
    void on_horizontalSlider_valueChanged(int value);
    void SliderJDT(char *time);
    void setLabelTime(char *time1,char *time2);
    void on_listPlay_clicked(const QModelIndex &index);
    void on_comboBoxStyle_currentIndexChanged(int index);
    void on_listPlay_itemClicked(QListWidgetItem *item);
};

#endif // WIDGET_H
