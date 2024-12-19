/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Widget/VideoSlider.h"
#include "Widget/videoframedisplay.h"
#include "Widget/videowidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_29;
    QPushButton *pushButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *minimize;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *maximize;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *close;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    VideoWidget *normal_widget;
    VideoFrameDisplay *reverse_widget;
    QWidget *sideBlock;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout;
    QListWidget *playList;
    QWidget *widget_controller;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    VideoSlider *video_slider;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *buttons_slide;
    QHBoxLayout *video_time_layout_5;
    QSpacerItem *horizontalSpacer_30;
    QLabel *current_time;
    QSpacerItem *horizontalSpacer_23;
    QPushButton *backward_seconds;
    QPushButton *forward_seconds;
    QSpacerItem *horizontalSpacer_32;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *previous_video;
    QSpacerItem *horizontalSpacer_26;
    QPushButton *play_button;
    QPushButton *pause_botton;
    QSpacerItem *horizontalSpacer_25;
    QPushButton *next_video;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_2;
    QPushButton *volume_button;
    QSlider *volume_slider;
    QSpacerItem *horizontalSpacer_31;
    QPushButton *repeat;
    QSpacerItem *horizontalSpacer_27;
    QPushButton *addFile;
    QSpacerItem *horizontalSpacer_28;
    QPushButton *openFileList;
    QSpacerItem *horizontalSpacer_40;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1010, 674);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow#MainWindow\n"
"{\n"
"	background-color: rgba(60, 65, 68,160);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-radius: 15px;\n"
"}"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 20));
        widget_2->setMaximumSize(QSize(16777215, 20));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_29 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_29);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(25, 22));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/player.png);\n"
"border-radius:0px; \n"
"} \n"
""));

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-radius:0px;\n"
"	color: #F0F0F0;\n"
"	background-color:rgba(0,0,0,0);\n"
"	border-style:none;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:16px;\n"
"}\n"
""));

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        comboBox = new QComboBox(widget_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        minimize = new QPushButton(widget_2);
        minimize->setObjectName(QString::fromUtf8("minimize"));
        minimize->setMinimumSize(QSize(21, 18));
        minimize->setMaximumSize(QSize(19, 15));
        minimize->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/min.svg);\n"
"border-radius:0px; \n"
"}  "));

        horizontalLayout->addWidget(minimize);

        horizontalSpacer_7 = new QSpacerItem(6, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        maximize = new QPushButton(widget_2);
        maximize->setObjectName(QString::fromUtf8("maximize"));
        maximize->setMinimumSize(QSize(25, 18));
        maximize->setMaximumSize(QSize(19, 15));
        maximize->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/max.svg);\n"
"border-radius:0px; \n"
"}  "));

        horizontalLayout->addWidget(maximize);

        horizontalSpacer_8 = new QSpacerItem(6, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        close = new QPushButton(widget_2);
        close->setObjectName(QString::fromUtf8("close"));
        close->setMinimumSize(QSize(25, 18));
        close->setMaximumSize(QSize(19, 15));
        close->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/close.svg);\n"
