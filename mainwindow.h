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

#include <algorithm>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <QMainWindow>
#include <VectorField/VectorFieldInterface.h>
#include <VectorField/DoubleGyreVectorField.h>
#include <Utilities/Utilities.h>

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

signals:
    void licDataChanged(VectorField& vectorFieldData);

private slots:

    /* Set flow simulation based on the selection from users */
    void setFlowData(const QString&);

    /* Open a file dialog and load an input flow simulation data file */
    void on_actionOpen_File_triggered();





private: // functions
    void setupSignalSlotConnection();

    void updateFlowField();

private: // variables
    Ui::MainWindow *ui;

    int flowID;
    VectorField *flowField;
};

#endif // MAINWINDOW_H
