#ifndef QUESTIONSWIDGET_H
#define QUESTIONSWIDGET_H

#include <QWidget>

#include "../db/question.h"

namespace Ui {
    class QuestionsWidget;
}

/**
 * @brief The QuestionsWidget class
 *
 * The widget for showing a group of questions.
 */
class QuestionsWidget : public QWidget
{
        Q_OBJECT

    public:
        /**
         * @brief QuestionsWidget Creates a new instance.
         * @param questions The questions to show.
         * @param parent The parent widget.
         */
        explicit QuestionsWidget(const QList<Question>& questions, QWidget *parent = 0);
        ~QuestionsWidget();

    private:
        Ui::QuestionsWidget *ui; // The UI
};

#endif // QUESTIONSWIDGET_H
