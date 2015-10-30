#include "loginwidget.h"
#include "ui_loginwidget.h"

#include <QDebug>

LoginWidget::LoginWidget(Storage* db, QWidget *parent)
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
    if(db->validUser(atoi(ui->idInput->text().toStdString().c_str()), &type)) {
        qDebug() << type;
        emit loggedIn(type);
    }
}
