#include "widget.h"
#include "ui_widget.h"
#include "lyric.h"
#include "ui_lyric.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <QString>
#include <stdlib.h>
#include <stdlib.h>
#include <QLabel>
#include <QSlider>
#include <QPixmap>
#include <QPalette>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QListWidgetItem>
#include <QDebug>
#include <fstream>
#include <map>
#include <time.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags (Qt::FramelessWindowHint);
    lyricCount = 0;

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);

    flag_cut = true;
    onoffSound = 1;

    ly = new lyric();

    ui->pushButtonPlay->setStyleSheet("border-image: url(:/pause.png);");
    ui->pushButtonSound->setStyleSheet("border-image: url(:/sound.png);");
    resize(1024,600);
    ui->labelBack1->setStyleSheet("QLabel{background:#003366;}");
    ui->labelBack2->setStyleSheet("QLabel{background:#CC3333;}");

    ui->listPlay->setStyleSheet("background-color:transparent");

    ui->labelSongName->setText(QString("See you again"));

    pipe(fd);//无名管道

    startMplayer();
    mplayerInit();
    createPthread();

    connect(ui->pushButtonNext,SIGNAL(clicked()),this,SLOT(nextSong()));//下一首
    connect(ui->pushButtonPlay,SIGNAL(clicked()),this,SLOT(cutButton()));//播放暂停
    connect(ui->pushButtonSound,SIGNAL(clicked()),this,SLOT(setSound()));//静音
    connect(ui->pushButtonBefore,SIGNAL(clicked()),this,SLOT(beforeSong()));//上一首
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));//声音大小
    connect(this,SIGNAL(sendTimePos(char*,char*)),this,SLOT(setLabelTime(char*,char*)));//传递时间
    connect(this,SIGNAL(sendSlider(char*)),this,SLOT(SliderJDT(char*)));//播放进度条
    connect(ui->pushButtonLRC,SIGNAL(clicked()),this,SLOT(lyricOpen()));//歌词界面
    connect(ui->pushButtonSingle,SIGNAL(clicked()),this,SLOT(singlePlay()));
    connect(ui->pushButtonList,SIGNAL(clicked()),this,SLOT(listPlay()));
    connect(ui->SliderJDT,SIGNAL(sliderReleased()),this,SLOT(setSlideValue()));
}

Widget::~Widget()
{
    delete ui;
    delete ly;
}

void Widget::startMplayer()//开启Mplayer
{
    pid_t pid = fork();
    if(pid == 0)
    {
        dup2(fd[1],1);
        execlp("mplayer","mplayer","-ac","mad","-slave",\
               "-quiet","-idle","-input","file=./fifo_cmd",\
               "./song/03.mp3",NULL);
    }
}

void Widget::mplayerInit()//初始化mplayer
{
    this->currentIndex = 0;

    mkfifo("fifo_cmd",0666);
    this->fifo_fd = open("fifo_cmd",O_WRONLY);

    DIR *dir=NULL;
        dir = opendir("./song");
        if(dir == NULL)
        {
            perror("opendir");
            return;
        }

        while(1)
        {
            struct dirent *ret=NULL;
            ret = readdir(dir);
            if(ret == NULL)
                break;
            if(ret->d_type == DT_REG)
            {
                if(strstr(ret->d_name,".mp3") != NULL)//查找到歌曲文件
                {
                    this->song.push_back(QString(ret->d_name));
                    //ui->listPlay->addItem(QString(ret->d_name));
                    if(strstr(ret->d_name,"03") != NULL)
                    {
                        ui->listPlay->addItem(QString("See you again"));
                    }
                    else if(strstr(ret->d_name,"08") != NULL)
                    {
                        ui->listPlay->addItem(QString("涅槃"));
                    }
                    else if(strstr(ret->d_name,"10")!= NULL)
                    {
                        ui->listPlay->addItem(QString("真的爱你"));
                    }
                    else if(strstr(ret->d_name,"01")!= NULL)
                    {
                        ui->listPlay->addItem(QString("打上花火"));
                    }
                    else if(strstr(ret->d_name,"02")!= NULL)
                    {
                        ui->listPlay->addItem(QString("Shape Of You"));
                    }
                    else if(strstr(ret->d_name,"04")!= NULL)
                    {
                        ui->listPlay->addItem(QString("富士山下"));
                    }
                    else if(strstr(ret->d_name,"05")!= NULL)
                    {
                        ui->listPlay->addItem(QString("盛夏的果实"));
                    }
                    else if(strstr(ret->d_name,"06")!= NULL)
                    {
                        ui->listPlay->addItem(QString("安河桥"));
                    }
                    else if(strstr(ret->d_name,"07")!= NULL)
                    {
                        ui->listPlay->addItem(QString("夜空中最亮的星"));
                    }
                    else if(strstr(ret->d_name,"09")!= NULL)
                    {
                        ui->listPlay->addItem(QString("沙漠骆驼"));
                    }
                }
            }
        }
        vector<QString>::iterator it = song.begin();
        for(;it!=song.end();it++)
        {
            cout<<(*it).toUtf8().data()<<endl;
        }
        closedir(dir);
}

