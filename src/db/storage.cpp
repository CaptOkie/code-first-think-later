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
// Questions table
#define QSTN_TABLE    "questions"
#define QSTN_ID_COL   "id"
#define QSTN_DESR_COL "desired"
#define QSTN_PSNL_COL "personal"
#define QSTN_CAT_COL  "category"
// Answers table
#define ANSR_TABLE   "answers"
#define ANSR_ID_COL  "id"
#define ANSR_QID_COL "question_id"
#define ANSR_VAL_COL "answer"
// Student's response table
#define RESP_TABLE         "responses"
#define RESP_STU_COL       "student_id"
#define RESP_QSTN_COL      "question_id"
#define RESP_DESR_ANSR_COL "desired_answer_id"
#define RESP_PSNL_ANSR_COL "personal_answer_id"

#include <QDebug>
#define DEBUG

Storage::Storage()
    : db(QSqlDatabase::addDatabase("QSQLITE"))
{
    db.setDatabaseName("cupid.db");
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

#ifdef DEBUG
    db.exec("DROP TABLE IF EXISTS " USER_TABLE);
    db.exec("DROP TABLE IF EXISTS " PRO_TABLE);
    db.exec("DROP TABLE IF EXISTS " ENRL_TABLE);
    db.exec("DROP TABLE IF EXISTS " QSTN_TABLE);
    db.exec("DROP TABLE IF EXISTS " ANSR_TABLE);
    db.exec("DROP TABLE IF EXISTS " RESP_TABLE);
#endif

    db.exec("CREATE TABLE IF NOT EXISTS " USER_TABLE
            " (" USER_ID_COL " integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, "
            USER_NAME_COL " text NOT NULL, "
            USER_TYPE_COL " integer NOT NULL)");

    db.exec("CREATE TABLE IF NOT EXISTS " PRO_TABLE
            " (" PRO_NAME_COL " text PRIMARY KEY NOT NULL, "
            PRO_MAX_GRP_COL " integer NOT NULL, "
            PRO_MIN_GRP_COL " integer NOT NULL)");

    db.exec("CREATE TABLE IF NOT EXISTS " ENRL_TABLE
            " (" ENRL_STU_COL " REFERENCES " USER_TABLE " (" USER_ID_COL ") ON DELETE CASCADE ON UPDATE CASCADE NOT NULL, "
            ENRL_PRO_COL " REFERENCES " PRO_TABLE " (" PRO_NAME_COL ") ON DELETE CASCADE ON UPDATE CASCADE NOT NULL, "
            "PRIMARY KEY (" ENRL_STU_COL " , " ENRL_PRO_COL "))");

    db.exec("CREATE TABLE IF NOT EXISTS " QSTN_TABLE
            " (" QSTN_ID_COL " integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, "
            QSTN_PSNL_COL " text NOT NULL, "
            QSTN_DESR_COL " text NOT NULL, "
            QSTN_CAT_COL " text NOT NULL)");

    db.exec("CREATE TABLE IF NOT EXISTS " ANSR_TABLE
            " (" ANSR_QID_COL " REFERENCES " QSTN_TABLE " (" QSTN_ID_COL ") ON DELETE CASCADE NOT NULL, "
            ANSR_ID_COL " integer NOT NULL, "
            ANSR_VAL_COL " text NOT NULL, "
            "PRIMARY KEY (" ANSR_QID_COL " , " ANSR_ID_COL "))");

    db.exec("CREATE TABLE IF NOT EXISTS " RESP_TABLE
            " (" RESP_STU_COL " REFERENCES " USER_TABLE " (" USER_ID_COL ") ON DELETE CASCADE NOT NULL, "
            RESP_QSTN_COL " NOT NULL, "
            RESP_PSNL_ANSR_COL " NOT NULL, "
            RESP_DESR_ANSR_COL " NOT NULL, "
            "FOREIGN KEY (" RESP_QSTN_COL " , " RESP_DESR_ANSR_COL ") "
                          "REFERENCES " ANSR_TABLE " (" ANSR_QID_COL " , " ANSR_ID_COL ") "
                          "ON DELETE CASCADE ON UPDATE CASCADE, "
            "FOREIGN KEY (" RESP_QSTN_COL " , " RESP_DESR_ANSR_COL ") "
                          "REFERENCES " ANSR_TABLE " (" ANSR_QID_COL " , " ANSR_ID_COL ") "
                          "ON DELETE CASCADE ON UPDATE CASCADE, "
            "PRIMARY KEY (" RESP_STU_COL " , " RESP_QSTN_COL "))");

#ifdef DEBUG
    // Populating database for testing
    // Adding Admins
    db.exec("INSERT INTO " USER_TABLE " (" USER_NAME_COL " , " USER_TYPE_COL ") "
            "VALUES ('Gandalf the Grey', 1), ('Ad Min', 1)");


    // Adding Students
    db.exec("INSERT INTO " USER_TABLE " (" USER_NAME_COL " , " USER_TYPE_COL ") "
            "VALUES "
            "('Stuart Dent', 0), ('Harvey Dent', 0), ('Bruce Wayne', 0), ('Frodo Baggins', 0), ('Cheese Man', 0), "
            "('Nathan Drake', 0), ('Jeremy Clarkson', 0), ('James T. Kirk', 0), ('Clark Kent', 0), ('Barry Allen', 0), "
            "('Timothy Burr', 0), ('Luke Skywalker', 0), ('Tony Stark', 0), ('Natasha Romanova', 0), ('Steve Rogers', 0), "
            "('Pepper Roni', 0), ('The Brickster', 0), ('Woody', 0), ('Buzz Lightyear', 0), ('Matt Murdock', 0), "
            "('He-Man', 0), ('Optimus Prime', 0), ('Gordon Freeman', 0), ('Jeff Goldblum', 0), ('Obi-Wan Kenobi', 0)");

    // Adding projects
    db.exec("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL " , " PRO_MAX_GRP_COL " , " PRO_MIN_GRP_COL ") "
            "VALUES ('pro_1', 5, 4)");

    db.exec("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL " , " PRO_MAX_GRP_COL " , " PRO_MIN_GRP_COL ") "
            "VALUES ('pro_2', 7, 4)");

    db.exec("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL " , " PRO_MAX_GRP_COL " , " PRO_MIN_GRP_COL ") "
            "VALUES ('pro_3', 3, 2)");

    // Adding student enrollment
    db.exec("INSERT INTO " ENRL_TABLE " (" ENRL_STU_COL " , " ENRL_PRO_COL ") "
            "VALUES (7, 'pro_1'), (7, 'pro_3'), (20, 'pro_1'), (20, 'pro_2'), (20, 'pro_3')");

    // Adding questions
    db.exec("INSERT INTO " QSTN_TABLE " (" QSTN_PSNL_COL " , " QSTN_DESR_COL " , " QSTN_CAT_COL ") "
            "VALUES ('What grade did you receive in COMP 2401?', "
            "'What grade would like partners to have received in 2401?', "
            "'Skills')");
    // Adding answers
    db.exec("INSERT INTO " ANSR_TABLE " (" ANSR_QID_COL " , " ANSR_ID_COL " , " ANSR_VAL_COL ") "
            "VALUES (1, 1, 'D- to D+'), (1, 2, 'C- to C+'), (1, 3, 'B- to B+'), (1, 4, 'A- to A+')");

    db.exec("INSERT INTO " QSTN_TABLE " (" QSTN_PSNL_COL " , " QSTN_DESR_COL " , " QSTN_CAT_COL ") "
            "VALUES ('How comfortable are you in the seat of power?', "
            "'How comfortable would you like your partners to be in the seat of power?', "
            "'Leadership')");
    // Adding answers
    db.exec("INSERT INTO " ANSR_TABLE " (" ANSR_QID_COL " , " ANSR_ID_COL " , " ANSR_VAL_COL") "
            "VALUES "
            "(2, 1, 'Baa. I am a sheep. Without a herder, I am lost.'), "
            "(2, 2, 'I panic when people depend on me'), "
            "(2, 3, 'I can handle it if I have to.'), "
            "(2, 4, 'I am pretty happy taking charge of the situation.'), "
            "(2, 5, 'DANCE FOR ME, MY PUPPETS, DANCE!.')");

    db.exec("INSERT INTO " QSTN_TABLE " (" QSTN_PSNL_COL " , " QSTN_DESR_COL " , " QSTN_CAT_COL ") "
            "VALUES ('Rate your tendency to procrastinate work?', "
            "'What would you like the tendency for procrastination of your partners to be?', "
            "'Personality')");
    // Adding answers
    db.exec("INSERT INTO " ANSR_TABLE " (" ANSR_QID_COL" , " ANSR_ID_COL " , " ANSR_VAL_COL") "
            "VALUES "
            "(3, 1, 'Eh, I will finish answering this tomorrow...'), "
            "(3, 2, 'If there is an entire week now, I see no reason to start now.'), "
            "(3, 3, 'Sometimes it happens, sometimes I start early. Depends on my mood.'), "
            "(3, 4, 'I prefer starting earlier rather than later.'), "
            "(3, 5, 'New assignment today? Please, I finished that yesterday.')");

    db.exec("INSERT INTO " QSTN_TABLE " (" QSTN_PSNL_COL " , " QSTN_DESR_COL " , " QSTN_CAT_COL ") "
            "VALUES ('During a typical day, what is your preferred working time?', "
            "'When would you like your partnets to prefer working on a typical day?', "
            "'Availability')");
    // Adding answers
    db.exec("INSERT INTO " ANSR_TABLE " (" ANSR_QID_COL" , " ANSR_ID_COL " , " ANSR_VAL_COL") "
            "VALUES "
            "(4, 1, 'I am a vampire. The sunlight BURNS me (11 PM or later).'), "
            "(4, 2, 'A bit of a night owl (7 PM)'), "
            "(4, 3, 'Around the afternoon is usually good (1 PM or later).'), "
            "(4, 4, 'A bit of an early bird (9 AM).'), "
            "(4, 5, 'At the break of dawn, or earlier, of course! (6 AM or so).')");

    // Adding student response
    db.exec("INSERT INTO " RESP_TABLE
            " (" RESP_STU_COL " , " RESP_QSTN_COL " , " RESP_PSNL_ANSR_COL " , " RESP_DESR_ANSR_COL ") "
            "VALUES "
            "(3, 1, 1, 2), (3, 2, 2, 3), (3, 3, 3, 1), (3, 4, 4, 1), "
            "(4, 1, 5, 4), (4, 2, 3, 4), (4, 3, 1, 5), (4, 4, 3, 2)");
