#ifndef SPLITSMALLEST_H
#define SPLITSMALLEST_H

#include "grouper.h"
#include "StorageSubsystem/project.h"
#include "StorageSubsystem/student.h"
#include <QHash>

class SplitSmallest : public Grouper
{
    public:
        SplitSmallest(Matcher* matcher);
        virtual ~SplitSmallest();

        virtual QList<Group*>* group(const Project& project);

    private:
        void initGroups(QMultiMap<int, Group *>& groups, QHash<int, Group *>& stog, const Project& project);
        void collectMatches(QHash<int, QMultiMap<int, Group*> >& matches, const QMultiMap<int, Group*>& groups);
        Student* bestStudent(int* match, const Group& from, const Group& to);
};

#endif // SPLITSMALLEST_H
