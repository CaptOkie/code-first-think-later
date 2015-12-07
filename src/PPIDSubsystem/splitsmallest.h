#ifndef SPLITSMALLEST_H
#define SPLITSMALLEST_H

#include "grouper.h"
#include "StorageSubsystem/project.h"
#include "StorageSubsystem/student.h"
#include <QMap>
#include <QHash>
#include <QSet>

class SplitSmallest : public Grouper
{
    public:
        SplitSmallest(Matcher* matcher);
        virtual ~SplitSmallest();

        virtual QList<Group*>* group(const Project& project);

    private:
        void initGroups(QSet<Group*>& groups, QHash<Student*, Group*>& stog, const QMap<int, Student*>& students);
        void fillMatches(QHash<Student*, QHash<Group*, int> >& matches, const QSet<Group*>& groups, const QMap<int, Student*>& students);
        void worstMatch(Student** student, Group** group, const QHash<Student*, QHash<Group*, int> >& matches, const QHash<Student*, Group*>& stog, const QSet<Group*>& remaining);
        void updateMatches(QHash<Student*, QHash<Group*, int> >& matches, Group* first, Group* second);
        void updateMatches(QHash<Group*, int>& values, Group* group, const Student& student);
        Student* bestMatch(Group* to, const QHash<Student*, QHash<Group*, int> >& matches, const QHash<Student*, Group*>& stog);
};

#endif // SPLITSMALLEST_H
