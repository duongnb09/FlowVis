/*=========================================================================
    Program:   Flow Visualization
    Module:    mainwindow.cpp

    Copyright (c) 2018 Duong B. Nguyen
    All rights reserved.

    See Copyright.txt for details

=========================================================================*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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
    connect(ui->flowID_ComboBox, SIGNAL(activated(QString)), this, SLOT(setFlowData(QString)));
}

/*
 * Set flow simulation based on the selection from users
 */
void MainWindow::setFlowData(const QString)
{

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
