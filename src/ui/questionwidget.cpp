#include "questionwidget.h"
#include "ui_questionwidget.h"

#include <QRadioButton>

QuestionWidget::QuestionWidget(const Question& question, QWidget *parent)
    : QWidget(parent), ui(new Ui::QuestionWidget), personal(new QButtonGroup(this)), desired(new QButtonGroup(this))
{
    ui->setupUi(this);

    ui->personalLabel->setText(question.getPersonal());
    ui->desiredLabel->setText(question.getDesired());

    QList<Answer>::const_iterator it;
    for (it = question.getAnswers().begin(); it != question.getAnswers().end(); ++it) {
        const Answer& answer = *it;

        QRadioButton* pBtn = new QRadioButton(answer.getValue(), this);
        ui->personalHLayout->addWidget(pBtn);
        personal->addButton(pBtn, answer.getId());

        QRadioButton* dBtn = new QRadioButton(answer.getValue(), this);
        ui->desiredHLayout->addWidget(dBtn);
        desired->addButton(dBtn, answer.getId());
    }
}

QuestionWidget::~QuestionWidget()
{
    delete ui;
    personal->deleteLater();
    desired->deleteLater();
}
