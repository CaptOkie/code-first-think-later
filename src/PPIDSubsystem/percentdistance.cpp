#include "percentdistance.h"

PercentDistance::PercentDistance()
    : cache()
{ }

PercentDistance::~PercentDistance()
{ }

int PercentDistance::match(const Student& student, const Group& group)
{
    const QMap<int, Student*>& students = group.getStudents();

    int count = 0;
    int total = 0;
    QMap<int, Student*>::const_iterator it;
    for (it = students.constBegin(); it != students.constEnd(); ++it) {
        total += match(student, **it);
        count += 1;
    }

    return (total / count);
}

int PercentDistance::match(const Student& s1, const Student& s2)
{
    int value;
    if (!getCachedValue(&value, s1, s2) && !getCachedValue(&value, s2, s1)) {
        value = compute(s1, s2);
    }
    return value;
}

bool PercentDistance::getCachedValue(int* value, const Student& s1, const Student& s2)
{
    QHash<int, QHash<int, int> >::const_iterator outside = cache.find(s1.getId());
    if (outside == cache.constEnd()) {
        return false;
    }

    QHash<int, int>::const_iterator inside = outside->find(s2.getId());
    if (inside == outside->constEnd()) {
        return false;
    }

    (*value) = inside.value();
    return true;
}

void PercentDistance::setCachedValue(int value, const Student& s1, const Student& s2)
{
    cache[s1.getId()].insert(s2.getId(), value);
    cache[s2.getId()].insert(s1.getId(), value);
}

int PercentDistance::compute(const Student& s1, const Student& s2)
{
    const QMap<int, Question*>& q1 = s1.getQuestions();
    const QMap<int, Question*>& q2 = s2.getQuestions();

    QMap<int, Question*>::const_iterator it1;
    QMap<int, Question*>::const_iterator it2;

    int total = 0;
    int count = 0;
    for (it1 = q1.constBegin(); it1 != q1.constEnd(); ++it1) {

        it2 = q2.find(it1.key());
        if ((it2 != q2.constEnd()) && !((*it1)->getAnswers().empty())) {
            const int& min = (*it1)->getAnswers().firstKey();
            const int& max = (*it1)->getAnswers().lastKey();

            total += distance(min, max, (*it1)->getPersonalAnswer(), (*it2)->getDesiredAnswer());
            total += distance(min, max, (*it1)->getDesiredAnswer(), (*it2)->getPersonalAnswer());
            count += 2;
        }
    }

    return (total / count);
}

int PercentDistance::distance(int min, int max, const Answer& a1, const Answer& a2)
{
    return 100 - ((100 / ((max - min) + 1)) * qAbs(a1.getId() - a2.getId()));
}
