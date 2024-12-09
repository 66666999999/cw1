#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPropertyAnimation>
#include <QVideoWidget>

#include <QLabel>
#include <QMediaPlayer>
#include <QListWidgetItem>
#include <QContextMenuEvent>
#include <QMenu>
#include <QAction>
#include <QCursor>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



/*初始化相关*/
public:
    // 初始化视频
    void initializeVideo(QString);
    // 正放视频
    void normalPlay();
    // 用于初始化一些类 (缩略图, 波形图..)
    void initSystem();
    // 使用QT初始化视频
    void initVideoInfo(QString);

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

/*视频信息相关成员*/
public:
    // 视频长度
    int durationS; //(秒)
    qint64 duration; //(微秒)
    qint64 durationMs; //(毫秒)
    // 倒放组件读出来的视频的秒数
    qint64 reverseDurationSecond;
    // 当前正在播放的视频的地址
    QString currentVideoPath;
    volatile qint64 lastSecond = 1e10;
    qint64 currentPosition=0; // 记录当前的播放位置



    int volume() const;

/*播放功能组件相关*/
public:


    QMediaPlayer * mediaPlayer; // 播放器
    QMediaPlaylist *playList; // 播放列表


/*标志位*/
public:
    // 标志是否静音
    bool m_playerMuted = true;
    // 标志是否已经加载了视频
    bool loadedVideo;

    // 当前视频的类型
    int currMediaType;
    // 当前的播放状态
    bool isRepeat=false;
    QMediaPlayer::State m_playerState = QMediaPlayer::StoppedState;


public slots:

    /*其它*/
    void connect2Player();  // 用于进行所有的链接

    void showNormalWidget();
    void showReverseWidget();
    void changePlayOrder(); // 播放顺序

    /*正放跳转相关*/
    void seek(qint64);   // 正放的时候, seek到某个位置

    /*音量相关*/
    void changeVolume(int);  //改变音量
    void changeMute();  // 静音

    /*暂停和继续播放*/
    void pause(); // 暂停
    void play();  // 继续播放
    void playClicked();  // 播放按钮的点击事件

    /*时间显示相关*/
    void positionChange(qint64 progress);
    void reverseShowRatio(qint64); //设置进度条比例
    void onDurationChanged(qint64 duration);

private:
    Ui::MainWindow *ui;



/*Qt Widget相关*/
public:
    // 初始化组件
    void initWdigets();

/*其它内容*/
public:

    QVector<QString> *playListLocal;
    void changePlayingRatio(float);

};
#endif // MAINWINDOW_H
