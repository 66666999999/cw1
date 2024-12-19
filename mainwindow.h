#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPropertyAnimation>
#include <QVideoWidget>
#include "seekFrame.h"
#include <QLabel>
#include <QMediaPlayer>
#include <QListWidgetItem>
#include <QContextMenuEvent>
#include <QMenu>
#include <QAction>
#include <QCursor>
#include <QProcess>
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Enumeration for different window resize regions.
 */
enum ResizeRegion {
    Default,      // No resize
    North,        // Top border
    NorthEast,    // Top-right corner
    East,         // Right border
    SouthEast,    // Bottom-right corner
    South,        // Bottom border
    SouthWest,    // Bottom-left corner
    West,         // Left border
    NorthWest     // Top-left corner
};

// Playback rate configuration
#define PLAYBACK_RATE_MIN           0.25     // Minimum playback speed
#define PLAYBACK_RATE_MAX           3.0      // Maximum playback speed
#define PLAYBACK_RATE_SCALE         0.25     // Playback speed step

/**
 * @brief The MainWindow class provides a multimedia player with various functionalities.
 * 
 * It includes video playback, controls, playlist management, playback rate adjustments,
 * and support for custom window resizing.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

signals:
    void sig_reversePlay(QString);       // Signal for reverse playback
    void sig_reverseProgress(qint64);    // Signal for reverse playback progress

/* Initialization Methods */
public:
    /**
     * @brief Initialize the video playback with a given file.
     * @param fileName Path to the video file.
     */
    void initializeVideo(QString);

    /**
     * @brief Play the video in normal (forward) mode.
     */
    void normalPlay();

    /**
     * @brief Initialize system components like thumbnails, waveforms, etc.
     */
    void initSystem();

    /**
     * @brief Initialize video information like duration, resolution, etc.
     * @param fileName Path to the video file.
     */
    void initVideoInfo(QString);

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

/* Video Information Members */
public:
    int durationS;             // Video duration in seconds
    qint64 duration;           // Video duration in microseconds
    qint64 durationMs;         // Video duration in milliseconds
    qint64 reverseDurationSecond; // Reverse playback duration in seconds
    QString currentVideoPath;  // Path to the currently playing video
    volatile qint64 lastSecond = 1e10;  // Timestamp for the last frame
    qint64 currentPosition = 0; // Current playback position in milliseconds

    int volume() const;        // Get current volume level

/* Playback Functionality Members */
public:
    SeekFrame* currVideoSeekFrame;  // SeekFrame for thumbnails or reverse play
    QMediaPlayer *mediaPlayer;      // QMediaPlayer for video playback
    QMediaPlaylist *playList;       // Playlist for video management

/* State Flags */
public:
    bool m_playerMuted = true;        // Mute flag
    bool loadedVideo;                 // Flag indicating if video is loaded
    int currMediaType;                // Type of current media (audio/video)
    bool isRepeat = false;            // Flag for repeat mode
    QMediaPlayer::State m_playerState = QMediaPlayer::StoppedState; // Current playback state

    float pf_playback_rate;           // Current playback rate
    int pf_playback_rate_changed;     // Flag indicating playback rate change

/* Frameless Window Members */
public:
    void handleResize();              // Handle window resizing
    void handleMove(QPoint pt);       // Handle window movement
    ResizeRegion getResizeRegion(QPoint clientPos); // Get the resize region
    void setResizeCursor(ResizeRegion region);      // Set cursor style based on region
    void mouseReleaseEvent(QMouseEvent *event) override; // Handle mouse release
    void mouseMoveEvent(QMouseEvent *event) override;    // Handle mouse move
    void mousePressEvent(QMouseEvent *event) override;   // Handle mouse press

/* Slots */
public slots:
    /* Miscellaneous */
    void connect2Player();          // Connect all necessary signals and slots
    void highlightInFileList();     // Highlight a video in the playlist
    void showNormalWidget();        // Show forward playback UI
    void showReverseWidget();       // Show reverse playback UI
    void changePlayOrder();         // Toggle between repeat and sequential play

    /* Seek Functionality */
    void initSeekFrame(QString); // Initialize SeekFrame for seeking
    void deleteSeekFrame();               // Delete the current SeekFrame object

    /* Seek in Forward Playback */
    void seek(qint64);    // Seek to a specific position in the video

    /* Volume Controls */
    void changeVolume(int); // Change playback volume
    void changeMute();             // Mute or unmute the video

    /* Playback Controls */
    void pause();                  // Pause video playback
    void play();                   // Resume video playback
    void playClicked();            // Handle play button click

    /* Skip Controls */
    void skipForwardOrBackward(bool); // Skip video forward or backward
    void jump(int);       // Jump to a specific time in the video

    /* Time Display */
    void positionChange(qint64 progress); // Update playback progress
    void reverseShowRatio(qint64);  // Update reverse progress bar

    /* Playlist Management */
    void openFileButtonClicked(); // Open a new file
    void addVideoItem(QString); // Add video to the playlist
    void changeVideo(bool);  // Change to next or previous video
    void onDurationChanged(qint64 duration); // Handle duration change

    /* Playback Speed */
    void on_speedBtn_clicked();   // Handle speed button click

private:
    Ui::MainWindow *ui;
    QPropertyAnimation *mAnimation_ControlWidget; // Animation for bottom control widget

    void showOutControlWidget(); // Show control widget
    void hideControlWidget();    // Hide control widget
    void updateDurationInfo(qint64 currentInfo); // Update duration display

/* Qt Widget Components */
public:
    void initWdigets(); // Initialize UI components like buttons, sliders, etc.

/* Other Components */
public:
    QVector<QString> *playHistory;     // Vector to store playback history
    QVector<QString> *playListLocal;   // Local playlist vector
    void changePlayingRatio(float ratio); // Change playback ratio

private:
    /* Frameless Window Properties */
    bool m_drag, m_move;                // Flags for dragging and moving
    QPoint dragPos, resizeDownPos;      // Positions for window dragging
    const int resizeBorderWidth = 10;   // Width of resize border
    ResizeRegion resizeRegion;          // Current resize region
    QRect mouseDownRect;                // Rectangle for mouse down position

private slots:
    void on_comboBox_activated(const QString &arg1); // ComboBox activation handler
    void changeEvent(QEvent *e);                    // Handle change events
    void on_comboBox_2_activated(int index);        // ComboBox2 activation handler

private:
    QTranslator tran; // Translator for multi-language support
};

#endif // MAINWINDOW_H
