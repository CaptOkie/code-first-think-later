#include "studenthomewidget.h"
#include "ui_studenthomewidget.h"

StudentHomeWidget::StudentHomeWidget(Storage& db, User* currUser, QWidget *parent)
    : QWidget(parent), ui(new Ui::StudentHomeWidget), db(db), currUser(currUser)
{
    ui->setupUi(this);
    ui->nameLabel->setText(currUser->getName());
    ui->numberLabel->setText(QString::number(currUser->getId()));

    loadProjects();
}

StudentHomeWidget::~StudentHomeWidget()
{
    delete ui;
    delete currUser;
}

void StudentHomeWidget::loadProjects() {
    QList<QString>* enrolled = 0;
    QList<QString>* available = 0;

//    db.getProjects(&enrolled, &available, currUser);
}
