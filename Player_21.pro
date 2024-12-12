QT       += core gui
QT += multimediawidgets
QT += opengl
QT += gui
QT += network \
      xml \
      multimedia \
      widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Widget/VideoSlider.cpp \
    Widget/videowidget.cpp \
    main.cpp \
    mainwindow.cpp \
    seekFrame.cpp \
    utils.cpp

HEADERS += \
    Widget/VideoSlider.h \
    Widget/videowidget.h \
    mainwindow.h \
    seekFrame.h \
    utils.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target


win32 {
LIBS +=\
    -L$$PWD/lib/ffmpeg-4.2.1-win32-dev/lib \
    -lavcodec \
    -lavdevice \
    -lavfilter \
    -lavformat \
    -lavutil \
    -lswresample \
    -lswscale

INCLUDEPATH += src \
    lib/ffmpeg-4.2.1-win32-dev/include
}

LIBS += -lopengl32\
         -lGLU32
