#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginwidget.h"

#include "stulogindialog.h"
#include "adminlogindialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    LoginWidget* loginWidget = new LoginWidget(this);
    int index = ui->stackedWidget->addWidget(loginWidget);
    ui->stackedWidget->setCurrentIndex(index);

//    connect(ui->studentBtn, SIGNAL(clicked()), this, SLOT(handleStuButton()));
//    connect(ui->adminBtn, SIGNAL(clicked()), this, SLOT(handleAdminButton()));
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
