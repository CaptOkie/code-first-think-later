#include "splitsmallest.h"

SplitSmallest::SplitSmallest(Matcher* matcher)
    : Grouper(matcher)
{ }

SplitSmallest::~SplitSmallest()
{ }

QList<Group*>* SplitSmallest::group(const Project& project)
{
    QHash<int, Group*> stog;
    QMultiMap<int, Group*> groups;
    initGroups(groups, stog, project);

    QList<Group*> full;
    // START Grouping
    while (groups.size() > 1) {

        QHash<int, QMultiMap<int, Group*> > matches;
        collectMatches(matches, groups);

        int student = 0;
        int lowest = 0;
        Group* group = NULL;
        for (QHash<int, QMultiMap<int, Group*> >::const_iterator it = matches.cbegin(); it != matches.cend(); ++it) {

            int nextStudent = it.key();
            int nextLowest = it.value().firstKey();
            Group* nextGroup = it.value().last();
            if (!group || nextLowest < lowest) {
                student = nextStudent;
                lowest = nextLowest;
                group = nextGroup;
            }
        }

        Group* remove = stog.take(student);
        if (group && remove) {

            QMap<int, Group*>::iterator git = groups.begin();
            while (git != groups.end()) {

                if (git.value() == group || git.value() == remove) {
                    git = groups.erase(git);
                }
                else {
                    ++git;
                }
            }

            Student* sptr = remove->getStudents().take(student);
            if (sptr) {

                group->getStudents().insert(sptr->getId(), sptr);
                stog.insert(sptr->getId(), group);

                if (group->getStudents().size() < project.getMaxGroupSize()) {
                    groups.insert(group->getStudents().size(), group);
                }
                else {
                    full.append(group);
                }

                if (remove->getStudents().isEmpty()) {
                    delete remove;
                }
                else {
                    groups.insert(remove->getStudents().size(), remove);
                }
            }
        }
    }
    // END Grouping

    // START Balancing
    if ((full.size() > 0) && (groups.size() > 0) && (groups.first()->getStudents().size() < project.getMinGroupSize())) {

        Group* toBalance = groups.first();
        groups.clear();
        for (QList<Group*>::const_iterator it = full.cbegin(); it != full.cend(); ++it) {
            groups.insert((*it)->getStudents().size(), (*it));
        }
        full.clear();

        while (toBalance->getStudents().size() < project.getMinGroupSize() && toBalance->getStudents().size() < (groups.lastKey() - 1)) {
            Group* from = NULL;
            Student* best = NULL;
            int match = 0;

            QMap<int, Group*>::iterator it = groups.end();
            while (it != groups.begin()) {
                --it;

                if (from) { // TODO: Look at bestStudent() and try to refactor
                    if (it.key() >= from->getStudents().size()) {
                        Group* nextGroup = it.value();
                        int nextMatch = 0;
                        Student* nextStudent = bestStudent(&nextMatch, *nextGroup, *toBalance);

                        if (nextMatch > match) {
                            match = nextMatch;
                            best = nextStudent;

                            groups.insert(groups.cend(), from->getStudents().size(), from);
                            from = nextGroup;
                            it = groups.erase(it);
                        }
                    }
                    else {
                        break;
                    }
                }
                else {
                    from = it.value();
                    it = groups.erase(it);
                    best = bestStudent(&match, *from, *toBalance);
                }
            }

            if (from && best) {
                from->getStudents().remove(best->getId());
                groups.insert(from->getStudents().size(), from);
                toBalance->getStudents().insert(best->getId(), best);
            }
        }
        groups.insert(toBalance->getStudents().size(), toBalance);
    }
    // END Balancing

    QList<Group*>* ret = new QList<Group*>();
    ret->append(full);
    ret->append(groups.values());

    return ret;
}

void SplitSmallest::initGroups(QMultiMap<int, Group*>& groups, QHash<int, Group*>& stog, const Project& project)
{
    for (QMap<int, Student*>::const_iterator it = project.getStudents().cbegin(); it != project.getStudents().cend(); ++it) {
        Student* student = it.value();
        Group* group = new Group(0, new QMap<int, Student*>());
        group->getStudents().insert(student->getId(), student);
        groups.insert(group->getStudents().size(), group);
        stog.insert(student->getId(), group);
    }
}

void SplitSmallest::collectMatches(QHash<int, QMultiMap<int, Group*> >& matches, const QMultiMap<int, Group*>& groups)
{
    Group* curr = NULL;
    for (QMap<int, Group*>::const_iterator outside = groups.cbegin(); outside != groups.cend(); ++outside) {
        if (curr && curr->getStudents().size() < outside.value()->getStudents().size()) {
            break;
        }
        curr = outside.value();

        for (QMap<int, Group*>::const_iterator inside = groups.cbegin(); inside != groups.cend(); ++inside) {
            if (outside != inside) {

                Group* comp = inside.value();
                QMap<int, Student*> students = curr->getStudents();
                for (QMap<int, Student*>::const_iterator it = students.cbegin(); it != students.cend(); ++it) {

                    const Student& student = *(it.value());
                    QMultiMap<int, Group*>& values = matches[student.getId()];
                    values.insert(getMatcher().match(student, *comp), comp);
                    if (values.size() > 2) {
                        values.erase(values.begin());
                    }
                }
            }
        }
    }
}


Student* SplitSmallest::bestStudent(int* match, const Group& from, const Group& to)
{
    Student* student = NULL;
    for (QMap<int, Student*>::const_iterator it = from.getStudents().cbegin(); it != from.getStudents().cend(); ++it) {

        Student* nextStudent = it.value();
        int nextMatch = getMatcher().match(*nextStudent, to);
        if (!student || nextMatch > (*match)) {
            student = nextStudent;
            (*match) = nextMatch;
        }
    }

    return student;
}
