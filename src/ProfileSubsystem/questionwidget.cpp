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
    QVBoxLayout* text = new QVBoxLayout(this);
    text->addWidget(new QLabel(question.getText(), this));
    QHBoxLayout* answers = new QHBoxLayout(this);

    // Vertical line
    QFrame* line = new QFrame(this);
    line->setGeometry(QRect());
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);

    // Button grid
    QGridLayout* grid = new QGridLayout(this);
    grid->addWidget(new QLabel("Personal", this), 1, 0);
    grid->addWidget(new QLabel("Desired", this), 2, 0);

    QHBoxLayout* answerGroup = NULL;
    for (QMap<int, Answer*>::const_iterator it = question.getAnswers().cbegin(); it != question.getAnswers().cend(); ++it) {

        const Answer* answer = it.value();

        QLabel* label = new QLabel(QString::number(answer->getId()).append(". ").append(answer->getText()), this);
        if (answerGroup) {
            answerGroup->addWidget(label);
            answers->addLayout(answerGroup);
            answerGroup = NULL;
        }
        else {
            answerGroup = new QHBoxLayout(this);
            answerGroup->addWidget(label);
        }

        grid->addWidget(new QLabel(QString::number(answer->getId()), this), 0, answer->getId());

        QRadioButton* pr = new QRadioButton("", this);
        personal.addButton(pr, answer->getId());
        grid->addWidget(pr, 1, answer->getId());
        if (answer->getId() == question.getPersonal().getId()) {
            pr->setChecked(true);
        }

        QRadioButton* dr = new QRadioButton("", this);
        desired.addButton(dr, answer->getId());
        grid->addWidget(dr, 2, answer->getId());
        if (answer->getId() == question.getDesired().getId()) {
            dr->setChecked(true);
        }
    }

    // Adding items
    layout->addLayout(text);
    layout->addWidget(line);
    layout->addLayout(grid);

    setLayout(layout);
}

QuestionWidget::~QuestionWidget()
{ }