"border-radius:0px; \n"
"}  "));

        horizontalLayout->addWidget(close);

        horizontalSpacer_6 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        normal_widget = new VideoWidget(centralwidget);
        normal_widget->setObjectName(QString::fromUtf8("normal_widget"));

        horizontalLayout_2->addWidget(normal_widget);

        reverse_widget = new VideoFrameDisplay(centralwidget);
        reverse_widget->setObjectName(QString::fromUtf8("reverse_widget"));

        horizontalLayout_2->addWidget(reverse_widget);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        sideBlock = new QWidget(centralwidget);
        sideBlock->setObjectName(QString::fromUtf8("sideBlock"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sideBlock->sizePolicy().hasHeightForWidth());
        sideBlock->setSizePolicy(sizePolicy);
        sideBlock->setMinimumSize(QSize(210, 0));
        sideBlock->setMaximumSize(QSize(250, 999999));
        sideBlock->setStyleSheet(QString::fromUtf8("QWidget#widget_controller_2\n"
"\n"
"{\n"
"	background-color: rgba(60, 65, 68,160);\n"
"	border-radius: 15px;\n"
"}"));
        verticalLayout_10 = new QVBoxLayout(sideBlock);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 9, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        playList = new QListWidget(sideBlock);
        playList->setObjectName(QString::fromUtf8("playList"));
        playList->setAutoFillBackground(true);
        playList->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(57,60,62);\n"
"	border-radius: 15px;\n"
"}\n"
"\n"
"QListView::item{\n"
"\n"
"font-size:30px;\n"
"color: rgba(0, 120, 215, 100); \n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"\n"
"\n"
"}\n"
"\n"
"QListView::item:hover {\n"
"background-color: rgba(0, 120, 215, 100);\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"/*background-color: #4B5CC4;*/\n"
"background-color: rgba(0, 120, 215, 100);\n"
"}\n"
"\n"
"\n"
"/*\n"
"QListView::item:selected:!active {\n"
"border-radius:5px; \n"
"border:1px solid rgb(210, 225, 230);\n"
"background-color: qlineargradient(spread:reflect, x1:0.501, y1:0, x2:0.506, y2:0.489182, stop:0.0284091 rgba(255, 255, 255, 255), stop:1 rgba(255, 170, 0, 255));\n"
"}\n"
"QListView::item:selected:active {\n"
"border-radius:5px; \n"
"border:1px solid rgb(210, 225, 230);\n"
"background-color: qlineargradient(spread:reflect, x1:0.501, y1:0, x2:0.506, y2:0.489182, stop:0.0284091 rgba(255, 255, 255, 255), stop:1 "
                        "rgba(255, 170, 0, 255));\n"
"}\n"
"*/"));

        verticalLayout->addWidget(playList);


        verticalLayout_10->addLayout(verticalLayout);


        gridLayout_2->addWidget(sideBlock, 1, 1, 2, 1);

        widget_controller = new QWidget(centralwidget);
        widget_controller->setObjectName(QString::fromUtf8("widget_controller"));
        sizePolicy.setHeightForWidth(widget_controller->sizePolicy().hasHeightForWidth());
        widget_controller->setSizePolicy(sizePolicy);
        widget_controller->setMinimumSize(QSize(0, 55));
        widget_controller->setMaximumSize(QSize(16777215, 55));
        widget_controller->setStyleSheet(QString::fromUtf8("QWidget#widget_controller\n"
"{\n"
"	background-color: rgba(60, 65, 68,160);\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(widget_controller);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(widget_controller);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 2, 0, 1);
        horizontalSpacer_4 = new QSpacerItem(5, 5, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        video_slider = new VideoSlider(widget);
        video_slider->setObjectName(QString::fromUtf8("video_slider"));
        video_slider->setMaximumSize(QSize(16777215, 6));
        video_slider->setCursor(QCursor(Qt::PointingHandCursor));
        video_slider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 0px solid #bbb;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background-color: #FFFFFF;\n"
"border-bottom-left-radius: 2px; \n"
"border-top-left-radius: 2px; \n"
"\n"
"border-radius: 2px; \n"
"margin-top:0px;\n"
"margin-bottom:0px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background-color: rgba(228, 228, 228, 50);v\n"
"border: 0px solid #777;\n"
"border-radius: 2px;\n"
"margin-top:0px;\n"
"margin-bottom:0px;\n"
"}\n"
"/*\n"
"QSlider::handle:horizontal {\n"
"background: rgb(255,153,102); \n"
"border: 1px solid rgb(255,153,102); \n"
"width: 14px;\n"
"height:10px;\n"
"border-radius: 7px;\n"
"margin-top:2px;\n"
"margin-bottom:2px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: rgb(255,128,6); \n"
"border: 1px solid rgba(102,102,102,102);\n"
"border-radius: 7px;\n"
"}*/\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
""
                        "border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 2px;\n"
"}\n"
""));
        video_slider->setMaximum(100);
        video_slider->setValue(0);
        video_slider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_3->addWidget(video_slider);

        horizontalSpacer_5 = new QSpacerItem(5, 5, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_2->addWidget(widget);

        buttons_slide = new QHBoxLayout();
        buttons_slide->setSpacing(1);
        buttons_slide->setObjectName(QString::fromUtf8("buttons_slide"));
        buttons_slide->setContentsMargins(-1, -1, 0, -1);
        video_time_layout_5 = new QHBoxLayout();
        video_time_layout_5->setSpacing(3);
        video_time_layout_5->setObjectName(QString::fromUtf8("video_time_layout_5"));
        horizontalSpacer_30 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        video_time_layout_5->addItem(horizontalSpacer_30);

        current_time = new QLabel(widget_controller);
        current_time->setObjectName(QString::fromUtf8("current_time"));
        current_time->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-radius:0px;\n"
"	color: #F0F0F0;\n"
"	background-color:rgba(0,0,0,0);\n"
"	border-style:none;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-size:16px;\n"
"}\n"
""));

        video_time_layout_5->addWidget(current_time);


        buttons_slide->addLayout(video_time_layout_5);

        horizontalSpacer_23 = new QSpacerItem(6, 29, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_23);

        backward_seconds = new QPushButton(widget_controller);
        backward_seconds->setObjectName(QString::fromUtf8("backward_seconds"));
        backward_seconds->setMinimumSize(QSize(36, 36));
        backward_seconds->setCursor(QCursor(Qt::PointingHandCursor));
        backward_seconds->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/backward_second.png);\n"
