#include "splitsmallest.h"

SplitSmallest::SplitSmallest(Matcher* matcher)
    : Grouper(matcher)
{ }

SplitSmallest::~SplitSmallest()
{ }

QList<Group*>* SplitSmallest::group(const Project& project)
{
    QHash<Student*, Group*> stog;
    QHash<Student*, QHash<Group*, int> > matches;
    QList<Group*> full;
    QSet<Group*> remaining;

    initGroups(remaining, stog, project.getStudents());
    fillMatches(matches, remaining, project.getStudents());

    while (remaining.size() > 1) {

        Student* student = NULL;
        Group* group = NULL;
        worstMatch(&student, &group, matches, stog, remaining);

        Group* remove = stog.take(student);
        if (student && group && remove) {
            remove->getStudents().remove(student->getId());
            group->getStudents().insert(student->getId(), student);
            stog.insert(student, group);

            updateMatches(matches, remove, group);
            if (remove->getStudents().isEmpty()) {
                remaining.remove(remove);
                delete remove;
            }

            if (group->getStudents().size() >= project.getMaxGroupSize()) {
                remaining.remove(group);
                full.append(group);
            }
        }
        else {
            return NULL;
        }
    }

    QList<Group*>* ret = new QList<Group*>();
    ret->append(remaining.toList());
    ret->append(full);

    return ret;
}

void SplitSmallest::initGroups(QSet<Group*>& groups, QHash<Student*, Group*>& stog, const QMap<int, Student*>& students)
{
    for (QMap<int, Student*>::const_iterator it = students.cbegin(); it != students.cend(); ++it) {
        Student* student = it.value();
        Group* group = new Group();
        group->getStudents().insert(student->getId(), student);
        groups.insert(group);
        stog.insert(student, group);
    }
}

void SplitSmallest::fillMatches(QHash<Student*, QHash<Group*, int> >& matches, const QSet<Group*>& groups, const QMap<int, Student*>& students)
{
    for (QMap<int, Student*>::const_iterator it = students.cbegin(); it != students.cend(); ++it) {

        Student* student = it.value();
        for (QSet<Group*>::const_iterator git = groups.cbegin(); git != groups.cend(); ++git) {

            Group* group = *git;
            matches[student].insert(group, getMatcher().match(*student, *group));
        }
    }
}

void SplitSmallest::worstMatch(Student** student, Group** group, const QHash<Student*, QHash<Group*, int> >& matches, const QHash<Student*, Group*>& stog, const QSet<Group*>& remaining)
{
    (*student) = NULL;
    (*group) = NULL;

    int worst = 0;
    for (QHash<Student*, QHash<Group*, int> >::const_iterator sit = matches.cbegin(); sit != matches.cend(); ++sit) {

        Student* currStudent = sit.key();
        const Group* currStudentGroup = stog.value(currStudent, NULL);
        const QHash<Group*, int>& groups = sit.value();

        int best = 0;
        Group* bestGroup = NULL;

        for (QHash<Group*, int>::const_iterator git = groups.cbegin(); git != groups.cend(); ++git) {

            if (currStudentGroup && (currStudentGroup != git.key()) && remaining.contains(git.key())) {

                int currValue = git.value();

                Group* studentGroup = stog.value(*student, NULL);
                int currSize = currStudentGroup->getStudents().size();
                if (!(*student)
                        || (studentGroup && (currSize < studentGroup->getStudents().size()))
                        || ((studentGroup && (currSize == studentGroup->getStudents().size())) && (currValue < worst))) {
                    (*student) = currStudent;
                    worst = currValue;

                }

                Group* currGroup = git.key();
                if (!bestGroup || (currValue > best)) {
                    bestGroup = currGroup;
                    best = currValue;
                }
            }
        }

        if ((*student) == currStudent) {
            (*group) = bestGroup;
        }
    }
}

void SplitSmallest::updateMatches(QHash<Student*, QHash<Group*, int> >& matches, Group* first, Group* second)
{
    for (QHash<Student*, QHash<Group*, int> >::iterator it = matches.begin(); it != matches.end(); ++it) {

        Student* student = it.key();
        QHash<Group*, int>& values = it.value();
        if (student) {
            updateMatches(values, first, *student);
            updateMatches(values, second, *student);
        }
    }
}

void SplitSmallest::updateMatches(QHash<Group*, int>& values, Group* group, const Student& student)
{
    if (group) {
        if (group->getStudents().isEmpty()) {
            values.take(group);
        }
        else {
            values.insert(group, getMatcher().match(student, *group));
        }
    }
}
