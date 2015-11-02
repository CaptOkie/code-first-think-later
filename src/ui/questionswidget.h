#ifndef QUESTIONSWIDGET_H
#define QUESTIONSWIDGET_H

#include <QWidget>

#include "../db/question.h"

namespace Ui {
    class QuestionsWidget;
}

class QuestionsWidget : public QWidget
{
        Q_OBJECT

    public:
        explicit QuestionsWidget(const QList<Question>&, QWidget *parent = 0);
        ~QuestionsWidget();

    private:
        Ui::QuestionsWidget *ui;
};

#endif // QUESTIONSWIDGET_H
