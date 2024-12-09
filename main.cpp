#include "mainwindow.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <QString>
#include <inttypes.h>



using namespace std;
#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);


    MainWindow w;
    w.show();
    return a.exec();
}
