#include "questionwidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QRadioButton>
#include <QLabel>
#include <QFrame>

QuestionWidget::QuestionWidget(const Question& question, QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout(this);

    // The question and answer text
    QVBoxLayout* text = new QVBoxLayout();
    QLabel* qLabel = new QLabel(question.getText(), this);
    QFont f(qLabel->font());
    f.setBold(true);
    qLabel->setFont(f);
    text->addWidget(qLabel);
    QHBoxLayout* answers = new QHBoxLayout();

    // Vertical line
    QFrame* line = new QFrame(this);
    line->setGeometry(QRect());
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);

    // Button grid
    QGridLayout* grid = new QGridLayout();
    QLabel* pLabel = new QLabel("Personal", this);
    pLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QLabel* dLabel = new QLabel("Desired", this);
    dLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    grid->addWidget(pLabel, 1, 0);
    grid->addWidget(dLabel, 2, 0);

    QVBoxLayout* answerGroup = NULL;
    for (QMap<int, Answer*>::const_iterator it = question.getAnswers().cbegin(); it != question.getAnswers().cend(); ++it) {

        const Answer* answer = it.value();

        QLabel* alabel = new QLabel(QString::number(answer->getId()).append(". ").append(answer->getText()), this);
        alabel->setAlignment(Qt::AlignTop);
        if (answerGroup) {
            answerGroup->addWidget(alabel);
            answers->addLayout(answerGroup);
            answerGroup = NULL;
        }
        else {
            answerGroup = new QVBoxLayout();
            answerGroup->addWidget(alabel);
        }

        QLabel* numLabel = new QLabel(QString::number(answer->getId()), this);
        numLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        numLabel->setAlignment(Qt::AlignHCenter);
        grid->addWidget(numLabel, 0, answer->getId());

        QRadioButton* pr = new QRadioButton("", this);
        pr->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        personal.addButton(pr, answer->getId());
        grid->addWidget(pr, 1, answer->getId());
        if (answer->getId() == question.getPersonal().getId()) {
            pr->setChecked(true);
        }

        QRadioButton* dr = new QRadioButton("", this);
        dr->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        desired.addButton(dr, answer->getId());
        grid->addWidget(dr, 2, answer->getId());
        if (answer->getId() == question.getDesired().getId()) {
            dr->setChecked(true);
        }
    }
    if (answerGroup) {
        answers->addLayout(answerGroup);
    }

    // Adding items
    text->addLayout(answers);
    layout->addLayout(text);
    layout->addWidget(line);
    layout->addLayout(grid);

    setLayout(layout);
}

QuestionWidget::~QuestionWidget()
{ }
