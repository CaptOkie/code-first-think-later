#ifndef MATCHER_H
#define MATCHER_H

#include "StorageSubsystem/student.h"
#include "StorageSubsystem/group.h"

class Matcher
{
    public:
        Matcher();
        virtual ~Matcher();

        virtual int match(const Student& student, const Group& group) = 0;
        virtual int match(const Student& s1, const Student& s2) = 0;
};

#endif // MATCHER_H