"border-radius:0px; \n"
"}  \n"
"QPushButton:hover{ \n"
"image: url(:new/image/backward_second.png);\n"
"border-radius:0px; \n"
"} \n"
"QPushButton:pressed{ \n"
"image: url(:new/image/backward_second.png);\n"
"border-radius:0px; \n"
"}"));

        buttons_slide->addWidget(backward_seconds);

        forward_seconds = new QPushButton(widget_controller);
        forward_seconds->setObjectName(QString::fromUtf8("forward_seconds"));
        forward_seconds->setMinimumSize(QSize(36, 36));
        forward_seconds->setCursor(QCursor(Qt::PointingHandCursor));
        forward_seconds->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/forward_second.png);\n"
"border-radius:0px; \n"
"}  \n"
"QPushButton:hover{ \n"
"image: url(:new/image/forward_second.png);\n"
"border-radius:0px; \n"
"} \n"
"QPushButton:pressed{ \n"
"image: url(:new/image/forward_second.png);\n"
"border-radius:0px; \n"
"}"));

        buttons_slide->addWidget(forward_seconds);

        horizontalSpacer_32 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_32);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_2);

        previous_video = new QPushButton(widget_controller);
        previous_video->setObjectName(QString::fromUtf8("previous_video"));
        previous_video->setMinimumSize(QSize(36, 36));
        previous_video->setCursor(QCursor(Qt::PointingHandCursor));
        previous_video->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/back.png);\n"
"border-radius:0px; \n"
"}  \n"
""));

        buttons_slide->addWidget(previous_video);

        horizontalSpacer_26 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_26);

        play_button = new QPushButton(widget_controller);
        play_button->setObjectName(QString::fromUtf8("play_button"));
        play_button->setMinimumSize(QSize(36, 36));
        play_button->setCursor(QCursor(Qt::PointingHandCursor));
        play_button->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/start_normal.png);\n"
"border-radius:0px; \n"
"}  \n"
"QPushButton:hover{ \n"
"image: url(:new/image/start_focus.png);\n"
"border-radius:0px; \n"
"} \n"
"QPushButton:pressed{ \n"
"image: url(:new/image/start_normal.png);\n"
"border-radius:0px; \n"
"}"));

        buttons_slide->addWidget(play_button);

        pause_botton = new QPushButton(widget_controller);
        pause_botton->setObjectName(QString::fromUtf8("pause_botton"));
        pause_botton->setMinimumSize(QSize(36, 36));
        pause_botton->setCursor(QCursor(Qt::PointingHandCursor));
        pause_botton->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/pause_normal.png);\n"
"border-radius:0px; \n"
"} \n"
"QPushButton:hover{ \n"
"image: url(:new/image/pause_focus.png);\n"
"border-radius:0px; \n"
"} \n"
"QPushButton:pressed{ \n"
"image: url(:new/image/pause_normal.png);\n"
"border-radius:0px; \n"
"}\n"
""));

        buttons_slide->addWidget(pause_botton);

        horizontalSpacer_25 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_25);

        next_video = new QPushButton(widget_controller);
        next_video->setObjectName(QString::fromUtf8("next_video"));
        next_video->setMinimumSize(QSize(36, 36));
        next_video->setCursor(QCursor(Qt::PointingHandCursor));
        next_video->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/forward.png);\n"
"border-radius:0px; \n"
"}  \n"
""));

        buttons_slide->addWidget(next_video);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer);

        comboBox_2 = new QComboBox(widget_controller);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(110, 30));
        comboBox_2->setMaximumSize(QSize(110, 30));
        QFont font;
        font.setPointSize(12);
        comboBox_2->setFont(font);

        buttons_slide->addWidget(comboBox_2);

        volume_button = new QPushButton(widget_controller);
        volume_button->setObjectName(QString::fromUtf8("volume_button"));
        volume_button->setMinimumSize(QSize(36, 36));
        volume_button->setCursor(QCursor(Qt::PointingHandCursor));
        volume_button->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/volume_normal.png);\n"
