#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "seekFrame.h"
#include "utils.h"
#include <QDebug>
#include <QMediaPlayer>
#include <QTime>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QShortcut>

// Constructor for the MainWindow class
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  // Set up UI components from the UI file

    setMouseTracking(true);  // Enable mouse tracking for the window
    this->setWindowFlags(Qt::FramelessWindowHint);  // Remove the window's default frame

    initSystem();  // Custom system initialization function
    ui->normal_widget->setStyleSheet("background-color:black;");  // Set the background color of the video widget

    // Create a QMediaPlayer object to handle video playback
    mediaPlayer = new QMediaPlayer;
    mediaPlayer->setVideoOutput(ui->normal_widget);  // Set the video output to a specific widget

    // Connect signals and slots for media player
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::onDurationChanged);

    // Initialize playlist for managing multiple media files
    playList = new QMediaPlaylist();
    mediaPlayer->setPlaylist(playList);  // Associate playlist with the media player

    initWdigets();  // Custom widget initialization
    connect2Player();  // Connect custom signals and slots to the media player

    // Apply a custom stylesheet to QComboBox
    ui->comboBox->setStyleSheet("QComboBox {"
                                "background-color: rgb(57, 60, 62);"  // Background color for the combo box
                                "border: 1px solid gray;"  // Add a 1-pixel gray border
                                "border-radius: 3px;"  // Rounded corners with a 3px radius
                                "padding: 1px 18px 1px 3px;"  // Padding for internal spacing
                                "min-width: 6em;"  // Minimum width of the combo box
                                "color: white;"  // White text color
                                "}"
                                "QComboBox::drop-down {"
                                "subcontrol-origin: padding;"
                                "subcontrol-position: top right;"
                                "width: 15px;"  // Width of the dropdown arrow
                                "border-left-width: 1px;"
                                "border-left-color: gray;"
                                "border-left-style: solid;"
                                "}"
                                "QComboBox::down-arrow {"
                                "image: url(:/images/down_arrow.png);"  // Use a custom arrow image
                                "}");

    // Populate comboBox_2 with playback speed options (0.25x to 3x with 0.25 step)
    double startSpeed = 0.25;
    double endSpeed = 3;
    double step = 0.25;

    for (double speed = startSpeed; speed <= endSpeed; speed += step) {
        QString speedText = tr("倍速:") + QString::number(speed);  // Generate text "倍速:x"
        ui->comboBox_2->addItem(speedText);  // Add the speed text to comboBox_2
    }
    ui->comboBox_2->setCurrentIndex(3);  // Set default selected index to 1.0x speed

    // Apply a transparent and minimalistic stylesheet to comboBox_2
    ui->comboBox_2->setStyleSheet("QComboBox {"
                                  "combo-box-popup:drop-up;"  // Dropdown menu opens upward
                                  "background-color: transparent;"  // Transparent background
                                  "border: none;"  // Remove the border
                                  "padding: 1px 18px 1px 3px;"  // Padding inside the combo box
                                  "min-width: 6em;"  // Minimum width
                                  "color: white;"  // White text color
                                  "}"
                                  "QComboBox::drop-down {"
                                  "subcontrol-origin: padding;"
                                  "subcontrol-position: top right;"
                                  "width: 15px;"  // Dropdown arrow width
                                  "border-left-width: 0px;"  // Remove left border
                                  "border-left-color: transparent;"
                                  "border-left-style: solid;"
                                  "}"
                                  "QComboBox::down-arrow {"
                                  "width: 10px;"  // Arrow width
                                  "height: 10px;"  // Arrow height
                                  "image: none;"  // No custom arrow image
                                  "}"
                                  "QComboBox:hover {"
                                  "color: Cyan;"  // Change text color to cyan on hover
                                  "}"
                                  "QComboBox:pressed {"
                                  "color: CadetBlue;"  // Change text color to cadet blue when pressed
                                  "}"
                                  "QComboBox:focus {"
                                  "outline: none;"  // Remove focus outline
                                  "}"
                                  "QComboBox QAbstractItemView {"
                                  "background-color: transparent;"  // Transparent dropdown background
                                  "border: 1px solid gray;"  // Border for the dropdown list
                                  "selection-background-color: rgba(100, 149, 237, 0.3);"  // Semi-transparent blue for selection
                                  "selection-color: white;"  // White text color for selected item
                                  "}");
}


// Destructor for MainWindow
MainWindow::~MainWindow()
{
    delete ui;  // Clean up the user interface instance
}

