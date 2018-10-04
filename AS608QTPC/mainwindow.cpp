#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "as608.h"
as608 zwmk;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int i;
    zwmk.PSGetUSBDevNum(&i);
    qDebug()<<i;
}

MainWindow::~MainWindow()
{
    delete ui;
}
