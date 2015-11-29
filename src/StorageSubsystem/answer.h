#ifndef ANSWER_H
#define ANSWER_H

#include <QString>

class Answer
{
    public:
        Answer();
        ~Answer();

        int getId() const;
        const QString& getText() const;

    private:
        int id;
        QString* text;
};

#endif // ANSWER_H