// Function to show the control widget with animation
void MainWindow::showOutControlWidget()
{
    // Set animation duration to 800 milliseconds
    mAnimation_ControlWidget->setDuration(800);

    // Get the current dimensions and position of the control widget
    int w = ui->widget_controller->width();
    int h = ui->widget_controller->height();
    int x = 0;
    int y = ui->centralwidget->height() - ui->widget_controller->height();  // Position at the bottom of the main window

    // Check if the control widget is hidden
    if (ui->widget_controller->isHidden())
    {
        ui->widget_controller->show();  // Show the control widget
        mAnimation_ControlWidget->setStartValue(ui->widget_controller->geometry());  // Set start geometry for animation
    }
    else
    {
        mAnimation_ControlWidget->setStartValue(ui->widget_controller->geometry());
    }

    // Set the target position and size for the animation
    mAnimation_ControlWidget->setEndValue(QRect(x, y, w, h));
    mAnimation_ControlWidget->setEasingCurve(QEasingCurve::Linear);  // Use a linear animation easing curve

    mAnimation_ControlWidget->start();  // Start the animation
}

// Function to hide the control widget with animation
void MainWindow::hideControlWidget()
{
    mAnimation_ControlWidget->setTargetObject(ui->widget_controller);  // Target the control widget for animation

    // Set animation duration to 300 milliseconds
    mAnimation_ControlWidget->setDuration(300);

    // Get the current dimensions and position of the control widget
    int w = ui->widget_controller->width();
    int h = ui->widget_controller->height();
    int x = 0;
    int y = ui->centralwidget->height() + h;  // Move the widget below the visible area

    // Set start and end values for the animation
    mAnimation_ControlWidget->setStartValue(ui->widget_controller->geometry());
    mAnimation_ControlWidget->setEndValue(QRect(x, y, w, h));
    mAnimation_ControlWidget->setEasingCurve(QEasingCurve::Linear);  // Use a linear animation easing curve

    mAnimation_ControlWidget->start();  // Start the animation
}

// Function to handle play/pause button clicks
void MainWindow::playClicked()
{
    if (!loadedVideo)  // Check if a video has been loaded
    {
        qDebug() << "尚未加载视频";  // Debug message: No video loaded
        return;
    }

    // Debug output: Print the current media player state
    qDebug() << "'current state:" << m_playerState;

    // Handle play and pause based on the current player state
    switch (m_playerState)
    {
    case QMediaPlayer::StoppedState:
    case QMediaPlayer::PausedState:
        play();  // Start or resume playback
        break;
    case QMediaPlayer::PlayingState:
        pause();  // Pause playback
        break;
    }

    // Debug output: Print the media player state after the operation
    qDebug() << "'after state:" << m_playerState;
}


// Function to connect UI components and media player signals/slots
void MainWindow::connect2Player() {
    // Connect buttons for close, maximize, and minimize window actions
    connect(ui->close, &QPushButton::clicked, this, [=]() { this->close(); });
    connect(ui->minimize, &QPushButton::clicked, this, [=]() { this->setWindowState(Qt::WindowMinimized); });
    connect(ui->maximize, &QPushButton::clicked, this, [=]() { this->setWindowState(Qt::WindowMaximized); });

    // Toggle the visibility of the side panel (playlist sidebar)
    connect(ui->openFileList, &QPushButton::clicked, this, [=]() {
        bool playListVisable = ui->sideBlock->isVisible();
        if (playListVisable) {
            ui->sideBlock->setVisible(false);  // Hide the side panel
            this->resize(this->width() - ui->sideBlock->width(), this->height());  // Adjust window size
            ui->openFileList->setStyleSheet(
                "image: url(:new/image/off1.png);"
                "border-radius:0px; "
                );
        } else {
            ui->sideBlock->setVisible(true);  // Show the side panel
            this->resize(this->width() + ui->sideBlock->width(), this->height());  // Adjust window size
            ui->openFileList->setStyleSheet(
                "image: url(:new/image/on1.png);"
                "border-radius:0px; "
                );
        }
    });

    // Connect play and pause buttons to the playClicked slot
    connect(ui->play_button, SIGNAL(clicked()), this, SLOT(playClicked()));
    connect(ui->pause_botton, SIGNAL(clicked()), this, SLOT(playClicked()));

    // Connect media player position changes to the corresponding slot
    connect(mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(positionChange(qint64)));

    // Connect slider signals for seeking video and adjusting volume
    connect(ui->video_slider, SIGNAL(sig_valueChanged_v(qint64)), this, SLOT(seek(qint64)));
    connect(ui->volume_slider, SIGNAL(valueChanged(int)), this, SLOT(changeVolume(int)));
    connect(ui->volume_button, SIGNAL(clicked()), this, SLOT(changeMute()));

    // Connect playlist repeat and file addition buttons
    connect(ui->repeat, SIGNAL(clicked()), this, SLOT(changePlayOrder()));
    connect(ui->addFile, SIGNAL(clicked()), this, SLOT(openFileButtonClicked()));

    // Handle double-click events on the playlist to play the selected video
    connect(ui->playList, &QListWidget::itemDoubleClicked, this, [=]() {
        qDebug() << "Double-clicked!";
        // Retrieve the currently double-clicked item
        QListWidgetItem *item = ui->playList->item(ui->playList->currentIndex().row());

        mediaPlayer->pause();
        initializeVideo(item->data(Qt::UserRole).toString());  // Initialize and play the selected video
        normalPlay();  // Start playback
    });

    // Handle single-click events on playlist items to debug current selection
    connect(ui->playList, &QListWidget::itemClicked, this, [=]() {
        qDebug() << "Current clicked index:" << ui->playList->currentIndex().row();
        QListWidgetItem *item = ui->playList->item(ui->playList->currentIndex().row());
        qDebug() << "Current clicked index text:" << item->data(Qt::UserRole).toString();
    });

    // Connect forward and backward buttons to skip video playback
    connect(ui->forward_seconds, &QPushButton::clicked, this, [=]() { skipForwardOrBackward(true); });
    connect(ui->backward_seconds, &QPushButton::clicked, this, [=]() { skipForwardOrBackward(false); });

    // Connect buttons for next and previous video selection
    connect(ui->next_video, &QPushButton::clicked, this, [=]() { changeVideo(true); });
    connect(ui->previous_video, &QPushButton::clicked, this, [=]() { changeVideo(false); });

    // Set up keyboard shortcuts for playback controls
    QShortcut *shortCutForPasueAndPlay = new QShortcut(Qt::Key_Space, this);  // Spacebar for play/pause
    QShortcut *shortCutForSkipForward = new QShortcut(Qt::Key_Right, this);  // Right arrow for skipping forward
    QShortcut *shortCutForSkipBackward = new QShortcut(Qt::Key_Left, this);  // Left arrow for skipping backward
    QShortcut *shortCutForMute = new QShortcut(Qt::CTRL + Qt::Key_M, this);  // Ctrl+M for muting audio

    // Connect shortcuts to corresponding slots or lambda functions
    connect(shortCutForMute, &QShortcut::activated, this, [=]() { changeMute(); });
    connect(shortCutForSkipForward, &QShortcut::activated, this, [=]() { skipForwardOrBackward(true); });
    connect(shortCutForSkipBackward, &QShortcut::activated, this, [=]() { skipForwardOrBackward(false); });
    connect(shortCutForPasueAndPlay, &QShortcut::activated, this, [=]() { playClicked(); });
}


