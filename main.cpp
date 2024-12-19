#include "mainwindow.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>
#include <QString>
#include <inttypes.h>
#include <QTranslator>
#include <QDebug>

// Include FFmpeg libraries for multimedia processing
extern "C" {
#include <libavcodec/avcodec.h>       // Codec library
#include <libavutil/avutil.h>         // Utility functions for FFmpeg
#include <libavformat/avformat.h>     // Format handling
#include <libswscale/swscale.h>       // Scaling and pixel format conversion
#include <libavutil/imgutils.h>       // Image utility functions
}

using namespace std;
#include <QApplication>  // Include QApplication for GUI application setup

int main(int argc, char *argv[])
{
    // Print FFmpeg version and codec configuration to debug output
    qDebug() << av_version_info();
    qDebug() << avcodec_configuration();

    // Initialize the Qt application
    QApplication a(argc, argv);

    // Load Chinese translation file for the application
    QTranslator tran;  // Translator object
    tran.load("://chinese.qm");  // Load the Chinese translation file
    a.installTranslator(&tran);  // Install the translator into the application

    // Create and display the main window
    MainWindow w;
    w.show();

    // Start the Qt event loop
    return a.exec();
}
