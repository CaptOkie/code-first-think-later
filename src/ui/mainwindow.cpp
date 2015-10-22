#include "stdio.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->studentBtn, SIGNAL (pressed()), this, SLOT (handleButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton()
{

}
