#include "question.h"

Question::Question(int id, QString* personal, QString* desired, QString* category)
    : id(id), personal(personal), desired(desired), category(category)
{ }

Question::~Question()
{ }

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