#endif

    db.close();
}

void Storage::addUser(QString& name, User::Type type) {
    db.open();

    QSqlQuery insert(db);
    insert.prepare("INSERT INTO " USER_TABLE " (" USER_NAME_COL " , " USER_TYPE_COL ") "
                   "VALUES (:name, :type)");
    insert.bindValue(":name", name);
    insert.bindValue(":type", type);
    insert.exec();

    db.close();
}

bool Storage::addProject(Project& project) {
    db.open();

    QSqlQuery insert(db);
    insert.prepare("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL " , " PRO_MIN_GRP_COL " , " PRO_MAX_GRP_COL ")"
                   "VALUES (:name, :min, :max)");
    insert.bindValue(":name", project.getName());
    insert.bindValue(":min", project.getGroupSize().getMin());
    insert.bindValue(":max", project.getGroupSize().getMax());
    insert.exec();

    db.close();

    return true;
}

void Storage::updateProject(Project& project, QString& name) {
    db.open();
    db.exec("PRAGMA foreign_keys = ON;");

    QSqlQuery update(db);
    update.prepare("UPDATE " PRO_TABLE " SET " PRO_NAME_COL " = :newName, " PRO_MIN_GRP_COL " = :newMin, "
                   PRO_MAX_GRP_COL " = :newMax WHERE " PRO_NAME_COL " = :name");
    update.bindValue(":newName", project.getName());
    update.bindValue(":newMin", project.getGroupSize().getMin());
    update.bindValue(":newMax", project.getGroupSize().getMax());
    update.bindValue(":name", name);
    update.exec();

    db.close();
}

