#include "profiledialog.h"
#include "ui_profiledialog.h"

#include "questionswidget.h"
#include "../db/question.h"

ProfileDialog::ProfileDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::ProfileDialog)
{
    ui->setupUi(this);
}

ProfileDialog::~ProfileDialog()
{
    delete ui;
}

void ProfileDialog::showProfile(const User& user)
{
    ui->tabWidget->clear();

    QList<Question>* questions = new QList<Question>();

    QList<Answer>* answers = new QList<Answer>();
    answers->append(Answer(1, "answer 1"));
    answers->append(Answer(2, "answer 2"));
    questions->append(Question(1, "Some hopefully really long personal question that may end up wrapping over more than a single line?",
                               "Some hopefully really long desired question that may end up wrapping over more than a single line?", "Long", answers));

    answers = new QList<Answer>();
    answers->append(Answer(1, "answer 1"));
    answers->append(Answer(2, "answer 2"));
    answers->append(Answer(2, "answer 3"));
    answers->append(Answer(2, "answer 4"));
    answers->append(Answer(2, "answer 5"));
    answers->append(Answer(2, "answer 6"));
    questions->append(Question(1, "Short personal?",
                               "Short desired?", "Short", answers));

    QMap<QString, QList<Question> > tabs;
    for (QList<Question>::const_iterator it = questions->begin(); it != questions->end(); ++it) {
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

    delete questions;
    show();
}
