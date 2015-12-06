#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QMap>

#include "answer.h"

/**
 * @brief The Question class. Abstract class for Question.
 */
class Question
{
    public:
        Question();
        virtual ~Question();

    public:
        /**
         * @brief getId
         * @return Returns the id of the Question.
         */
        virtual int getId() const = 0;
        /**
         * @brief getText
         * @return Retuns the text of the Question.
         */
        virtual const QString& getText() const = 0;
        /**
         * @brief getCategory
         * @return Returns the category of the Question.
         */
        virtual const QString& getCategory() const = 0;

        /**
         * @brief getAnswers
         * @return Returns the map of Answers indexed by their ids of the Question.
         */
        virtual const QMap<int, Answer*>& getAnswers() const = 0;
        /**
         * @brief getPersonal
         * @return Returns a Student's personal Answer for the Question.
         */
        virtual const Answer& getPersonal() const = 0;
        /**
         * @brief getDesired
         * @return Returns a Student's desired ANswer for the QUestion.
         */
        virtual const Answer& getDesired() const = 0;

        /**
         * @brief setResponse Sets the Student's response to a Question.
         * @param personal The id of the Personal Answer.
         * @param desired The id of the desired Answer.
         * @return Whether it was successful or not.
         */
        virtual bool setResponse(int personal, int desired) = 0;
        /**
         * @brief setResponse Sets the Student's response to a Question.
         * @param personal The Personal Answer.
         * @param desired The desired Answer.
         * @return Whether it was successful or not.
         */
        virtual bool setResponse(const Answer& personal, const Answer& desired) = 0;
};

#endif // QUESTION_H
