#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMediaPlayer>
#include <QTime>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSystem();

    mediaPlayer = new QMediaPlayer;
    mediaPlayer->setVideoOutput(ui->normal_widget);

    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::onDurationChanged);
    playList = new QMediaPlaylist();
    mediaPlayer->setPlaylist(playList);
    initWdigets();
    connect2Player();


    initializeVideo("C:\\QTcode\\Player_1\\Player_1\\111.mp4");
    normalPlay();
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::playClicked(){
    if(!loadedVideo){
        qDebug()<<"尚未加载视频";
        return;
    }
    // 处理点击了播放-暂停按钮的处理
    qDebug()<<"'current satate:"<<m_playerState;
    switch (m_playerState) {
    case QMediaPlayer::StoppedState:
    case QMediaPlayer::PausedState:
        play();
        break;
    case QMediaPlayer::PlayingState:
        pause();
        break;
    }
    qDebug()<<"'after satate:"<<m_playerState;
}
void MainWindow::connect2Player(){
    connect(ui->play_button,SIGNAL(clicked()),this,SLOT(playClicked()));
    connect(ui->pause_botton,SIGNAL(clicked()),this,SLOT(playClicked()));
    connect(mediaPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(positionChange(qint64)));
    connect(ui->video_slider,SIGNAL(sig_valueChanged_v(qint64)),this,SLOT(seek(qint64)));
    connect(ui->volume_slider,SIGNAL(valueChanged(int)),SLOT(changeVolume(int)));
    connect(ui->volume_button,SIGNAL(clicked()),this,SLOT(changeMute()));
}
void MainWindow::positionChange(qint64 progress) // * progress 是当前的毫秒数
{
    // qDebug()<<"MainWindow::positionChange:  progress"<<progress;
    // qDebug()<<"MainWindow::positionChange:  total duration"<<mediaPlayer->duration();
    // 计算当前进度
    // 计算当前的秒数
    // int curr = int(double(progress)/double(currVideoSeekFrame->formatContext->duration/1000)*100) ;
    // // qDebug()<<"curr"<<curr;
    if (!ui->video_slider->isSliderDown())
        qDebug()<<"max:"<<ui->video_slider->maximum();
        ui->video_slider->setValue(progress);

    currentPosition = progress;
      //progress/1000 = 秒数
}

void MainWindow::initVideoInfo(QString fileName){
    // 记录当前播放的路径
    currentVideoPath = fileName;
    // durationMs = (qint64)(currVideoSeekFrame->formatContext->duration/1000);
    // durationS = (qint64)(currVideoSeekFrame->formatContext->duration/1000000);
}
void MainWindow::onDurationChanged(qint64 duration) {
    qDebug() << "####Total Duration:" << duration  << "milliseconds"; // Duration is in milliseconds
    durationMs = (qint64)(duration);
    durationS = (qint64)(duration/1000);
}
void MainWindow::seek(qint64 time){
    if(loadedVideo){
        /*正放的时候跳转到某个位置*/
        mediaPlayer->setPosition(time);
    }
}
void MainWindow::changeVolume(int volume){
    mediaPlayer->setVolume(volume);
}

void MainWindow::changeMute(){
    mediaPlayer->setMuted(m_playerMuted);
    m_playerMuted = !m_playerMuted;
}

void MainWindow::initializeVideo(QString fileName){
    initVideoInfo(fileName);
}

void MainWindow::showNormalWidget(){
    ui->normal_widget->setVisible(true);

}
void MainWindow::showReverseWidget(){
    ui->normal_widget->setVisible(true);

}
void MainWindow::normalPlay(){
    mediaPlayer->setMedia(QMediaContent(QUrl::fromLocalFile(currentVideoPath)));

    showNormalWidget();
    play();
    // 设置播放进度条最大值(秒数)
    qDebug()<<"MainWindow::normalPlay  "<<mediaPlayer->duration();
    qDebug()<<"MainWindow::normalPlay s "<<durationS;
    qDebug()<<"MainWindow::normalPlay ms "<<durationMs;

    ui->video_slider->setMaximum((int)durationMs);

    // 设置标记位
    if(!loadedVideo){
        loadedVideo = true;
    }
}
void MainWindow::initSystem(){
    loadedVideo = false; // 标记目前还没有加载视频
}

void MainWindow::initWdigets(){
    // 初始化播放按钮
    ui->pause_botton->setVisible(false); // 暂停按钮初始为不可见
}

void MainWindow::pause(){
    m_playerState = QMediaPlayer::StoppedState;
    ui->play_button->setVisible(true);
    ui->pause_botton->setVisible(false);
    mediaPlayer->pause();
}
void MainWindow::play(){
    m_playerState = QMediaPlayer::PlayingState;
    ui->play_button->setVisible(false);
    ui->pause_botton->setVisible(true);
    qDebug()<<"开始播放";
    mediaPlayer->play();
}
void MainWindow::reverseShowRatio(qint64 pts){
    /*用于更新进度条*/
    ui->video_slider->setValue(int(pts));
}

void MainWindow::changePlayOrder(){
    if(isRepeat){
        isRepeat=false;
    }
    else{
        isRepeat = true;
    }
}
