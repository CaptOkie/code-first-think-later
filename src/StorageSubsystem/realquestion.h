#ifndef REALQUESTION_H
#define REALQUESTION_H

#include "question.h"

/**
 * @brief The RealQuestion class. The Question class that holds the state for the Question such as the the Answers
 *        and a Student's responses.
 */
class RealQuestion : public Question
{
    public:
        /**
         * @brief RealQuestion The constructor.
         * @param id The id of the Question.
         * @param text The text of the Question.
         * @param category The category of the Question.
         */
        RealQuestion(int id, QString* text, QString* category);
        RealQuestion(int id, const QString& text, const QString& category);
        ~RealQuestion();

    public:
        /**
         * @brief getId
         * @return Returns the id of the Question.
         */
        virtual int getId() const;
        /**
         * @brief getText
         * @return Retuns the text of the Question.
         */
        virtual const QString& getText() const;
        /**
         * @brief getCategory
         * @return Returns the category of the Question.
         */
        virtual const QString& getCategory() const;

        /**
         * @brief getAnswers
         * @return Returns the map of Answers indexed by their ids of the Question.
         */
        virtual const QMap<int, Answer*>& getAnswers() const;
        /**
         * @brief getPersonal
         * @return Returns a Student's personal Answer for the Question.
         */
        virtual const Answer& getPersonal() const;
        /**
         * @brief getDesired
         * @return Returns a Student's desired ANswer for the QUestion.
         */
        virtual const Answer& getDesired() const;

        /**
         * @brief setAnswers Sets the Answers of the Questions.
         * @param answers The Answers.
         */
        void setAnswers(QMap<int, Answer*>* answers);
        /**
         * @brief setResponse Sets the Student's response to a Question.
         * @param personal The id of the Personal Answer.
         * @param desired The id of the desired Answer.
         * @return Whether it was successful or not.
         */
        virtual bool setResponse(int personal, int desired);
        /**
         * @brief setResponse Sets the Student's response to a Question.
         * @param personal The Personal Answer.
         * @param desired The desired Answer.
         * @return Whether it was successful or not.
         */
        virtual bool setResponse(const Answer& personal, const Answer& desired);

    private:
        int id;
        QString* text;
        QString* category;
        QMap<int, Answer*>* answers;
        Answer* personal;
        Answer* desired;

    private:
        // Private functions to handle deleting pointers.
        void cleanResponse(Answer* answer);
        void deleteResponse(Answer* answer);
        void deleteAnswers(QMap<int, Answer*>* answers);
};

#endif // REALQUESTION_H