"border-radius:0px; \n"
"padding:5px;\n"
"}  \n"
"QPushButton:hover{ \n"
"image: url(:new/image/volume_normal_focus.png);\n"
"border-radius:0px; \n"
"padding:3px;\n"
"} \n"
"QPushButton:!checked{ \n"
"image: url(:new/image/volume_normal.png);\n"
"} \n"
"QPushButton:checked{ \n"
"image: url(:new/image/volume_mute.png);\n"
"} \n"
"\n"
""));
        volume_button->setCheckable(true);

        buttons_slide->addWidget(volume_button);

        volume_slider = new QSlider(widget_controller);
        volume_slider->setObjectName(QString::fromUtf8("volume_slider"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(volume_slider->sizePolicy().hasHeightForWidth());
        volume_slider->setSizePolicy(sizePolicy1);
        volume_slider->setMinimumSize(QSize(0, 20));
        volume_slider->setMaximumSize(QSize(150, 16777215));
        volume_slider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 0px solid #bbb;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: rgb(7,163,90);\n"
"border-radius: 0px;\n"
"margin-top:8px;\n"
"margin-bottom:8px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: rgb(255,255, 255);\n"
"border: 0px solid #777;\n"
"border-radius: 2px;\n"
"margin-top:8px;\n"
"margin-bottom:8px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: rgb(191,191,191); \n"
"border: 1px solid rgb(191,191,191); \n"
"width: 8px;\n"
"height:8px;\n"
"border-radius: 2px;\n"
"margin-top:6px;\n"
"margin-bottom:6px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: rgb(255,255,255); \n"
"\n"
"border-radius: 7px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border"
                        "-radius: 4px;\n"
"}\n"
"\n"
""));
        volume_slider->setMaximum(100);
        volume_slider->setSingleStep(0);
        volume_slider->setPageStep(0);
        volume_slider->setValue(100);
        volume_slider->setOrientation(Qt::Orientation::Horizontal);

        buttons_slide->addWidget(volume_slider);

        horizontalSpacer_31 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_31);

        repeat = new QPushButton(widget_controller);
        repeat->setObjectName(QString::fromUtf8("repeat"));
        repeat->setMinimumSize(QSize(24, 24));
        repeat->setMaximumSize(QSize(24, 24));
        repeat->setCursor(QCursor(Qt::PointingHandCursor));
        repeat->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/inorder.png);\n"
"border-radius:0px; \n"
"} \n"
""));

        buttons_slide->addWidget(repeat);

        horizontalSpacer_27 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_27);

        addFile = new QPushButton(widget_controller);
        addFile->setObjectName(QString::fromUtf8("addFile"));
        addFile->setMinimumSize(QSize(24, 24));
        addFile->setMaximumSize(QSize(24, 24));
        addFile->setCursor(QCursor(Qt::PointingHandCursor));
        addFile->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/add.png);\n"
"border-radius:0px; \n"
"} \n"
"QPushButton:hover{ \n"
"image: url(:new/image/add.png);\n"
"border-radius:0px; \n"
"} \n"
"QPushButton:pressed{ \n"
"image: url(:new/image/add.png);\n"
"border-radius:0px; \n"
"}\n"
""));

        buttons_slide->addWidget(addFile);

        horizontalSpacer_28 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_28);

        openFileList = new QPushButton(widget_controller);
        openFileList->setObjectName(QString::fromUtf8("openFileList"));
        openFileList->setMinimumSize(QSize(36, 36));
        openFileList->setCursor(QCursor(Qt::PointingHandCursor));
        openFileList->setStyleSheet(QString::fromUtf8("QPushButton{ \n"
"image: url(:new/image/off1.png);\n"
"border-radius:0px; \n"
"}  \n"
""));

        buttons_slide->addWidget(openFileList);

        horizontalSpacer_40 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_40);


        verticalLayout_2->addLayout(buttons_slide);


        verticalLayout_8->addLayout(verticalLayout_2);


        gridLayout_2->addWidget(widget_controller, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\344\270\255\346\226\207", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "English", nullptr));

        minimize->setText(QString());
#if QT_CONFIG(statustip)
        maximize->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        maximize->setText(QString());
        close->setText(QString());
        current_time->setText(QCoreApplication::translate("MainWindow", "00:00:00 / 00:00:00", nullptr));
        backward_seconds->setText(QString());
        forward_seconds->setText(QString());
        previous_video->setText(QString());
        play_button->setText(QString());
        pause_botton->setText(QString());
        next_video->setText(QString());
        volume_button->setText(QString());
        repeat->setText(QString());
        addFile->setText(QString());
        openFileList->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