// Update the current playback position on the slider
void MainWindow::positionChange(qint64 progress) // * progress is the current position in milliseconds
{
    // Check if the video slider is not being actively dragged
    if (!ui->video_slider->isSliderDown())
        qDebug() << "max:" << ui->video_slider->maximum();
    ui->video_slider->setValue(progress);  // Update the slider value based on progress

    currentPosition = progress;  // Update the current playback position
    updateDurationInfo(progress / 1000);  // Convert progress to seconds and update duration display
}

// Update the video playback time and display it
void MainWindow::updateDurationInfo(qint64 currentInfo) {
    /* Updates the displayed current playback time */
    qDebug() << "currentInfo" << currentInfo;
    qDebug() << "second_duration" << durationS;

    QString tStr;  // String to hold the formatted time
    if (currentInfo || durationS) {
        // Calculate current and total time using QTime
        QTime currentTime((currentInfo / 3600) % 60, (currentInfo / 60) % 60,
                          currentInfo % 60, (currentInfo * 1000) % 1000);
        QTime totalTime((durationS / 3600) % 60, (durationS / 60) % 60,
                        durationS % 60, (durationS * 1000) % 1000);

        // Use "hh:mm:ss" format if the total duration exceeds 1 hour
        QString format = "mm:ss";
        if (durationS > 3600)
            format = "hh:mm:ss";

        // Format the current and total time as a string
        tStr = currentTime.toString(format) + " / " + totalTime.toString(format);
    }
    qDebug() << "m_labelDuration" << tStr;
    ui->current_time->setText(tStr);  // Update the UI label with the formatted time

    // Handle end of video for repeat or sequential playback
    if (currentInfo == (qint64)durationS) {
        if (isRepeat) {
            initializeVideo(currentVideoPath);  // Restart the current video
            normalPlay();  // Start playback
        } else {
            changeVideo(true);  // Play the next video
        }
    }
}

// Initialize video information based on the provided file path
void MainWindow::initVideoInfo(QString fileName) {
    currentVideoPath = fileName;  // Store the current video file path
    durationMs = (qint64)(currVideoSeekFrame->formatContext->duration / 1000);  // Duration in milliseconds
    durationS = (qint64)(currVideoSeekFrame->formatContext->duration / 1000000);  // Duration in seconds
    qDebug() << "####Total Duration:" << duration << ",durationS:" << durationS << ",durationMs:" << durationMs;
}

