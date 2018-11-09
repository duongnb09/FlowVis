/*=========================================================================
    Program:   Flow Visualization
    Module:    main.cpp

    Copyright (c) 2018 Duong B. Nguyen
    All rights reserved.

    See LICENSE for details

=========================================================================*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
