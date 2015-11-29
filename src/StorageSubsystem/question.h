#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <list>

#include "answer.h"

class Question
{
public:
    Question();
    ~Question();

protected:
    int id;
    std::string personal;
    std::string desired;
    std::string category;

public:
    std::list<Answer> getAnswers();
    Answer getPersonalAnswer();
    Answer getDesiredAnswer();
    void setPersonal(Answer);
    void setDesired(Answer);
};

#endif // QUESTION_H
