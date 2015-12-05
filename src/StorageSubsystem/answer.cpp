#include "answer.h"

Answer::Answer(int id, QString* text)
    : id(id), text(text)
{ }

Answer::Answer(int id, const QString &text)
    : id(id), text(new QString(text))
{ }

Answer::Answer(Answer& other)
    : id(other.getId()), text(new QString(other.getText()))
{ }

Answer::~Answer()
{
    delete text;
}

int Answer::getId() const
{
    return id;
}

const QString& Answer::getText() const
{
    return *text;
}
