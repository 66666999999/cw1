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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <Widget/videowidget.h>
#include "Widget/VideoSlider.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
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
    QSpacerItem *horizontalSpacer_32;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *previous_video;
    QSpacerItem *horizontalSpacer_26;
    QPushButton *play_button;
    QPushButton *pause_botton;
    QSpacerItem *horizontalSpacer_25;
    QPushButton *next_video;
    QSpacerItem *horizontalSpacer;
    QPushButton *volume_button;
    QSlider *volume_slider;
    QHBoxLayout *horizontalLayout_2;
    VideoWidget *normal_widget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1010, 674);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_controller = new QWidget(centralwidget);
        widget_controller->setObjectName(QString::fromUtf8("widget_controller"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_controller->sizePolicy().hasHeightForWidth());
        widget_controller->setSizePolicy(sizePolicy);
        widget_controller->setMinimumSize(QSize(0, 55));
        widget_controller->setMaximumSize(QSize(16777215, 55));
        widget_controller->setStyleSheet(QString::fromUtf8(""));
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
        video_slider->setStyleSheet(QString::fromUtf8(""));
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
        current_time->setStyleSheet(QString::fromUtf8(""));

        video_time_layout_5->addWidget(current_time);


        buttons_slide->addLayout(video_time_layout_5);

        horizontalSpacer_23 = new QSpacerItem(6, 29, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_23);

        horizontalSpacer_32 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_32);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_2);

        previous_video = new QPushButton(widget_controller);
        previous_video->setObjectName(QString::fromUtf8("previous_video"));
        previous_video->setMinimumSize(QSize(36, 36));
        previous_video->setCursor(QCursor(Qt::PointingHandCursor));
        previous_video->setStyleSheet(QString::fromUtf8(""));

        buttons_slide->addWidget(previous_video);

        horizontalSpacer_26 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_26);

        play_button = new QPushButton(widget_controller);
        play_button->setObjectName(QString::fromUtf8("play_button"));
        play_button->setMinimumSize(QSize(36, 36));
        play_button->setCursor(QCursor(Qt::PointingHandCursor));
        play_button->setStyleSheet(QString::fromUtf8(""));

        buttons_slide->addWidget(play_button);

        pause_botton = new QPushButton(widget_controller);
        pause_botton->setObjectName(QString::fromUtf8("pause_botton"));
        pause_botton->setMinimumSize(QSize(36, 36));
        pause_botton->setCursor(QCursor(Qt::PointingHandCursor));
        pause_botton->setStyleSheet(QString::fromUtf8(""));

        buttons_slide->addWidget(pause_botton);

        horizontalSpacer_25 = new QSpacerItem(6, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer_25);

        next_video = new QPushButton(widget_controller);
        next_video->setObjectName(QString::fromUtf8("next_video"));
        next_video->setMinimumSize(QSize(36, 36));
        next_video->setCursor(QCursor(Qt::PointingHandCursor));
        next_video->setStyleSheet(QString::fromUtf8(""));

        buttons_slide->addWidget(next_video);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttons_slide->addItem(horizontalSpacer);

        volume_button = new QPushButton(widget_controller);
        volume_button->setObjectName(QString::fromUtf8("volume_button"));
        volume_button->setMinimumSize(QSize(36, 36));
        volume_button->setCursor(QCursor(Qt::PointingHandCursor));
        volume_button->setStyleSheet(QString::fromUtf8(""));
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
        volume_slider->setStyleSheet(QString::fromUtf8(""));
        volume_slider->setMaximum(100);
        volume_slider->setSingleStep(0);
        volume_slider->setPageStep(0);
        volume_slider->setValue(100);
        volume_slider->setOrientation(Qt::Orientation::Horizontal);

        buttons_slide->addWidget(volume_slider);


        verticalLayout_2->addLayout(buttons_slide);


        verticalLayout_8->addLayout(verticalLayout_2);


        gridLayout_2->addWidget(widget_controller, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        normal_widget = new VideoWidget(centralwidget);
        normal_widget->setObjectName(QString::fromUtf8("normal_widget"));

        horizontalLayout_2->addWidget(normal_widget);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250", nullptr));
        current_time->setText(QCoreApplication::translate("MainWindow", "00:00:00 / 00:00:00", nullptr));
        previous_video->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\346\233\262", nullptr));
        play_button->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276", nullptr));
        pause_botton->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        next_video->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\346\233\262", nullptr));
        volume_button->setText(QCoreApplication::translate("MainWindow", "\351\235\231\351\237\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