void *sendCmdFunc(void *arg)//发送获取时间指令
{
    Widget *p = (Widget *)arg;
    while(1)
    {
        write(p->fifo_fd,"get_time_length\n",strlen("get_time_length\n"));//获取总时间
        usleep(200*1000);
        write(p->fifo_fd,"get_time_pos\n",strlen("get_time_pos\n"));//获取实时文件
        usleep(200*1000);
        write(p->fifo_fd,"get_percent_pos\n",strlen("get_percent_pos\n"));//获取播放百分比
        usleep(200*1000);
        write(p->fifo_fd,"get_file_name\n",strlen("get_file_name\n"));//获取文件名
        usleep(200*1000);
    }
}
void *recvPipeMsg(void *arg)//获取时间
{
    Widget *p = (Widget *)arg;
    char time2[128] = "";
    while(1)
    {

        char msg[256] = "";
        read(p->fd[0],msg,sizeof(msg));
        if(strstr(msg,"ANS_LENGTH") != NULL)
        {
            sscanf(msg,"ANS_LENGTH = %s",time2);
        }
        else if(strstr(msg,"ANS_TIME_POSITION") != NULL)
        {
            char time1[128] = "";
            sscanf(msg,"ANS_TIME_POSITION = %s",time1);
            if(strstr(msg,"ANS_LENGTH") != NULL)
            {
                sscanf(msg,"ANS_LENGTH = %s",time2);
            }
            emit p->sendTimePos(time1,time2);
        }
        else if(strstr(msg,"ANS_PERCENT_POSITION") != NULL)
        {
            char time[128] = "";
            sscanf(msg,"ANS_PERCENT_POSITION = %s",time);
            emit p->sendSlider(time);
        }
        else if(strstr(msg,"ANS_FILENAME=") != NULL)
        {
            char title[128] = "";
            sscanf(msg,"ANS_FILENAME = '%s'",title);
            title[strlen(title)-1] = ' ';
            strcpy(p->songName,title);
            p->songName[2] = '\0';
        }
        else
            printf("%s\n",msg);
    }
}

void *playingLyric(void *arg)//歌词解析
{
    Widget *p = (Widget *)arg;
    int i = 0;
    p->mapCount = 0;
    printf("线程3\n");
    sprintf(p->lyricName,"song/%s.lrc",p->songName);
    ifstream File;
    File.open(p->lyricName);
    string str;
    if(File)
    {
        while(getline(File,str)!=NULL)
        {
            char c[str.length()];
            strcpy(c,str.data());
            char type[256]="";
            char msg[256]="";
            sscanf(c,"[%[^:]:%[^]]",type,msg);
            if(i<5)
            {
                QTextCodec *codec = QTextCodec::codecForName("UTF-8");
                QTextCodec::setCodecForTr(codec);
                QTextCodec::setCodecForLocale(codec);
                QTextCodec::setCodecForCStrings(codec);
                if(strcmp(type, "ti") == 0)
                {
                    p->ly->ui->labelLyricName->setText(QString(msg));
                }
                else if(strcmp(type, "ar") == 0)
                {
                    p->ly->ui->labelSong01->setText(QString(msg));
                }
                else if(strcmp(type, "al") == 0)
                {
                    p->ly->ui->labelSong02->setText(QString(msg));
                }
            }
            else
            {
                char *song_lrc = c;
                if(*song_lrc == '[')
                    song_lrc += 10;

                //逐个时间分析
                char *time_lrc = c;
                if(*time_lrc == '[')
                {
                    int m = 0,s=0,ss=0;
                    sscanf(time_lrc,"[%d:%d:%d", &m,&s,&ss);
                    int time = m*60+s+ss/100;
                    char lrc[256] = "";
                    strcpy(lrc, song_lrc);
                    p->mapLyricPlay.insert(pair<int,string>(time,lrc));
                    p->mapCount++;
                }
            }
            i++;
        }
        printf("count==%d\n",p->mapCount);
    }
    else
        printf("打开失败\n");
}

