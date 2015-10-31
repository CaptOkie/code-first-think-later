#include "adminhomewidget.h"
#include "ui_adminhomewidget.h"

AdminHomeWidget::AdminHomeWidget(Storage& db, User* currUser, QWidget *parent)
    : QWidget(parent), ui(new Ui::AdminHomeWidget), detailsDialog(this),
      db(db), currUser(currUser)
{
    ui->setupUi(this);
    ui->nameLabel->setText(currUser->getName());
    ui->numberLabel->setText(QString::number(currUser->getId()));

    connect(ui->newBtn, &QPushButton::clicked, &detailsDialog, &QDialog::show);
}

AdminHomeWidget::~AdminHomeWidget()
{
    delete ui;
    delete currUser;
}
