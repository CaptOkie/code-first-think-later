#include "profileform.h"
#include "ui_profileform.h"
#include "profilecontrol.h"
#include "StorageSubsystem/question.h"
#include "StorageSubsystem/student.h"
#include "questionswidget.h"
#include <QDesktopWidget>

ProfileForm::ProfileForm(ProfileControl& ctrl, const Student& student, QWidget *parent)
    : QDialog(parent), ui(new Ui::ProfileForm), ctrl(ctrl), data()
{
    ui->setupUi(this);
    ui->nameLabel->setText(student.getName());
}

ProfileForm::~ProfileForm()
{
    delete ui;
}

void ProfileForm::show(const QMap<int, Question*>& questions)
{
    data.clear();
    QMap<QString, QList<QuestionWidget*> > tabs;
    for (QMap<int, Question*>::const_iterator it = questions.cbegin(); it != questions.cend(); ++it) {

        Question* question = it.value();
        QuestionWidget* widget = new QuestionWidget(*question);
        tabs[question->getCategory()].append(widget);
        data.insert(question->getId(), widget);
    }

    ui->tabWidget->clear();
    for (QMap<QString, QList<QuestionWidget*> >::iterator it = tabs.begin(); it != tabs.end(); ++it) {
        ui->tabWidget->addTab(new QuestionsWidget(it.value(), ui->tabWidget), it.key());
    }

    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            size(),
            qApp->desktop()->availableGeometry()
        )
    );
    QDialog::show();
}