void Widget::createPthread()
{
    pthread_create(&tidGetTime,NULL,sendCmdFunc,this);//线程1发送时间
    pthread_create(&tidRecvPipe,NULL,recvPipeMsg,this);//线程2接收时间
}

void Widget::lyricOpen()//专辑名匹配歌曲
{
    ly->show();
    connect(ly->ui->pushButtonClose,SIGNAL(clicked()),this,SLOT(closeLyric()));
    char pic[128] = "";
    sprintf(pic,"background-image:url(:/song%s.png)",songName);
    ly->ui->labelPicture->setStyleSheet(pic);
    ly->ui->labelLyricName->setText(songName);
    ly->ui->labelLyric05->setStyleSheet("color:black;");
    ly->ui->labelLyric04->setStyleSheet("color:black;");
    pthread_create(&tidPlayLyric,NULL,playingLyric,this);//线程3歌词解析
    pthread_detach(tidPlayLyric);
}

void Widget::closeLyric()
{
    ly->hide();
    pthreadCancel();
}

void Widget::singlePlay()
{
    playType = 1;
    ui->labelPlayType->setText("单曲循环");
}

void Widget::listPlay()
{
    playType = 2;
    ui->labelPlayType->setText("列表循环");
}

void Widget::setSlideValue()
{
    int value = ui->SliderJDT->value();
    char cmd[128] = "";
    int len = sprintf(cmd,"seek %d\n",value);
    write(fifo_fd,cmd,len);
}

void Widget::pthreadCancel()
{
    mapLyricPlay.clear();
    ly->ui->labelLyric01->clear();
    ly->ui->labelLyric02->clear();
    ly->ui->labelLyric03->clear();
    ly->ui->labelLyric04->clear();
    ly->ui->labelLyric05->clear();
    pthread_cancel(tidPlayLyric);
    printf("销毁成功\n");
}


void Widget::nextSong()//下一首
{
    this->currentIndex++;
    if(this->currentIndex == (int)song.size())
    {
        currentIndex = 0;
    }
    char cmd[128] = "";
    lyricCount = 0;
    mapLyricPlay.clear();
    ly->ui->labelLyric01->clear();
    ly->ui->labelLyric02->clear();
    ly->ui->labelLyric03->clear();
    ly->ui->labelLyric04->clear();
    ly->ui->labelLyric05->clear();
    ui->labelSongName->setText(ui->listPlay->item(currentIndex)->text().toUtf8().data());
    ui->listPlay->item(currentIndex)->setSelected(true);
    if(flag_cut)
    {
        int len = sprintf(cmd,"loadfile ./song/%s\n",\
                song[currentIndex].toUtf8().data());
        write(fifo_fd,cmd,len);
    }
    else if(flag_cut == false)
    {
        ui->pushButtonPlay->setStyleSheet("border-image: url(:/pause.png);");
        pthread_create(&tidGetTime,NULL,sendCmdFunc,this);
        pthread_detach(tidGetTime);
        int len = sprintf(cmd,"loadfile ./song/%s\n",\
                song[currentIndex].toUtf8().data());
        write(fifo_fd,cmd,len);
        flag_cut = true;
    }

    if(onoffSound == 0)
    {
        ui->pushButtonSound->setStyleSheet("border-image: url(:/sound.png);");
        char cmd[128] = "mute 1\n";
        usleep(100*1000);
        write(fifo_fd,cmd,strlen(cmd));
    }
}

