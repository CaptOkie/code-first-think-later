#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginwidget.h"
#include "adminhomewidget.h"
#include "studenthomewidget.h"

MainWindow::MainWindow(Storage& db, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), db(db), currUser(NULL)
{
    ui->setupUi(this);

    QAction* action = new QAction(this);
    action->setShortcut(Qt::Key_Q | Qt::CTRL);
    connect(action, &QAction::triggered, this, &MainWindow::close);
    addAction(action);

    showLogin();
}

MainWindow::~MainWindow()
{
    delete ui;
    if(currUser != NULL) {
        delete currUser;
    }
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

void MainWindow::showHome(User* user)
{
    QWidget* widget = NULL;
    currUser = user;
    switch(user->getType()) {
        case User::ADMIN:
            widget = new AdminHomeWidget(db, *user, ui->stackedWidget);
            break;
        case User::STUDENT:
            widget = new StudentHomeWidget(ui->stackedWidget);
            break;
        default:
            break;
    }
    if (widget != NULL) {
        changeView(widget);
    }
}
