#include "questionwidget.h"
#include "ui_questionwidget.h"

#include <QRadioButton>

QuestionWidget::QuestionWidget(Storage& db, const Question& question, QWidget *parent)
    : QWidget(parent), ui(new Ui::QuestionWidget), db(db), question(question.getId()),
      student(question.getResponses().first().getStudent()),
      personal(new QButtonGroup(this)), desired(new QButtonGroup(this))
{
    ui->setupUi(this);

    ui->title->setText("Question #" + QString::number(question.getId()));
    ui->personalLabel->setText(question.getPersonal());
    ui->desiredLabel->setText(question.getDesired());

    int pResp = question.getResponses().first().getPersonal();
    int dResp = question.getResponses().first().getDesired();

    QList<Answer>::const_iterator it;
    for (it = question.getAnswers().begin(); it != question.getAnswers().end(); ++it) {
        const Answer& answer = *it;

        QRadioButton* pBtn = new QRadioButton(answer.getValue(), this);
        if (answer.getId() == pResp) {
            pBtn->setChecked(true);
        }
        ui->personalLayout->addWidget(pBtn);
        personal->addButton(pBtn, answer.getId());

        QRadioButton* dBtn = new QRadioButton(answer.getValue(), this);
        if (answer.getId() == dResp) {
            dBtn->setChecked(true);
        }
        ui->desiredLayout->addWidget(dBtn);
        desired->addButton(dBtn, answer.getId());
    }
}

QuestionWidget::~QuestionWidget()
{
    delete ui;
    personal->deleteLater();
    desired->deleteLater();
}

void QuestionWidget::saveResponses() {
    db.updateResponse(Response(student, question, personal->checkedId(), desired->checkedId()));
}