void Widget::setLabelTime(char *time1,char *time2)//实时显示播放时间和总时间
{
    int tmp_time1 = atoi(time1);
    int tmp_time2 = atoi(time2);
    nowTime = tmp_time1;
    allTime = tmp_time2;

    map<int,string>::iterator it1;
    map<int,string>::iterator it2;
    map<int,string>::iterator itend = mapLyricPlay.end();


    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);

    //it1 = mapLyricPlay.find(tmp_time1);
    for( it1 =mapLyricPlay.begin();it1 != mapLyricPlay.end(); it1++)
    {
       if((*it1).first == tmp_time1)
       {
           string astr = (*it1).second;
           char cstr[astr.length()];
           strcpy(cstr,astr.data());
           ly->ui->labelLyric03->setText(QString (cstr));
           ly->ui->labelLyric03->setStyleSheet("color:red;");

           it2= mapLyricPlay.equal_range(tmp_time1).second;
           string astr1 = (*it2).second;
           char cstr1[astr1.length()];
           strcpy(cstr1,astr1.data());
           ly->ui->labelLyric04->setText(QString (cstr1));

           string astr2 = (*(--it1)).second;
           char cstr2[astr2.length()];
           strcpy(cstr2,astr2.data());
           ly->ui->labelLyric02->setText(QString (cstr2));
           printf("当前时间=%d 总时间=%d\n",tmp_time1,(*(--itend)).first);

           break;
       }
    }

    if(tmp_time1 == ((*(itend)).first)||tmp_time1 == ((*(itend)).first-2)||tmp_time1 == ((*(itend)).first-1))
    {
        printf("调用了\n");
        closeLyric();
    }
    char str_time[128] = "";
    sprintf(str_time,"%02d:%02d/%02d:%02d",tmp_time1/60,tmp_time1%60,tmp_time2/60,tmp_time2%60);
    ui->timeLabel->setText(QString(str_time));

    if(tmp_time1 == (tmp_time2-1) && playType == 1)
    {
        printf("单曲循环\n");
        char cmd[128] = "";
        int len = sprintf(cmd,"loadfile ./song/%s\n",\
                song[currentIndex].toUtf8().data());

        write(fifo_fd,cmd,len);
        if(onoffSound == 0)
        {
            ui->pushButtonSound->setStyleSheet("border-image: url(:/offsound.png);");
            char cmd[128] = "mute 1\n";
            usleep(100*1000);
            write(fifo_fd,cmd,strlen(cmd));
        }

    }
    else if(tmp_time1 == (tmp_time2-1) && playType == 2)
    {
        printf("列表循环\n");
        char cmd[128] = "";
        currentIndex++;
        lyricCount = 0;
        mapLyricPlay.clear();
        ly->ui->labelLyric01->clear();
        ly->ui->labelLyric02->clear();
        ly->ui->labelLyric03->clear();
        ly->ui->labelLyric04->clear();
        ly->ui->labelLyric05->clear();
        int len = sprintf(cmd,"loadfile ./song/%s\n",\
                song[currentIndex].toUtf8().data());

        write(fifo_fd,cmd,len);
        ui->labelSongName->setText(ui->listPlay->item(currentIndex)->text().toUtf8().data());
    }
    if(tmp_time1 == tmp_time2 && playType == 3)
    {
        srand(time(NULL));
        currentIndex = rand() % 11;
        char cmd[128] = "";
        lyricCount = 0;
        mapLyricPlay.clear();
        ly->ui->labelLyric01->clear();
        ly->ui->labelLyric02->clear();
        ly->ui->labelLyric03->clear();
        ly->ui->labelLyric04->clear();
        ly->ui->labelLyric05->clear();
        int len = sprintf(cmd,"loadfile ./song/%s\n",\
                song[currentIndex].toUtf8().data());

        write(fifo_fd,cmd,len);
    }
}

void Widget::cutButton()//播放暂停
{
    if (flag_cut)
    {
        ui->pushButtonPlay->setStyleSheet("border-image: url(:/play.png);");
        flag_cut = false;
        write(fifo_fd,"pause\n",strlen("pause\n"));
        pthread_cancel(tidGetTime);
    }
    else
    {   
        ui->pushButtonPlay->setStyleSheet("border-image: url(:/pause.png);");
        flag_cut = true;
        write(fifo_fd,"pause\n",strlen("pause\n"));
        pthread_create(&tidGetTime,NULL,sendCmdFunc,this);
        pthread_detach(tidGetTime);
    }
}

void Widget::setSound()//设置音量
{
    if (onoffSound)
    {
        ui->pushButtonSound->setStyleSheet("border-image: url(:/offsound.png);");
        char cmd[128] = "mute 1\n";
        write(fifo_fd,cmd,strlen(cmd));
        onoffSound = 0;
    }
    else
    {
        ui->pushButtonSound->setStyleSheet("border-image: url(:/sound.png);");
        char cmd[128] = "mute 0\n";
        write(fifo_fd,cmd,strlen(cmd));
        onoffSound = 1;
    }
}

