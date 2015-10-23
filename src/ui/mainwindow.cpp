#include "stdio.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stulogindialog.h"
#include "adminlogindialog.h"
#include <QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->studentBtn, SIGNAL(clicked()), this, SLOT(handleStuButton()));
    connect(ui->adminBtn, SIGNAL(clicked()), this, SLOT(handleAdminButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleStuButton()
{
    QDialog* stuDialog = new StuLoginDialog(parentWidget());
    stuDialog->exec();
}

void MainWindow::handleAdminButton()
{
    QDialog* adminDialog = new AdminLoginDialog(parentWidget());
    adminDialog->exec();
}
