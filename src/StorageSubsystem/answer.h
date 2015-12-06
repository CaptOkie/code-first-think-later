#ifndef ANSWER_H
#define ANSWER_H

#include <QString>

/**
 * @brief The Answer class. An answer to a Question.
 */
class Answer
{
    public:
        /**
         * @brief Answer The constructor.
         * @param id THe id of the Answer.
         * @param text The text of the Answer.
         */
        Answer(int id, QString* text);
        Answer(int id, const QString& text);
        Answer(const Answer &other);
        Answer();
        ~Answer();

        /**
         * @brief getId
         * @return The id of the Answer
         */
        int getId() const;
        /**
         * @brief getText
         * @return The text of the Answer.
         */
        const QString& getText() const;

    private:
        /**
         * @brief id Answer id.
         */
        int id;
        /**
         * @brief text The text of the Answer.
         */
        QString* text;
};

#endif // ANSWER_H