// Slot to handle duration change in the media player
void MainWindow::onDurationChanged(qint64 duration) {
    // qDebug() << "####Total Duration:" << duration  << "milliseconds"; // Duration is in milliseconds
    // durationMs = (qint64)(duration);
    // durationS = (qint64)(duration/1000);

    // ui->video_slider->setMaximum((int)durationMs);  // Set the slider's maximum value to video duration
    // qDebug() << "####Total Duration:" << duration  <<",durationS:"<<durationS<<",durationMs:"<<durationMs;
}

// Seek to a specific position in the video
void MainWindow::seek(qint64 time) {
    if (loadedVideo) {
        mediaPlayer->setPosition(time);  // Set the position in milliseconds
    }
}

// Change the video player's volume
void MainWindow::changeVolume(int volume) {
    mediaPlayer->setVolume(volume);  // Set volume (0 to 100)
}

// Toggle mute status for the video player
void MainWindow::changeMute() {
    mediaPlayer->setMuted(m_playerMuted);  // Set mute status
    m_playerMuted = !m_playerMuted;  // Toggle the mute state
}

// Jump to a specific time in the video
void MainWindow::jump(int second) {
    if (!loadedVideo) {  // Check if a video is loaded
        qDebug() << "尚未加载视频";  // Debug message: No video loaded
        return;
    }
    mediaPlayer->setPosition(currentPosition + second * 1000);  // Move to a new position in milliseconds
}



// Function to add a video item to the playlist
void MainWindow::addVideoItem(QString fileName) {
    // Determine the type of media file
    int mediaTypeTemp = mediaType(fileName);

    // Extract the short file name from the full file path
    QString shortFilename = getFileName(fileName);
    qDebug() << "Adding video!";

    // Create a custom widget for the playlist entry
    QWidget *widget_3 = new QWidget(ui->playList);
    widget_3->setObjectName(QString::fromUtf8("widget_3"));
    widget_3->setMaximumSize(QSize(16777215, 1651461));

    // Set up a horizontal layout to arrange child widgets
    QHBoxLayout *horizontalLayout_4 = new QHBoxLayout(widget_3);
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

    // Create a QLabel to display the video file name
    QLabel *label = new QLabel(widget_3);
    label->setText(shortFilename);
    label->setStyleSheet("color: rgb(246,246,246);"
                         "font-family:'Microsoft YaHei';"
                         "font:10pt;");
    label->setObjectName(QString::fromUtf8("label"));

    // Create an "info" button with custom styles
    QPushButton *pushButton_3 = new QPushButton(widget_3);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
    pushButton_3->setMinimumSize(QSize(30, 30));
    pushButton_3->setMaximumSize(QSize(30, 30));
    pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
            "image: url(:new/image/info_1.png);\n"
            "border-radius:0px; \n"
            "padding:0px;\n"
            "}  \n"
            "QPushButton:hover{ \n"
            "image: url(:new/image/info_2.png);\n"
            "border-radius:0px; \n"
            "padding:0px;\n"
            "} \n"
            "\n"
            "QPushButton:checked{ \n"
            "image: url(:new/image/info_1.png);\n"
            "} \n"
            "\n"
            ""));

    // Add the "info" button and file name label to the horizontal layout
    horizontalLayout_4->addWidget(pushButton_3);
    horizontalLayout_4->addWidget(label);

    // Add a spacer to separate buttons visually
    QSpacerItem *horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout_4->addItem(horizontalSpacer_4);

    // Create a "delete" button with custom styles
    QPushButton *pushButton_2 = new QPushButton(widget_3);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setMinimumSize(QSize(30, 30));
    pushButton_2->setMaximumSize(QSize(30, 30));
    pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
        "image: url(:new/image/delete.png);\n"
        "border-radius:0px; \n"
        "padding:0px;\n"
        "}  \n"
        "QPushButton:hover{ \n"
        "image: url(:new/image/delete_hover.png);\n"
        "border-radius:0px; \n"
        "padding:0px;\n"
        "} \n"
        "QPushButton:checked{ \n"
        "image: url(:new/image/delete.png);\n"
        "} \n"
        "\n"
        ""));

    // Add the "delete" button to the layout
    horizontalLayout_4->addWidget(pushButton_2);

    // Create a new list item and assign the custom widget to it
    QListWidgetItem *Qitem = new QListWidgetItem(ui->playList, 0);
    Qitem->setSizeHint(QSize(120, 40));
    ui->playList->setItemWidget(Qitem, widget_3);
    Qitem->setData(Qt::UserRole, fileName);  // Store the file path as user data

    // Connect the delete button to remove the item from the playlist
    connect(pushButton_2, &QPushButton::clicked, this, [=]() {
        ui->playList->removeItemWidget(Qitem);  // Remove the widget from the playlist
        int removeIndex = -1;

        // Search for the file in the playlist
        for (int i = 0; i < playListLocal->size(); i++) {
            if ((*playListLocal)[i] == Qitem->data(Qt::UserRole).toString()) {
                removeIndex = i;

                // Stop the media player if the deleted file is currently playing
                qDebug() << Qitem->data(Qt::UserRole).toString() << currentVideoPath;
                if ((Qitem->data(Qt::UserRole).toString() == currentVideoPath) && m_playerState == QMediaPlayer::PlayingState) {
                    mediaPlayer->stop();
                }
            }
        }

        // Remove the file from the playlist and update the playlist file
        if (removeIndex != -1) {
            playListLocal->removeAt(removeIndex);
            writePlayList(*playListLocal);
        }

        delete Qitem;  // Free the memory for the removed item
    });

    // Retrieve video information
    QString info = getVideoInfo(fileName);

    // Connect the info button to display video details in a message box
    connect(pushButton_3, &QPushButton::clicked, [=]() {
        QMessageBox msgBox;
        msgBox.setStyleSheet(
            "QMessageBox{"
            " border:none;"
            " background-color: rgb(57,60,62);"
            " border-radius: 15px;"
            " color: white;"
            "}"
            "QPushButton{"
            " image: url(:new/image/ok.png);"
            " border-radius:0px;"
            " padding:1px;"
            "}"
            "QLabel {"
            " color: white;"
            "}");

        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.button(QMessageBox::Ok)->setText("");
        msgBox.button(QMessageBox::Ok)->setMinimumSize(QSize(25, 25));
        msgBox.setIcon(QMessageBox::NoIcon);

        QIcon *windowIcon = new QIcon(":new/image/info.png");
        msgBox.setWindowIcon(*windowIcon);
        msgBox.setWindowTitle("");
        msgBox.setWindowFlag(Qt::FramelessWindowHint);  // Remove window frame
        msgBox.setText(info);  // Display video information
        msgBox.exec();
    });
}



