#ifndef PERCENTDISTANCE_H
#define PERCENTDISTANCE_H

#include <QHash>
#include "matcher.h"

class PercentDistance : public Matcher
{
    public:
        PercentDistance();
        virtual ~PercentDistance();

        virtual int match(const Student& student, const Group& group);
        virtual int match(const Student& s1, const Student& s2);

    private:
        QHash<int, QHash<int, int> > cache;

        bool getCachedValue(int* value, const Student& s1, const Student& s2);
        int compute(const Student& s1, const Student& s2);
};

#endif // PERCENTDISTANCE_H
