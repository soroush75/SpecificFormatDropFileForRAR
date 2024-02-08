#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QWidget"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