// Function to handle the "Open File" button click event
void MainWindow::openFileButtonClicked() {
    QString filename;
    QT_TRY {
        // Open a file dialog to select a video or audio file
        filename = QFileDialog::getOpenFileName();
        if (filename == "") {  // Check if the user canceled the dialog
            return;
        }

        // Validate whether the selected file is a supported video/audio file
        if (!isValidVideoFile(filename)) {
            QMessageBox::warning(this, tr("Error"), tr("The selected file is not a valid video or audio format"));
            return;
        }

        // Check if the file is already in the playlist
        bool inList = false;
        int numVideos = ui->playList->count();
        for (int i = 0; i < numVideos; i++) {
            QString i_address = ui->playList->item(i)->data(Qt::UserRole).toString();
            if (filename == i_address) {
                QMessageBox::information(this, tr("Info"), tr("The selected file is already in the playlist"));
                inList = true;
                break;
            }
        }

        mediaPlayer->pause();  // Pause the player before adding a new file
        if (!inList) {
            addVideoItem(filename);  // Add the new file to the playlist
            playListLocal->append(filename);  // Append the file to the local playlist
        }

        // Initialize and play the video
        qDebug() << "openFileButtonClicked1";
        initializeVideo(filename);
        qDebug() << "openFileButtonClicked2";
        normalPlay();

        // Save the updated playlist to the local file
        if (writePlayList(*playListLocal)) {
            qDebug() << "Playlist saved successfully";
        } else {
            qDebug() << "An error occurred while saving the playlist";
        }
    }
    QT_CATCH(QMediaPlayer::Error e) {  // Catch errors related to QMediaPlayer
        qDebug() << "An error occurred";
        return;
    }
}

// Function to initialize video settings
void MainWindow::initializeVideo(QString fileName) {
    /* Used to initialize video settings for playback */
    currMediaType = mediaType(fileName);

    // If the media file is audio, display the album cover
    if (currMediaType == 1) {
        QImage *notFoundImage = new QImage(":new/image/song.png");
        ui->reverse_widget->slotSetOneFrame(*notFoundImage);
    }

    // Initialize SeekFrame for video navigation
    deleteSeekFrame();
    initSeekFrame(fileName);

    // Initialize video metadata (e.g., duration)
    initVideoInfo(fileName);
}

// Highlight the currently playing video in the playlist
void MainWindow::highlightInFileList() {
    int numVideos = ui->playList->count();
    if (numVideos != 0) {
        int currentVideoIndex = -1;
        for (int i = 0; i < numVideos; i++) {
            QString i_address = ui->playList->item(i)->data(Qt::UserRole).toString();
            if (currentVideoPath == i_address) {
                currentVideoIndex = i;
                break;
            }
        }
        if (currentVideoIndex != -1) {
            ui->playList->item(currentVideoIndex)->setSelected(true);  // Highlight the item
        }
    }
}

// Function to display the normal video widget
void MainWindow::showNormalWidget() {
    ui->normal_widget->setVisible(true);
    ui->reverse_widget->setVisible(false);
}

