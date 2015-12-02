#ifndef GROUP_H
#define GROUP_H

#include <QMap>

#include "student.h"

class Group
{
    public:
        Group(int id, QMap<int, Student&>* student);
        ~Group();

        int getId() const;
        QMap<int, Student&>& getStudents();
        const QMap<int, Student&>& getStudents() const;

    private:
        int id;
        QMap<int, Student&>* students;
};

#endif // GROUP_H
