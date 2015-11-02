#include "questionswidget.h"
#include "ui_questionswidget.h"

#include <QVBoxLayout>
#include <QSpacerItem>

#include "questionwidget.h"

QuestionsWidget::QuestionsWidget(const QList<Question>& questions, QWidget *parent)
    : QWidget(parent), ui(new Ui::QuestionsWidget)
{
    ui->setupUi(this);

    QVBoxLayout* layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    QList<Question>::const_iterator it;
    for (it = questions.begin(); it != questions.end(); ++it) {
        layout->addWidget(new QuestionWidget(*it, this));
    }
    layout->addSpacerItem(new QSpacerItem(0,0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    ui->scrollAreaWidgetContents->setLayout(layout);
}

QuestionsWidget::~QuestionsWidget()
{
    delete ui;
}
