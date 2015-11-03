#ifndef QUESTIONWIDGET_H
#define QUESTIONWIDGET_H

#include <QWidget>
#include <QButtonGroup>

#include "../db/question.h"

namespace Ui {
    class QuestionWidget;
}

/**
 * @brief The QuestionWidget class
 *
 * The widget for showing a single question.
 */
class QuestionWidget : public QWidget
{
        Q_OBJECT

    public:
        /**
         * @brief QuestionWidget Creates a new instance.
         * @param question The question to show.
         * @param parent The parent widget.
         */
        explicit QuestionWidget(const Question& question, QWidget *parent = 0);
        ~QuestionWidget();

    private:
        Ui::QuestionWidget *ui; // The UI
        QButtonGroup* personal; // The button group for the personal question
        QButtonGroup* desired;  // The button group for the desired question
};

#endif // QUESTIONWIDGET_H