void Storage::removeProject(QString& project) {
    db.open();
    db.exec("PRAGMA foreign_keys = ON;");

    QSqlQuery remove(db);
    remove.prepare("DELETE FROM " PRO_TABLE " WHERE " PRO_NAME_COL " = :name");
    remove.bindValue(":name", project);
    remove.exec();

    db.close();
}

void Storage::enrollStudent(QString& project, int stuId) {
    db.open();

    QSqlQuery insert(db);
    insert.prepare("INSERT INTO " ENRL_TABLE " (" ENRL_STU_COL " , " ENRL_PRO_COL ") "
                   "VALUES (:student, :project)");
    insert.bindValue(":student", stuId);
    insert.bindValue(":project", project);
    insert.exec();

    db.close();
}

void Storage::unenrollStudent(QString& project, int stuId) {
    db.open();

    QSqlQuery remove(db);
    remove.prepare("DELETE FROM " ENRL_TABLE " WHERE " ENRL_STU_COL " = :stuId AND " ENRL_PRO_COL " = :project");
    remove.bindValue(":stuId", stuId);
    remove.bindValue(":project", project);
    remove.exec();

    db.close();
}

//void Storage::updateResponses(const QList<Response>& responses, int stuId) {
//    db.open();

//    QSqlQuery update(db);
//    update.prepare("UPDATE " RESP_TABLE " SET " RESP_PSNL_ANSR_COL " = :newPersonal ");
//}

