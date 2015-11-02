#ifndef ANSWER_H
#define ANSWER_H

#include <QString>

class Answer
{
    public:
        Answer(int, QString*);
        Answer(int, const QString&);
        Answer(const Answer&);
        ~Answer();

        int getId() const;
        const QString& getValue() const;

    private:
        int id;
        QString* value;
};

#endif // ANSWER_H
