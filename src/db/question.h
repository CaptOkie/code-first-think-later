#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QList>

#include "answer.h"
#include "response.h"

/**
 * @brief The Question class
 *
 * Stores information about the question.
 */
class Question
{
    public:
        /**
         * @brief Question Creates a new instance, which claims ownership of, and responsibility for deleting, pointers.
         * @param id The ID of the question.
         * @param personal The personal question.
         * @param desired The desired question.
         * @param category The category to which the question belongs.
         * @param answers The possible answers to the question.
         * @param responses The responses students have made to the question.
         */
        Question(int id, QString* personal, QString* desired, QString* category, QList<Answer>* answers, QList<Response>* responses);

        /**
         * @brief Question Creates a new instance.
         * @param id The ID of the question.
         * @param personal The personal question.
         * @param desired The desired question.
         * @param category The category to which the question belongs.
         * @param answers The possible answers to the question.
         * @param responses The responses students have made to the question.
         */
        Question(int id, const QString& personal, const QString& desired, const QString& category, QList<Answer>* answers, QList<Response>* responses);

        /**
         * @brief Question Creates a new instance.
         * @param copy The Question to copy.
         */
        Question(const Question& copy);

        ~Question();

        /**
         * @brief getId
         * @return The ID of the question.
         */
        int getId() const;

        /**
         * @brief getPersonal
         * @return The personal question.
         */
        const QString& getPersonal() const;

        /**
         * @brief getDesired
         * @return The desired question.
         */
        const QString& getDesired() const;

        /**
         * @brief getCategory
         * @return The category to which the question belongs.
         */
        const QString& getCategory() const;

        /**
         * @brief getAnswers
         * @return The possible answers to the question.
         */
        const QList<Answer>& getAnswers() const;

        /**
         * @brief getResponses
         * @return Student responses to the question.
         */
        const QList<Response>& getResponses() const;

    private:
        int id;                     // The ID of the question
        QString* personal;          // The personal question
        QString* desired;           // The desired question
        QString* category;          // The category the question belongs to
        QList<Answer>* answers;     // The possible answers to the question
        QList<Response>* responses; // Student responses to the question
};

#endif // QUESTION_H
