#ifndef GROUPER_H
#define GROUPER_H

#include <QList>
#include <QMap>
#include "StorageSubsystem/group.h"
#include "StorageSubsystem/student.h"
#include "matcher.h"

class Grouper
{
    public:
        Grouper(Matcher* matcher);
        virtual ~Grouper();

        virtual QList<Group*>* group(const Project& project) = 0;

    protected:
        Matcher* matcher;
};

#endif // GROUPER_H
