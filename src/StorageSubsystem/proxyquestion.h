#ifndef PROXYQUESTION_H
#define PROXYQUESTION_H

#include "question.h"
#include "realquestion.h"
#include "questionstorage.h"
#include "indicator.h"

/**
 * @brief The ProxyQuestion class. The Question class which manages loading from the storage.
 *        Inherits from Question.
 */
class ProxyQuestion : public Question
{
    public:
        /**
         * @brief ProxyQuestion The constructor.
         * @param id The id of the Question in storage.
         * @param text The text of the question.
         * @param category The category.
         * @param storage The storage that is communicated with.
         */
        ProxyQuestion(int id, QString* text, QString* category, QuestionStorage* storage);
        ~ProxyQuestion();

    public:
        /**
         * @brief getId
         * @return The id.
         */
        virtual int getId() const;
        /**
         * @brief getText
         * @return The text of the question.
         */
        virtual const QString& getText() const;
        /**
         * @brief getCategory
         * @return The category of the Question.
         */
        virtual const QString& getCategory() const;

        /**
         * @brief getAnswers
         * @return A map of Answers indexed by their ids that belong to the Question.
         */
        virtual const QMap<int, Answer*>& getAnswers() const;
        /**
         * @brief getPersonal
         * @return A Student's personal answer to the Question.
         */
        virtual const Answer& getPersonal() const;
        /**
         * @brief getDesired
         * @return A Student's desired answer in partner to the Question.
         */
        virtual const Answer& getDesired() const;

        /**
         * @brief setResponse Sets a Student's response to a Question. Includes personal and desired answers.
         * @param personal The id of the personal Answer.
         * @param desired The id of the desired Answer.
         * @return Whether is was successful or not.
         */
        virtual bool setResponse(int personal, int desired);
        /**
         * @brief setResponse Sets a Student's response to a Question. Includes personal and desired answers.
         * @param personal The personal Answer.
         * @param desired The desired Answer.
         * @return  Whether it was successful or not.
         */
        virtual bool setResponse(const Answer& personal, const Answer& desired);

    private:
        /**
         * @brief hasAnswers Indicating whether the Answers have been loaded from Storage.
         */
        Indicator* hasAnswers;
        /**
         * @brief hasResponse Indicating whether a Question has a Student's response.
         */
        Indicator* hasResponse;
        /**
         * @brief realQuestion The Question object holding the state.
         */
        RealQuestion* realQuestion;
        /**
         * @brief storage The storage being communicated with.
         */
        QuestionStorage* storage;

    private:
        /**
         * @brief loadAnswers Loads the Answers from the storage.
         */
        void loadAnswers() const;
};

#endif // PROXYQUESTION_H
