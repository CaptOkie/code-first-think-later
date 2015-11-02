#include "studenthomewidget.h"
#include "ui_studenthomewidget.h"

StudentHomeWidget::StudentHomeWidget(Storage& db, User* currUser, QWidget *parent)
    : QWidget(parent), ui(new Ui::StudentHomeWidget), db(db), currUser(currUser), profileDialog(this)
{
    ui->setupUi(this);
    ui->nameLabel->setText(currUser->getName());
    ui->numberLabel->setText(QString::number(currUser->getId()));
    loadProjects();

    connect(ui->joinBtn, &QPushButton::clicked, this, &StudentHomeWidget::joinProject);
    connect(ui->leaveBtn, &QPushButton::clicked, this, &StudentHomeWidget::leaveProject);
    connect(ui->editProfileBtn, &QPushButton::clicked, this, &StudentHomeWidget::showProfile);
}

StudentHomeWidget::~StudentHomeWidget()
{
    delete ui;
    delete currUser;
}

void StudentHomeWidget::joinProject()
{
    QString project = ui->availableTreeWidget->currentItem()->text(0);
    db.enrollStudent(project, currUser->getId());
    loadProjects();
}

void StudentHomeWidget::leaveProject()
{
    QString project = ui->enrolledTreeWidget->currentItem()->text(0);
    db.unenrollStudent(project, currUser->getId());
    loadProjects();
}

void StudentHomeWidget::loadProjects()
{
    ui->availableTreeWidget->clear();
    ui->enrolledTreeWidget->clear();

    QList<QString>* enrolled = 0;
    QList<QString>* available = 0;

    db.getProjects(&enrolled, &available, *currUser);
    QList<QString>::const_iterator it;
    for(it = enrolled->begin(); it != enrolled->end(); ++it) {
        new QTreeWidgetItem(ui->enrolledTreeWidget, QStringList(*it));
    }

    for(it = available->begin(); it != available->end(); ++it) {
        new QTreeWidgetItem(ui->availableTreeWidget, QStringList(*it));
    }

    delete enrolled;
    delete available;
}

void StudentHomeWidget::showProfile()
{
    profileDialog.showProfile(*currUser);
}
