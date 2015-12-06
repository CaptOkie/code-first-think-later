#ifndef QUESTIONSTORAGE_H
#define QUESTIONSTORAGE_H

#include <QtSql>
#include <QMap>

#include "question.h"
#include "answer.h"
#include "student.h"

/**
 * @brief The QuestionStorage class. Access information in the database pertaining to a specific question.
 *        Such as a Student's responses and a Question's Answers.
 */
class QuestionStorage
{
    public:
        /**
         * @brief QuestionStorage The constructor.
         * @param db The database connection.
         * @param student The Student that the retrieved responses will belong to.
         */
        QuestionStorage(QSqlDatabase& db, const Student& student);
        ~QuestionStorage();

        /**
         * @brief getAnswers
         * @param question The Question
         * @return A map of Answers indexed by their ids that belong to the Question.
         */
        QMap<int, Answer*>* getAnswers(const Question& question);
        /**
         * @brief getPersonalAnswer
         * @param question The Question
         * @return The id of the Student's personal Answer for the Question.
         */
        int getPersonalAnswer(const Question& question);
        /**
         * @brief getDesiredAnswer
         * @param question The Question.
         * @return The id of the Student's personal Answer for the Question.
         */
        int getDesiredAnswer(const Question& question);

        /**
         * @brief setResponse Set the response of the Student for a given Question.
         * @param question The Question.
         * @param personal The id of the personal Answer.
         * @param desired The id of the desired Answer.
         * @return Whether it was successful or not.
         */
        bool setResponse(const Question& question, int personal, int desired);
        /**
         * @brief setResponse Set the response of the Student for a given Question.
         * @param question The Question.
         * @param personal The personal Answer.
         * @param desired The desired Answer.
         * @return Whether it was successful or not.
         */
        bool setResponse(const Question& question, const Answer& personal, const Answer& desired);

    private:
        /**
         * @brief db The database connection.
         */
        QSqlDatabase& db;
        /**
         * @brief student The Student.
         */
        const Student& student;
};

#endif // QUESTIONSTORAGE_H
