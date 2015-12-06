#include "answer.h"

Answer::Answer(int id, QString* text)
    : id(id), text(text)
{ }

Answer::Answer(int id, const QString& text)
    : id(id), text(new QString(text))
{ }

Answer::Answer(const Answer& other)
    : id(other.getId()), text(new QString(other.getText()))
{ }

Answer::Answer()
    : id(-1), text(new QString(""))
{ }

Answer::~Answer()
{
    if (text)
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
