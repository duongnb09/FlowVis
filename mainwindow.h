/*=========================================================================
    Program:   Flow Visualization
    Module:    mainwindow.h

    Copyright (c) 2018 Duong B. Nguyen
    All rights reserved.

    See Copyright.txt for details

=========================================================================*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    /* Open a file dialog and load an input flow simulation data file */
    void on_actionOpen_File_triggered();

    /* Set flow simulation based on the selection from users */
    void setFlowData(const QString);

private: // functions
    void setupSignalSlotConnection();

private: // variables
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
