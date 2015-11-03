#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(Storage& db, QWidget *parent)
    : QWidget(parent), ui(new Ui::LoginWidget), db(db)
{
    ui->setupUi(this);
    ui->idInput->setValidator(new QRegExpValidator(QRegExp("\\d+"), ui->idInput));

    connect(ui->idInput, &QLineEdit::returnPressed, ui->loginBtn, &QPushButton::click);
    connect(ui->loginBtn, &QPushButton::clicked, this, &LoginWidget::attemptLogin);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::attemptLogin()
{
    QString input = ui->idInput->text();
    User* user = 0;
    if(db.validUser(input, &user)) {
        emit loggedIn(user);
    }
}
