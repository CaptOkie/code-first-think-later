#include "storage.h"
#include "groupsize.h"

// Table names and columns
// Student table
#define USER_TABLE    "users"
#define USER_ID_COL   "id"
#define USER_NAME_COL "name"
#define USER_TYPE_COL "type"
// Project table
#define PRO_TABLE       "projects"
#define PRO_NAME_COL    "name"
#define PRO_MAX_GRP_COL "max_grp_size"
#define PRO_MIN_GRP_COL "min_grp_size"
// Enrollment Table
#define ENRL_TABLE   "enrollment"
#define ENRL_STU_COL "stu_id"
#define ENRL_PRO_COL "project_name"

#include <QDebug>
#define DEBUG

Storage::Storage()
    : db(QSqlDatabase::addDatabase("QSQLITE"))
{
    db.setDatabaseName("cuPID.db");
    setupDB();
}

Storage::~Storage() {
    if(db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(db.connectionName());
}

void Storage::setupDB() {
    db.open();
    QSqlQuery create;
    create = db.exec("CREATE TABLE IF NOT EXISTS " USER_TABLE
                     " (" USER_ID_COL " integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, "
                     USER_NAME_COL " text NOT NULL, "
                     USER_TYPE_COL " integer NOT NULL)");
    create = db.exec("CREATE TABLE IF NOT EXISTS " PRO_TABLE
                     " (" PRO_NAME_COL " text PRIMARY KEY NOT NULL, "
                     PRO_MAX_GRP_COL " integer NOT NULL, "
                     PRO_MIN_GRP_COL " integer NOT NULL)");
    create = db.exec("CREATE TABLE IF NOT EXISTS " ENRL_TABLE
                     " (" ENRL_STU_COL " REFERENCES " USER_TABLE " (" USER_ID_COL ") ON DELETE CASCADE NOT NULL, "
                     ENRL_PRO_COL " REFERENCES " PRO_TABLE " (" PRO_NAME_COL ") ON DELETE CASCADE NOT NULL, "
                     "PRIMARY KEY (" ENRL_STU_COL " , " ENRL_PRO_COL "))");

#ifdef DEBUG
    // Populating database for debugging
    QSqlQuery insert;
    // Adding admin
    insert = db.exec("INSERT INTO " USER_TABLE " (" USER_NAME_COL " , " USER_TYPE_COL ") SELECT 'a', 1 "
                     "WHERE NOT EXISTS (SELECT * FROM " USER_TABLE " WHERE " USER_TYPE_COL " = 1)");
    // Adding student
    insert = db.exec("INSERT INTO " USER_TABLE " (" USER_NAME_COL " , " USER_TYPE_COL ") SELECT 's', 0 "
                     "WHERE NOT EXISTS (SELECT * FROM " USER_TABLE " WHERE " USER_TYPE_COL " = 0)");
    // Adding projects
    insert = db.exec("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL " , " PRO_MAX_GRP_COL " , " PRO_MIN_GRP_COL ") "
                     "VALUES ('pro_1', 5, 4)");
    insert = db.exec("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL " , " PRO_MAX_GRP_COL " , " PRO_MIN_GRP_COL ") "
                     "VALUES ('pro_2', 7, 4)");
    insert = db.exec("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL " , " PRO_MAX_GRP_COL " , " PRO_MIN_GRP_COL ") "
                     "VALUES ('pro_3', 3, 2)");
    //Adding student enrollment
    insert = db.exec("INSERT INTO " ENRL_TABLE " (" ENRL_STU_COL " , " ENRL_PRO_COL ") "
                     "VALUES (2, 'pro_1'), (2, 'pro_3')");
#endif

    db.close();
}

void Storage::addUser(QString& name, User::Type type) {
    db.open();
    QSqlQuery insert = QSqlQuery(db);
    insert.prepare("INSERT INTO " USER_TABLE " (" USER_NAME_COL " , " USER_TYPE_COL ") "
                   "VALUES (:name, :type)");
    insert.bindValue(":name", name);
    insert.bindValue(":type", type);
    insert.exec();
    db.close();
}

bool Storage::addProject(QString& name) {
    db.open();
    QSqlQuery insert = QSqlQuery(db);
    insert.prepare("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL ")"
                   "VALUES (:name)");
    insert.bindValue(":name", name);
    insert.exec();
    db.close();

    return true;
}

bool Storage::validUser(QString& idStr, User** user) {
    return validUser(atoi(idStr.toStdString().c_str()), user);
}

bool Storage::validUser(int id, User** user) {
    db.open();
    QSqlQuery select = QSqlQuery(db);
    select.prepare("SELECT * FROM " USER_TABLE " WHERE " USER_ID_COL " = :id");
    select.bindValue(":id", id);
    select.exec();

    if(select.first()) {
        int id = select.value(USER_ID_COL).toInt();
        User::Type type = (User::Type)select.value(USER_TYPE_COL).toInt();
        QString name = (QString)select.value(USER_NAME_COL).toString();
        *user = new User(id, type, new QString(name));

        db.close();
        return true;
    }
    db.close();
    return false;
}

void Storage::getProjects(QList<Project>** projects) {
    *projects = new QList<Project>;
    db.open();
    QSqlQuery select = db.exec("SELECT * FROM " PRO_TABLE);
    while(select.next()) {
        QString name = QString(select.value(PRO_NAME_COL).toString());
        int min = select.value(PRO_MIN_GRP_COL).toInt();
        int max = select.value(PRO_MAX_GRP_COL).toInt();
        (*projects)->append(Project(new QString(name), new GroupSize(min, max)));
    }
}
