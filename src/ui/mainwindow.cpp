#include "stdio.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stulogindialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->studentBtn, SIGNAL (clicked()), this, SLOT (handleButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton()
{
    QDialog* stuDialog = new StuLoginDialog(parentWidget());
    stuDialog->show();
}