// Function to display the reverse (audio) widget
void MainWindow::showReverseWidget() {
    ui->normal_widget->setVisible(true);
    ui->reverse_widget->setVisible(false);
}

// Function to play a video normally
void MainWindow::normalPlay() {
    mediaPlayer->setMedia(QMediaContent(QUrl::fromLocalFile(currentVideoPath)));  // Load the video file

    highlightInFileList();  // Highlight the currently playing video in the playlist
    playHistory->append(currentVideoPath);  // Add the current video to playback history

    // If it's an audio file, display the cover image
    if (currMediaType == 1) {
        showReverseWidget();
        QImage cover = getAttachedPic(currentVideoPath);  // Retrieve album cover image
        ui->reverse_widget->slotSetOneFrame(cover);
        QImage *notFoundImage = new QImage(":new/image/song.png");
        ui->reverse_widget->slotSetOneFrame(*notFoundImage);
    } else {
        // Display the normal video widget for video playback
        showNormalWidget();
    }

    play();  // Start playback

    // Set the maximum value for the video progress slider (duration in milliseconds)
    qDebug() << "MainWindow::normalPlay  " << mediaPlayer->duration();
    qDebug() << "MainWindow::normalPlay s " << durationS;
    qDebug() << "MainWindow::normalPlay ms " << durationMs;

    ui->video_slider->setMaximum((int)durationMs);

    // Mark the video as loaded
    if (!loadedVideo) {
        loadedVideo = true;
    }
}

// Function to initialize the system and load the saved playlist
void MainWindow::initSystem() {
    loadedVideo = false;  // Mark no video as loaded initially

    playHistory = new QVector<QString>;  // Initialize playback history
    playListLocal = readPlayList();  // Load the playlist from the local file

    // Add each video in the local playlist to the UI
    if (playListLocal->size() != 0) {
        for (int i = 0; i < playListLocal->size(); i++) {
            addVideoItem((*playListLocal)[i]);
        }
    }

    // Initialize SeekFrame (used for seeking within videos)
    currVideoSeekFrame = NULL;
}




// Function to change the playback speed of the video
void MainWindow::changePlayingRatio(float rt) {
    qDebug() << "Change playback rate to:" << rt;
    if (loadedVideo) {  // Ensure a video is loaded before changing the speed
        mediaPlayer->setPlaybackRate(qreal(rt));  // Set the playback rate
    }
}

// Function to initialize UI components and settings
void MainWindow::initWdigets() {
    /* This function initializes widgets in the main window */
    // Set the window icon
    QIcon *windowIcon = new QIcon(":new/image/player.png");
    this->setWindowIcon(*windowIcon);

    // Initialize play/pause buttons and playlist visibility
    ui->pause_botton->setVisible(false);  // Pause button is initially hidden
    ui->sideBlock->setVisible(false);  // Playlist sidebar is initially hidden

    pf_playback_rate = 1;  // Default playback rate
}

// Function to skip forward or backward in the video playback
void MainWindow::skipForwardOrBackward(bool mode) {
    if (!loadedVideo) {
        qDebug() << "skipForwardOrBackward: No video loaded";
        return;
    }
    if (mode) {  // Skip forward
        int jumpSecond = 5;  // Jump forward 5 seconds
        if (currentPosition + jumpSecond * 1000 >= durationMs) {
            mediaPlayer->setPosition(durationMs - 10);  // Jump to near the end
            qDebug() << "Jump to end";
        } else {
            jump(jumpSecond);
        }
    } else {  // Skip backward
        int jumpSecond = -5;  // Jump backward 5 seconds
        if (currentPosition + jumpSecond * 1000 <= 0) {
            mediaPlayer->setPosition(10);  // Jump to near the start
            qDebug() << "Jump to start";
        } else {
            jump(jumpSecond);
        }
    }
}

// Function to pause the video playback
void MainWindow::pause() {
    m_playerState = QMediaPlayer::StoppedState;  // Update the player state
    ui->play_button->setVisible(true);  // Show the play button
    ui->pause_botton->setVisible(false);  // Hide the pause button
    mediaPlayer->pause();  // Pause the media player
}

// Function to play the video
void MainWindow::play() {
    m_playerState = QMediaPlayer::PlayingState;  // Update the player state
    ui->play_button->setVisible(false);  // Hide the play button
    ui->pause_botton->setVisible(true);  // Show the pause button
    qDebug() << "Start playback";
    mediaPlayer->play();  // Start playback
}

