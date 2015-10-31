#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(Storage& db, QWidget *parent)
    : QWidget(parent), ui(new Ui::LoginWidget), idRegex(QRegExp("\\d+")), db(db)
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
    UserType type;
    QString input = ui->idInput->text();
    if(db.validUser(input, &type)) {
        emit loggedIn(type);
    }
}
