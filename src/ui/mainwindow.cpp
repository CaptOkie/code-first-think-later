#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginwidget.h"
#include "adminhomewidget.h"

MainWindow::MainWindow(Storage* db, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), db(db)
{
    ui->setupUi(this);

    showLogin();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeView(QWidget* widget)
{
    QWidget* old = ui->stackedWidget->currentWidget();
    ui->stackedWidget->addWidget(widget);
    if (old != 0) {
        ui->stackedWidget->removeWidget(old);
        delete old;
    }
}

void MainWindow::showLogin()
{
    LoginWidget* loginWidget = new LoginWidget(db);
    changeView(loginWidget);
    connect(loginWidget, &LoginWidget::loggedIn, this, &MainWindow::showHome);
}

void MainWindow::showHome(UserType userType)
{
    QWidget* widget;
    switch(userType) {
        case ADMIN:
            widget = new AdminHomeWidget(ui->stackedWidget);
            break;
        default:
            break;
    }
    changeView(widget);
}
