#include "profilecontrol.h"

ProfileControl::ProfileControl(Student& student)
    : profileForm(*this, student), student(student)
{ }

ProfileControl::~ProfileControl()
{ }

void ProfileControl::start()
{
    profileForm.show(student.getQuestions());
}

void ProfileControl::save(const QList<Response>& responses)
{
    const QMap<int, Question*> questions = student.getQuestions();
    for (QList<Response>::const_iterator it = responses.cbegin(); it != responses.cend(); ++it) {

        const Response& response = *it;
        Question* question = questions.value(response.getQuestion(), NULL);
        if (question) {

        }
    }
}
