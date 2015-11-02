#include "question.h"

Question::Question(int id, QString* personal, QString* desired, QString* category, QList<Answer>* answers)
    : id(id), personal(personal), desired(desired), category(category), answers(answers)
{ }

Question::Question(int id, const QString& personal, const QString& desired, const QString& category, QList<Answer>* answers)
    : id(id), personal(new QString(personal)), desired(new QString(desired)), category(new QString(category)), answers(answers)
{ }

Question::Question(const Question& copy)
    : id(copy.getId()), personal(new QString(copy.getPersonal())), desired(new QString(copy.getDesired())),
      category(new QString(copy.getCategory())), answers(new QList<Answer>(copy.getAnswers()))
{ }

Question::~Question()
{
    delete personal;
    delete desired;
    delete category;
    delete answers;
}

int Question::getId() const
{
    return id;
}

const QString& Question::getPersonal() const
{
    return *personal;
}

const QString& Question::getDesired() const
{
    return *desired;
}

const QString& Question::getCategory() const
{
    return *category;
}

const QList<Answer>& Question::getAnswers() const
{
    return *answers;
}