bool Storage::validUser(QString& idStr, User** user) {
    return validUser(idStr.toInt(), user);
}

bool Storage::validUser(int id, User** user) {
    db.open();

    QSqlQuery select(db);
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

    db.close();
}

void Storage::getProjects(QList<QString>** enrolled, QList<QString>** available, User& student) {
    *enrolled = new QList<QString>;
    *available = new QList<QString>;
    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT " ENRL_PRO_COL " FROM " ENRL_TABLE " WHERE " ENRL_STU_COL " = :id");
    select.bindValue(":id", student.getId());
    select.exec();

    while(select.next()) {
        QString project = QString(select.value(ENRL_PRO_COL).toString());
        (*enrolled)->append(project);
    }

    select.prepare("SELECT " PRO_NAME_COL " FROM " PRO_TABLE " EXCEPT "
                   "SELECT " ENRL_PRO_COL " FROM " ENRL_TABLE " WHERE " ENRL_STU_COL " = :id");
    select.bindValue(":id", student.getId());
    select.exec();

    while(select.next()) {
        QString project = QString(select.value(PRO_NAME_COL).toString());
        (*available)->append(project);
    }

    db.close();
}

void Storage::getProjects(QList<Project>** projects, QString& name) {
    *projects = new QList<Project>;
    db.open();

    QSqlQuery select(db);
    select.prepare("SELECT * FROM " PRO_TABLE " WHERE " PRO_NAME_COL " = :name");
    select.bindValue(":name", name);
    select.exec();

    while(select.next()) {
        QString name = QString(select.value(PRO_NAME_COL).toString());
        int min = select.value(PRO_MIN_GRP_COL).toInt();
        int max = select.value(PRO_MAX_GRP_COL).toInt();
        (*projects)->append(Project(new QString(name), new GroupSize(min, max)));
    }

    db.close();
}

void Storage::getResponses(QList<Question>& questions, int stuId) {
    db.open();

    QSqlQuery selectQuestions(db);
    QSqlQuery selectAnswer(db);
    QSqlQuery selectResponses(db);

    selectQuestions.prepare("SELECT * FROM " QSTN_TABLE);
    selectAnswer.prepare("SELECT * FROM " ANSR_TABLE " WHERE " ANSR_QID_COL " = :questionId");
    selectResponses.prepare("SELECT * FROM " RESP_TABLE " WHERE "
                            RESP_STU_COL " = :studentId AND "
                            RESP_QSTN_COL " = :questionId");
    selectResponses.bindValue(":studentId", stuId);

    selectQuestions.exec();
    while(selectQuestions.next()) {
        int questionId = selectQuestions.value(QSTN_ID_COL).toInt();

        selectAnswer.bindValue(":questionId", questionId);
        selectAnswer.exec();
        QList<Answer>* answers = new QList<Answer>;
        while(selectAnswer.next()) {
            int answerId = selectAnswer.value(ANSR_ID_COL).toInt();
            QString answerText = selectAnswer.value(ANSR_VAL_COL).toString();

            answers->append(Answer(answerId, answerText));
        }

        selectResponses.bindValue(":questionId", questionId);
        selectResponses.exec();
        QList<Response>* responses = new QList<Response>;
        while(selectResponses.next()) {
            int personal = selectResponses.value(RESP_PSNL_ANSR_COL).toInt();
            int desired = selectResponses.value(RESP_DESR_ANSR_COL).toInt();

            responses->append(Response(stuId, personal, desired));
        }

        QString personal = selectQuestions.value(QSTN_PSNL_COL).toString();
        QString desired = selectQuestions.value(QSTN_DESR_COL).toString();
        QString category = selectQuestions.value(QSTN_CAT_COL).toString();

        questions.append(Question(questionId, personal, desired, category, answers, responses));
    }

    db.close();
}
