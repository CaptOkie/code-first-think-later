#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

QMetaObject::Connection LoginWidget::setStudentBtnHandler(const char *signal, const char *slot, const QObject *receiver)
{
    return connect(ui->studentBtn, signal, receiver, slot);
}

QMetaObject::Connection LoginWidget::setAdminBtnHandler(const char *signal, const char *slot, const QObject *receiver)
{
    return connect(ui->adminBtn, signal, receiver, slot);
}
