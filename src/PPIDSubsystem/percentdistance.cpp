#include "percentdistance.h"

PercentDistance::PercentDistance()
    : cache()
{ }

PercentDistance::~PercentDistance()
{ }

int PercentDistance::match(const Student& student, const Group& group)
{

}

int PercentDistance::match(const Student& s1, const Student& s2)
{
    int value;
    if (getCachedValue(&value, s1, s2)) {
        return value;
    }
    if (getCachedValue(&value, s2, s1)) {
        return value;
    }

    return compute(s1, s2);
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

int PercentDistance::compute(const Student& s1, const Student& s2)
{
    const QMap<int, Question*>& q1 = s1.getQuestions();
    const QMap<int, Question*>& q2 = s2.getQuestions();

    QMap<int, Question*>::const_iterator it1 = q1.constBegin();
    QMap<int, Question*>::const_iterator it2 = q2.constBegin();




    return 0;
}
