#ifndef QUESTIONWIDGET_H
#define QUESTIONWIDGET_H

#include <QWidget>
#include <QButtonGroup>

#include "../db/question.h"
#include "../db/storage.h"

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
         * @param db The storage object.
         * @param question The question to show.
         * @param parent The parent widget.
         */
        explicit QuestionWidget(Storage& db, const Question& question, QWidget *parent = 0);
        ~QuestionWidget();

    public slots:
        void saveResponses();

    private:
        Ui::QuestionWidget *ui; // The UI
        Storage& db;            // The storage object for the database
        int question;           // The id of the question
        int student;            // The id of the student that is answering the questions
        QButtonGroup* personal; // The button group for the personal question
        QButtonGroup* desired;  // The button group for the desired question
};

#endif // QUESTIONWIDGET_H
