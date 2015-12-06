#include "questionswidget.h"
#include "ui_questionswidget.h"

#include <QVBoxLayout>
#include <QSpacerItem>
#include <QFrame>

QuestionsWidget::QuestionsWidget(QList<QuestionWidget*>& widgets, QWidget* parent)
    : QWidget(parent), ui(new Ui::QuestionsWidget)
{
    ui->setupUi(this);

    QVBoxLayout* layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    for (QList<QuestionWidget*>::iterator it = widgets.begin(); it != widgets.end(); ++it) {
        QuestionWidget* widget = *it;
        widget->setParent(this);
        layout->addWidget(widget);
        if (it != (widgets.end() - 1)) {
            QFrame* line = new QFrame(this);
            line->setGeometry(QRect());
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);
            layout->addWidget(line);
        }
    }

    layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    ui->scrollAreaWidgetContents->setLayout(layout);
}

QuestionsWidget::~QuestionsWidget()
{
    delete ui;
}
