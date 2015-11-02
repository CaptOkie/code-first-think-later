#include "answer.h"

Answer::Answer(int id, QString* value)
    : id(id), value(value)
{ }

Answer::Answer(int id, const QString& value)
    : id(id), value(new QString(value))
{ }

Answer::Answer(const Answer& copy)
    : id(copy.getId()), value(new QString(copy.getValue()))
{ }

Answer::~Answer()
{
    delete value;
}

int Answer::getId() const
{
    return id;
}

const QString& Answer::getValue() const
{
    return *value;
}