void Widget::beforeSong()//上一首
{
    if(this->currentIndex == 0)
    {
        currentIndex = song.size();
        currentIndex--;
    }
    else
    {
        this->currentIndex--;
    }
    char cmd[128] = "";
    mapLyricPlay.clear();
    lyricCount = 0;
    ly->ui->labelLyric01->clear();
    ly->ui->labelLyric02->clear();
    ly->ui->labelLyric03->clear();
    ly->ui->labelLyric04->clear();
    ly->ui->labelLyric05->clear();
    ui->labelSongName->setText(ui->listPlay->item(currentIndex)->text().toUtf8().data());
    ui->listPlay->item(currentIndex)->setSelected(true);
    int len = sprintf(cmd,"loadfile ./song/%s\n",\
            song[currentIndex].toUtf8().data());
    char pic[128] = "";
    sprintf(pic,":/song%d",currentIndex);

    write(fifo_fd,cmd,len);

    if(flag_cut)
    {
        int len = sprintf(cmd,"loadfile ./song/%s\n",\
                song[currentIndex].toUtf8().data());
        write(fifo_fd,cmd,len);
    }
    else if(flag_cut == false)
    {
        ui->pushButtonPlay->setStyleSheet("border-image: url(:/pause.png);");
        pthread_create(&tidGetTime,NULL,sendCmdFunc,this);
        pthread_detach(tidGetTime);
        int len = sprintf(cmd,"loadfile ./song/%s\n",\
                song[currentIndex].toUtf8().data());
        write(fifo_fd,cmd,len);
        flag_cut = true;
    }

    if(onoffSound == 0)
    {
        ui->pushButtonSound->setStyleSheet("border-image: url(:/sound.png);");
        char cmd[128] = "mute 1\n";
        usleep(100*1000);
        write(fifo_fd,cmd,strlen(cmd));
    }
}

void Widget::SliderJDT(char *time)//进度条槽函数
{
    int sliderTime = atoi(time);
    ui->SliderJDT->setValue(sliderTime);
}

void Widget::on_horizontalSlider_valueChanged(int value)//音量
{
    char cmd1[128] = "";
    int len = sprintf(cmd1,"volume %d 1",value);
    write(fifo_fd,cmd1,len);
    ui->pushButtonSound->setStyleSheet("border-image: url(:/sound.png);");
    char cmd2[128] = "mute 0\n";
    write(fifo_fd,cmd2,strlen(cmd2));
    onoffSound = 1;
}

void Widget::on_listPlay_clicked(const QModelIndex &index)//点击播放
{
    char cmd[128] = "";
    lyricCount = 0;
    mapLyricPlay.clear();
    ly->ui->labelLyric01->clear();
    ly->ui->labelLyric02->clear();
    ly->ui->labelLyric03->clear();
    ly->ui->labelLyric04->clear();
    ly->ui->labelLyric05->clear();
    int len = sprintf(cmd,"loadfile ./song/%s\n",\
            song[index.row()].toUtf8().data());
    currentIndex = index.row();

    write(fifo_fd,cmd,len);

    if(onoffSound == 0)
    {
        ui->pushButtonSound->setStyleSheet("border-image: url(:/sound.png);");
        char cmd[128] = "mute 1\n";
        usleep(100*1000);
        write(fifo_fd,cmd,strlen(cmd));
    }

    if(flag_cut)
    {
        int len = sprintf(cmd,"loadfile ./song/%s\n",\
                song[currentIndex].toUtf8().data());
        write(fifo_fd,cmd,len);
    }
    else if(flag_cut == false)
    {
        ui->pushButtonPlay->setStyleSheet("border-image: url(:/pause.png);");
        pthread_create(&tidGetTime,NULL,sendCmdFunc,this);
        pthread_detach(tidGetTime);
        int len = sprintf(cmd,"loadfile ./song/%s\n",\
                song[currentIndex].toUtf8().data());
        write(fifo_fd,cmd,len);
        flag_cut = true;
    }
}

void Widget::on_comboBoxStyle_currentIndexChanged(int index)//更换主题
{
    if(index == 0)
    {
        ui->labelBack1->setStyleSheet("QLabel{background:#003366;}");
        ui->labelBack2->setStyleSheet("QLabel{background:#CC3333;}");
    }
    else if(index == 1)
    {
        ui->labelBack1->setStyleSheet("QLabel{background:#6699CC;}");
        ui->labelBack2->setStyleSheet("QLabel{background:#333333;}");
    }
    else if(index == 2)
    {
        ui->labelBack1->setStyleSheet("QLabel{background:#CC9933;}");
        ui->labelBack2->setStyleSheet("QLabel{background:#FFCC33;}");
    }
    else if(index == 3)
    {
        ui->labelBack1->setStyleSheet("QLabel{background:#CCCCCC;}");
        ui->labelBack2->setStyleSheet("QLabel{background:#CC3399;}");
    }
    else if(index == 4)
    {
        ui->labelBack1->setStyleSheet("QLabel{background:#FF99CC;}");
        ui->labelBack2->setStyleSheet("QLabel{background:#CCFF00;}");
    }
}

void Widget::on_listPlay_itemClicked(QListWidgetItem *item)
{
    ui->labelSongName->setText(item->text().toUtf8().data());
}
