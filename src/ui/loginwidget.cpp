#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::LoginWidget), idRegex(QRegExp("\\d+"))
{
    ui->setupUi(this);
    ui->idInput->setValidator(new QRegExpValidator(idRegex, ui->idInput));

    connect(ui->loginBtn, &QPushButton::clicked, this, &LoginWidget::handleLoginBtn);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::handleLoginBtn()
{
    emit loggedIn(ADMIN);
}