// Function to change the video (play the next or previous video)
void MainWindow::changeVideo(bool nextOrPrevious) {
    /*
     * Possible cases:
     * 1. Playlist is empty
     *    a. No video is loaded
     *    b. A video is loaded, but the playlist is empty
     * 2. Playlist has items
     *    a. No video is loaded
     *    b. The current video is not in the playlist
     *    c. The current video is in the playlist
    */
    if (!loadedVideo) {  // Case 1.a and 2.a: No video is loaded
        qDebug() << "changeVideo: No video loaded";
        return;
    }

    // Case 1.b: If playlist is empty but a video is loaded
    int numVideos = ui->playList->count();
    if (numVideos == 0) {
        mediaPlayer->setPosition(10);  // Jump to the start of the current video
        if (m_playerState == QMediaPlayer::PausedState) play();
        return;
    }

    // Find the index of the current video in the playlist
    int currentVideoIndex = -1;
    QString nextPath = "";
    QString previousPath = "";
    for (int i = 0; i < numVideos; i++) {
        QString i_address = ui->playList->item(i)->data(Qt::UserRole).toString();
        if (currentVideoPath == i_address) {
            currentVideoIndex = i;
            break;
        }
    }

    if (currentVideoIndex == -1) {
        // Case 2.b: The current video is not in the playlist
        nextPath = ui->playList->item(0)->data(Qt::UserRole).toString();  // Use the first video as next
        if (playHistory->count() - 2 < 0) {
            previousPath = nextPath;  // No previous video, use the first video
        } else {
            previousPath = (*playHistory)[playHistory->count() - 2];  // Use the last video in play history
        }
    } else {
        // Case 2.c: The current video is in the playlist
        int previousIndex = currentVideoIndex - 1;
        int nextIndex = currentVideoIndex + 1;

        if (previousIndex < 0) {
            previousIndex = numVideos - 1;  // Loop to the last video
        }
        if (nextIndex >= numVideos) {
            nextIndex = 0;  // Loop to the first video
        }

        previousPath = ui->playList->item(previousIndex)->data(Qt::UserRole).toString();
        nextPath = ui->playList->item(nextIndex)->data(Qt::UserRole).toString();
    }

    qDebug() << "Next video:" << nextPath;
    qDebug() << "Previous video:" << previousPath;

    if (nextOrPrevious) {
        // Play the next video
        initializeVideo(nextPath);
        normalPlay();
    } else {
        // Play the previous video
        initializeVideo(previousPath);
        normalPlay();
    }
}


// Handle mouse press events
void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {  // Check for left mouse button click
        this->m_drag = true;  // Enable dragging
        this->dragPos = event->pos();  // Record the position of the mouse click
        this->resizeDownPos = event->globalPos();  // Record the global mouse position
        this->mouseDownRect = this->rect();  // Record the current widget rectangle

        qDebug() << "State:" << m_playerState;
        if (m_playerState == QMediaPlayer::PlayingState) {
            pause();  // Pause playback if currently playing
        } else if (m_playerState == QMediaPlayer::StoppedState) {
            play();  // Start playback if stopped
        }
    }
}

// Handle mouse movement events for resizing or dragging
void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (resizeRegion != Default) {
        handleResize();  // Handle resizing
        return;
    }

    if (m_move) {  // If dragging is active, move the window
        move(event->globalPos() - dragPos);
        return;
    }

    QPoint clientCursorPos = event->pos();  // Get cursor position relative to the window
    QRect r = this->rect();
    QRect resizeInnerRect(resizeBorderWidth, resizeBorderWidth,
                          r.width() - 2 * resizeBorderWidth, r.height() - 2 * resizeBorderWidth);

    if (r.contains(clientCursorPos) && !resizeInnerRect.contains(clientCursorPos)) {
        // Adjust window size based on cursor position
        ResizeRegion resizeReg = getResizeRegion(clientCursorPos);
        setResizeCursor(resizeReg);

        if (m_drag && (event->buttons() & Qt::LeftButton)) {
            resizeRegion = resizeReg;
            handleResize();
        }
    } else {
        // Move the window if the cursor is inside and dragging is active
        setCursor(Qt::ArrowCursor);
        if (m_drag && (event->buttons() & Qt::LeftButton)) {
            m_move = true;
            move(event->globalPos() - dragPos);
        }
    }
}

// Handle mouse release events
void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    m_drag = false;  // Stop dragging
    if (m_move) {
        m_move = false;
    }
    resizeRegion = Default;  // Reset the resize region
    setCursor(Qt::ArrowCursor);  // Reset the cursor to default
}

// Set the mouse cursor based on the resizing region
void MainWindow::setResizeCursor(ResizeRegion region) {
    switch (region) {
    case North:
    case South:
        setCursor(Qt::SizeVerCursor);
        break;
    case East:
    case West:
        setCursor(Qt::SizeHorCursor);
        break;
    case NorthWest:
    case SouthEast:
        setCursor(Qt::SizeFDiagCursor);
        break;
    default:
        setCursor(Qt::SizeBDiagCursor);
        break;
    }
}

