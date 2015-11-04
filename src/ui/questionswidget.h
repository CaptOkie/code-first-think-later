#ifndef QUESTIONSWIDGET_H
#define QUESTIONSWIDGET_H

#include <QWidget>

#include "../db/question.h"
#include "../db/storage.h"

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
        explicit QuestionsWidget(Storage& db, const QList<Question>& questions, QWidget *parent = 0);
        ~QuestionsWidget();

    signals:
        void saveResponses();

    public slots:
        void save();

    private:
        Ui::QuestionsWidget *ui; // The UI
};

#endif // QUESTIONSWIDGET_H
