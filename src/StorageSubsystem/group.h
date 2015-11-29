#ifndef GROUP_H
#define GROUP_H

#include <QMap>

#include "student.h"

class Group
{
    public:
        Group();
        ~Group();

        int getId() const;
        const QMap<int, Student>& getStudents() const;
        QMap<int, Student>& getStudents();

    private:
        int id;
        QMap<int, Student>* student;
};

#endif // GROUP_H
