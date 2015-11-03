#ifndef ANSWER_H
#define ANSWER_H

#include <QString>

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
        const QString& getValue() const;

    private:
        int id;
        QString* value;
};

#endif // ANSWER_H
