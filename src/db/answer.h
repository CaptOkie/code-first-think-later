#ifndef ANSWER_H
#define ANSWER_H

#include <QString>

/**
 * @brief The Answer class
 *
 * Stores information about a possible answer to a question.
 */
class Answer
{
    public:
        /**
         * @brief Answer Creates a new instance, which claims ownership of, and responsibility for deleting, pointers.
         * @param id The ID of the Answer.
         * @param value The actual Answer.
         */
        Answer(int id, QString* value);

        /**
         * @brief Answer Creates a new instance.
         * @param id The ID of the Answer.
         * @param value The actual Answer.
         */
        Answer(int id, const QString& value);

        /**
         * @brief Answer
         * @param copy The Answer to copy.
         */
        Answer(const Answer& copy);

        ~Answer();

        /**
         * @brief getId
         * @return The ID of the Answer.
         */
        int getId() const;

        /**
         * @brief getValue
         * @return The actual answer.
         */
        const QString& getValue() const;

    private:
        int id;         // The ID
        QString* value; // The actual answer
};

#endif // ANSWER_H
