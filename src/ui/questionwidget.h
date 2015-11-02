#ifndef QUESTIONWIDGET_H
#define QUESTIONWIDGET_H

#include <QWidget>
#include <QButtonGroup>

#include "../db/question.h"

namespace Ui {
    class QuestionWidget;
}

class QuestionWidget : public QWidget
{
        Q_OBJECT

    public:
        explicit QuestionWidget(const Question& question, QWidget *parent = 0);
        ~QuestionWidget();

    private:
        Ui::QuestionWidget *ui;
        QButtonGroup* personal;
        QButtonGroup* desired;
};

#endif // QUESTIONWIDGET_H