// Determine the resizing region based on cursor position
ResizeRegion MainWindow::getResizeRegion(QPoint clientPos) {
    if (clientPos.y() <= resizeBorderWidth) {
        if (clientPos.x() <= resizeBorderWidth)
            return NorthWest;
        else if (clientPos.x() >= this->width() - resizeBorderWidth)
            return NorthEast;
        else
            return North;
    } else if (clientPos.y() >= this->height() - resizeBorderWidth) {
        if (clientPos.x() <= resizeBorderWidth)
            return SouthWest;
        else if (clientPos.x() >= this->width() - resizeBorderWidth)
            return SouthEast;
        else
            return South;
    } else {
        if (clientPos.x() <= resizeBorderWidth)
            return West;
        else
            return East;
    }
}

// Perform window resizing based on the current resizing region
void MainWindow::handleResize() {
    int xdiff = QCursor::pos().x() - resizeDownPos.x();  // Horizontal movement
    int ydiff = QCursor::pos().y() - resizeDownPos.y();  // Vertical movement
    qDebug() << "xdiff:" << xdiff << "ydiff:" << ydiff;

    switch (resizeRegion) {
    case East:
        resize(mouseDownRect.width() + xdiff, this->height());
        break;
    case West:
        resize(mouseDownRect.width() - xdiff, this->height());
        move(resizeDownPos.x() + xdiff, this->y());
        break;
    case South:
        resize(this->width(), mouseDownRect.height() + ydiff);
        break;
    case North:
        resize(this->width(), mouseDownRect.height() - ydiff);
        move(this->x(), resizeDownPos.y() + ydiff);
        break;
    case SouthEast:
        resize(mouseDownRect.width() + xdiff, mouseDownRect.height() + ydiff);
        break;
    case NorthEast:
        resize(mouseDownRect.width() + xdiff, mouseDownRect.height() - ydiff);
        move(this->x(), resizeDownPos.y() + ydiff);
        break;
    case NorthWest:
        resize(mouseDownRect.width() - xdiff, mouseDownRect.height() - ydiff);
        move(resizeDownPos.x() + xdiff, resizeDownPos.y() + ydiff);
        break;
    case SouthWest:
        resize(mouseDownRect.width() - xdiff, mouseDownRect.height() + ydiff);
        move(resizeDownPos.x() + xdiff, this->y());
        break;
    }
}

// Update the video slider's position
void MainWindow::reverseShowRatio(qint64 pts) {
    ui->video_slider->setValue(int(pts));
}

// Initialize the SeekFrame object for video seeking
void MainWindow::initSeekFrame(QString fileName) {
    currVideoSeekFrame = new SeekFrame(fileName, 1000, 9999);
}

// Delete the SeekFrame object and release memory
void MainWindow::deleteSeekFrame() {
    if (this->currVideoSeekFrame != NULL) {
        delete currVideoSeekFrame;
        currVideoSeekFrame = NULL;
    }
}

// Change the play order: Repeat or Sequential
void MainWindow::changePlayOrder() {
    if (isRepeat) {
        ui->repeat->setStyleSheet(" QPushButton{ image: url(:new/image/inorder.png); border-radius:0px; }");
        isRepeat = false;
    } else {
        ui->repeat->setStyleSheet(" QPushButton{ image: url(:new/image/repeat.png); border-radius:0px; }");
        isRepeat = true;
    }
}

// Adjust playback speed when the speed button is clicked
void MainWindow::on_speedBtn_clicked() {
    pf_playback_rate += PLAYBACK_RATE_SCALE;  // Increase playback rate by a step
    if (pf_playback_rate > PLAYBACK_RATE_MAX) {
        pf_playback_rate = PLAYBACK_RATE_MIN;  // Reset to minimum rate
    }
    changePlayingRatio(pf_playback_rate);  // Update playback speed

    // Mute audio when the playback speed is not 1x
    mediaPlayer->setMuted(pf_playback_rate != 1);
}

// Update the application's language based on the ComboBox selection
void MainWindow::on_comboBox_activated(const QString &arg1) {
    if (ui->comboBox->currentIndex() == 0) {
        qDebug() << "Display in Chinese";
        tran.load("://chinese.qm");
    } else if (ui->comboBox->currentIndex() == 1) {
        qDebug() << "Display in English";
        tran.load("://english.qm");
    } else {
        qDebug() << "Other language selected";
    }
    qApp->installTranslator(&tran);  // Install the selected language
    ui->retranslateUi(this);  // Update UI translations
}

// Handle language change events
void MainWindow::changeEvent(QEvent *e) {
    QWidget::changeEvent(e);  // Call the base class's event handler
    if (e->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);  // Update the UI texts
        qDebug() << "Language change event triggered";
    }
}

// Adjust playback speed when ComboBox_2 is activated
void MainWindow::on_comboBox_2_activated(int index) {
    pf_playback_rate = PLAYBACK_RATE_SCALE + index * 0.25;  // Adjust playback rate
    changePlayingRatio(pf_playback_rate);
    mediaPlayer->setMuted(pf_playback_rate != 1);
}
