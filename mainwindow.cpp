/*=========================================================================
    Program:   Flow Visualization
    Module:    mainwindow.cpp

    Copyright (c) 2018 Duong B. Nguyen
    All rights reserved.

    See LICENSE for details

=========================================================================*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <Utilities/Utilities.h>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupSignalSlotConnection();
}

MainWindow::~MainWindow()
{
    delete ui;

}

/*
 * Set up slots for signals generated from UI events
 */
void MainWindow::setupSignalSlotConnection()
{
    connect(ui->flowID_ComboBox, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(setFlowData(const QString&)));
    connect(this,SIGNAL(licDataChanged(VectorField&)),ui->licOpenGLWidget,SLOT(updateLICData(VectorField&)));
}

/*
 * Set flow simulation based on the selection from users
 */
void MainWindow::setFlowData(const QString& flowName)
{

    string flowNameStr = flowName.toStdString();
    unordered_map<string, int> flowIDMapper{
        { "Double Gyre", Flow_DoubleGyre },
        { "Cylinder 2D", Flow_Cylinder2D },
    };

    flowID = (FlowID)flowIDMapper[flowNameStr];
    updateFlowField();

}

void MainWindow::updateFlowField()
{

    switch (flowID) {
        case Flow_DoubleGyre:
        {
            flowField = new DoubleGyreVectorField(0.1, PI / 5., 0.25);
            cout<<"Flow float gyre"<<endl;
            emit licDataChanged(*flowField);
            break;
        }
        default:
        {
            break;
        }
    }
}

/*
 * Open a file dialog and load an input flow simulation data file
 */
void MainWindow::on_actionOpen_File_triggered()
{

    QString fileName;
    QStringList fileNames;
    QFileDialog dialog(this);

    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setViewMode(QFileDialog::List);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

    if ( dialog.exec() ) {

        fileNames = dialog.selectedFiles();

        QStringList list = fileNames;
        QStringList::Iterator it = list.begin();
        while(it != list.end()) {
            fileName = *it;
            ++it;
        }

        //Notify Loader to load file - TODO
        std::cout<<fileName.toStdString()<<std::endl;
    }
}
