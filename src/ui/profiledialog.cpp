#include "profiledialog.h"
#include "ui_profiledialog.h"

#include "questionswidget.h"
#include "../db/question.h"

ProfileDialog::ProfileDialog(const User& user, Storage& db, QWidget *parent)
    : QDialog(parent), ui(new Ui::ProfileDialog), user(user), db(db)
{
    ui->setupUi(this);

}

ProfileDialog::~ProfileDialog()
{
    delete ui;
}

void ProfileDialog::showProfile()
{
    ui->tabWidget->clear();

    QList<Question> questions;
    db.getResponses(questions, user.getId());

    QMap<QString, QList<Question> > tabs;
    for (QList<Question>::const_iterator it = questions.begin(); it != questions.end(); ++it) {
        const Question& question = *it;
        QString category = question.getCategory().toLower();
        if (!tabs.contains(category)) {
            tabs.insert(category, QList<Question>());
        }
        tabs[category].append(question);
    }

    for (QMap<QString, QList<Question> >::const_iterator it = tabs.begin(); it != tabs.end(); ++it) {
        ui->tabWidget->addTab(new QuestionsWidget(*it), (*it).first().getCategory());
    }

    show();
}
