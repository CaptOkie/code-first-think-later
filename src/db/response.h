#ifndef RESPONSE_H
#define RESPONSE_H

#include "question.h"

class Response
{
    public:
        Response(int, int, Question*);
        Response(int, int, const Question&);
        Response(const Response&);
        ~Response();

        int getPersonal() const;
        int getDesired() const;
        const Question& getQuestion() const;

    private:
        int personal;
        int desired;
        Question* question;
};

#endif // RESPONSE_H
