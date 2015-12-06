#ifndef QUESTIONSWIDGET_H
#define QUESTIONSWIDGET_H

#include <QWidget>
#include "questionwidget.h"

namespace Ui {
    class QuestionsWidget;
}

class QuestionsWidget : public QWidget
{
    Q_OBJECT

    public:
        explicit QuestionsWidget(QList<QuestionWidget*>& widgets, QWidget* parent = 0);
        ~QuestionsWidget();

    private:
        Ui::QuestionsWidget *ui;
};

#endif // QUESTIONSWIDGET_H
