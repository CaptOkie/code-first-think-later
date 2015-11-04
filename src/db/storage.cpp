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

#ifdef DEBUG
    populateDatabase();
#endif
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
    db.exec("PRAGMA foreign_keys = ON;");

    QSqlQuery remove(db);
    remove.prepare("DELETE FROM " ENRL_TABLE " WHERE " ENRL_STU_COL " = :stuId AND " ENRL_PRO_COL " = :project");
    remove.bindValue(":stuId", stuId);
    remove.bindValue(":project", project);
    remove.exec();

    db.close();
}

void Storage::updateResponse(const Response& response) {
    db.open();
    db.exec("PRAGMA foreign_keys = ON;");

    QSqlQuery update(db);
    update.prepare("UPDATE " RESP_TABLE " SET " RESP_PSNL_ANSR_COL " = :newPersonal, "
                   RESP_DESR_ANSR_COL " = :newDesired "
                   "WHERE " RESP_STU_COL " = :studentId AND " RESP_QSTN_COL " = :questionId");
    update.bindValue(":studentId", response.getStudent());
    update.bindValue(":questionId", response.getQuestion());
    update.bindValue(":newPersonal", response.getPersonal());
    update.bindValue(":newDesired", response.getDesired());
    update.exec();

    db.close();
}

void Storage::updateResponses(const QList<Response>& responses) {
    db.open();
    db.exec("PRAGMA foreign_keys = ON;");

    QSqlQuery update(db);
    update.prepare("UPDATE " RESP_TABLE " SET " RESP_PSNL_ANSR_COL " = :newPersonal, "
                   RESP_DESR_ANSR_COL " = :newDesired "
                   "WHERE " RESP_STU_COL " = :studentId AND " RESP_QSTN_COL " = :questionId");

    QList<Response>::const_iterator it;
    for(it = responses.begin(); it != responses.end(); ++it) {
        const Response& resp = *it;

        update.bindValue(":studentId", resp.getStudent());
        update.bindValue(":questionId", resp.getQuestion());
        update.bindValue(":newPersonal", resp.getPersonal());
        update.bindValue(":newDesired", resp.getPersonal());
        update.exec();
    }

    db.close();
}

bool Storage::getUser(int id, User** user) {
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

            responses->append(Response(stuId, questionId, personal, desired));
        }

        QString personal = selectQuestions.value(QSTN_PSNL_COL).toString();
        QString desired = selectQuestions.value(QSTN_DESR_COL).toString();
        QString category = selectQuestions.value(QSTN_CAT_COL).toString();

        questions.append(Question(questionId, personal, desired, category, answers, responses));
    }

    db.close();
}

void Storage::populateDatabase() {
#ifdef DEBUG
    db.open();

    QList<int> users;
    QList<int> projects;

    // Populating database for testing
    // Adding Students
    db.exec("INSERT INTO " USER_TABLE " (" USER_NAME_COL " , " USER_TYPE_COL ") "
            "VALUES "
            "('Stuart Dent', 0), ('Harvey Dent', 0), ('Bruce Wayne', 0), ('Frodo Baggins', 0), ('Cheese Man', 0), "
            "('Nathan Drake', 0), ('Jeremy Clarkson', 0), ('James T. Kirk', 0), ('Clark Kent', 0), ('Barry Allen', 0), "
            "('Timothy Burr', 0), ('Luke Skywalker', 0), ('Tony Stark', 0), ('Natasha Romanova', 0), ('Steve Rogers', 0), "
            "('Pepper Roni', 0), ('The Brickster', 0), ('Woody', 0), ('Buzz Lightyear', 0), ('Matt Murdock', 0), "
            "('He-Man', 0), ('Optimus Prime', 0), ('Gordon Freeman', 0), ('Jeff Goldblum', 0), ('Obi-Wan Kenobi', 0)");
    QSqlQuery query = db.exec("SELECT " USER_ID_COL " FROM " USER_TABLE);
    while(query.next()) {
        users.append(query.value(USER_ID_COL).toInt());
    }

    // Adding Admins
    db.exec("INSERT INTO " USER_TABLE " (" USER_NAME_COL " , " USER_TYPE_COL ") "
            "VALUES ('Gandalf the Grey', 1), ('Ad Min', 1)");

    // Adding projects
    db.exec("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL " , " PRO_MAX_GRP_COL " , " PRO_MIN_GRP_COL ") "
            "VALUES ('Super Duper Router 3000', 5, 4), ('Hacking Time', 7, 4), ('HAL', 3, 2)");

    QList<Question> questions;
    QList<Answer>* answers = new QList<Answer>();

#define SKILLS "1. Skills"
#define LEADERSHIP "2. Leadership"
#define PERSONALITY "3. Personality"
#define AVAILABILITY "4. Availability"

    answers->append(Answer(1, "D- to D+"));
    answers->append(Answer(2, "C- to C+"));
    answers->append(Answer(3, "B- to B+"));
    answers->append(Answer(4, "A- to A+"));
    questions.append(Question(0,
                              "What grade did you receive in COMP 2401?",
                              "What grade would you like your partners to have received in COMP 2401?",
                              SKILLS,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "D- to D+"));
    answers->append(Answer(2, "C- to C+"));
    answers->append(Answer(3, "B- to B+"));
    answers->append(Answer(4, "A- to A+"));
    questions.append(Question(0,
                              "What grade did you receive in COMP 2404?",
                              "What grade would you like your partners to have received in COMP 2404?",
                              SKILLS,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "Very uncomfortable/zero confidence."));
    answers->append(Answer(2, "Uncomfortable/low confidence."));
    answers->append(Answer(3, "It's okay, I guess."));
    answers->append(Answer(4, "I enjoy writing!"));
    answers->append(Answer(5, "I'm very comfortable/confident."));
    questions.append(Question(0,
                              "How confident and/or comfortable are you in report writing?",
                              "How confident and/or comfortable would you like your partners to be in report writing?",
                              SKILLS,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "I cannot debug."));
    answers->append(Answer(2, "I have a lot of trouble with debugging."));
    answers->append(Answer(3, "I can usually figure things out eventually."));
    answers->append(Answer(4, "I have a fair idea of where the bugs usually happen so I'm pretty fast at debugging!"));
    answers->append(Answer(5, "I'm very good at debugging software."));
    questions.append(Question(0,
                              "How proficient are you at software debugging?",
                              "How proficient would you like your partners to be at debugging?",
                              SKILLS,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "I am very uncomfortabl with power."));
    answers->append(Answer(2, "I dislike having power."));
    answers->append(Answer(3, "I can handle it if I have to."));
    answers->append(Answer(4, "I'm pretty happy taking charge of situations."));
    answers->append(Answer(5, "I am very comfortable with having power."));
    questions.append(Question(0,
                              "How comfortable are you in the seat of power?",
                              "How comfortable would you like your partners to be in the seat of power?",
                              LEADERSHIP,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "Extrememely unorganized."));
    answers->append(Answer(2, "Unorganized."));
    answers->append(Answer(3, "I have a pretty good idea of where everything is."));
    answers->append(Answer(4, "Organized."));
    answers->append(Answer(5, "Extremely well organized."));
    questions.append(Question(0,
                              "Rate your level of organization.",
                              "Rate the level of organization you would like your partners to have?",
                              LEADERSHIP,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "Very uncomfortable."));
    answers->append(Answer(2, "Uncomfortable."));
    answers->append(Answer(3, "I don't really mind making decisions if I have to."));
    answers->append(Answer(4, "I am pretty comfortable with making tough decisions."));
    answers->append(Answer(5, "I am very comfortable making tough decisions."));
    questions.append(Question(0,
                              "Rate your comfortability in making big, important decisions.",
                              "Rate how comfortable you would like your partners to be at making big, important decisions.",
                              LEADERSHIP,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "I will not step up and take the initiative."));
    answers->append(Answer(2, "I dislike taking charge."));
    answers->append(Answer(3, "If no one else wants to, I have no problem taking charge."));
    answers->append(Answer(4, "I like stepping up and taking charge."));
    answers->append(Answer(5, "I love stepping up and taking charge."));
    questions.append(Question(0,
                              "How willing are you to step up to the plate and take the initiative?",
                              "How willing should your partners be to step up to the plate to take the initiative?",
                              LEADERSHIP,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "I always procrastinate to the last minute."));
    answers->append(Answer(2, "I have a tendency to procrastinate."));
    answers->append(Answer(3, "Sometimes it happens, sometimes I start early. Depends on my mood."));
    answers->append(Answer(4, "I prefer starting earlier rather than later."));
    answers->append(Answer(5, "I never procrastinate."));
    questions.append(Question(0,
                              "Rate your tendency to procrastinate to the last minute.",
                              "Rate the tendency you would like for your group members to procrastinate to the last minute.",
                              PERSONALITY,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "I will never start talking with relative strangers."));
    answers->append(Answer(2, "I feel uneasy around strangers."));
    answers->append(Answer(3, "If the look approachable, I might say hello."));
    answers->append(Answer(4, "I enjoy speaking with strangers."));
    answers->append(Answer(5, "I will always start talking with random strangers."));
    questions.append(Question(0,
                              "Rate your tendency to start/begin discussions with relative strangers.",
                              "Rate the tendency you would like your partners to start/begin discussions with relative strnagers.",
                              PERSONALITY,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "I start everything at once and distribute my time across everything evenly."));
    answers->append(Answer(2, "I try to do a bit of everything, but I tend to get excited/focused on one part and finish it completely."));
    answers->append(Answer(3, "I try to do things one at a time, but usually end up starting multiple things anyways."));
    answers->append(Answer(4, "I focus on one thing at a time until it's finished."));
    questions.append(Question(0,
                              "When working on large scale projects, what is your preferred way of working?",
                              "How would you like your partners to prefer working on large scale projects?",
                              PERSONALITY,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "I don't usually show up to meetings."));
    answers->append(Answer(2, "Considerably late."));
    answers->append(Answer(3, "About on time - perhaps a few minutes either way."));
    answers->append(Answer(4, "Several minutes early."));
    answers->append(Answer(5, "More than 15 minutes early."));
    questions.append(Question(0,
                              "If you have a meeting tomorrow, what time would you usually arrive?",
                              "If you have a meeting tomorrow, what time would you like your partners to arrive?",
                              PERSONALITY,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "Very late at night."));
    answers->append(Answer(2, "During the evening."));
    answers->append(Answer(3, "During the afternoon."));
    answers->append(Answer(4, "During the morning."));
    answers->append(Answer(5, "Very early in the morning."));
    questions.append(Question(0,
                              "During a typical day, what it your preferred working time?",
                              "What would you like your partner's preferred working times to be?",
                              AVAILABILITY,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "Never."));
    answers->append(Answer(2, "Weekends only."));
    answers->append(Answer(3, "Some weekdays only."));
    answers->append(Answer(4, "Any day of the week, but not the weekends."));
    answers->append(Answer(5, "Everyday is a good day."));
    questions.append(Question(0,
                              "Based on your current schedule, what days are you usually available?",
                              "What days would you like your partners to be available?",
                              AVAILABILITY,
                              answers,
                              new QList<Response>));

    answers = new QList<Answer>();
    answers->append(Answer(1, "Phone calls."));
    answers->append(Answer(2, "Text messages."));
    answers->append(Answer(3, "Emails."));
    answers->append(Answer(4, "Forums."));
    questions.append(Question(0,
                              "Based on how often you check, what is your preferred mode of communication?",
                              "What would you like your partners' preferred mode of communication to be?",
                              AVAILABILITY,
                              answers,
                              new QList<Response>));

    query.prepare("INSERT INTO " QSTN_TABLE " (" QSTN_DESR_COL ", " QSTN_PSNL_COL ", " QSTN_CAT_COL ") VALUES "
                  "(:desr, :pern, :catg)");
    for (QList<Question>::const_iterator it = questions.begin(); it != questions.end(); ++it) {
        const Question& question = *it;
        query.bindValue(":desr", question.getDesired());
        query.bindValue(":pern", question.getPersonal());
        query.bindValue(":catg", question.getCategory());
        query.exec();

        int id = query.lastInsertId().toInt();
        QSqlQuery insert(db);
        insert.prepare("INSERT INTO " ANSR_TABLE " (" ANSR_QID_COL ", " ANSR_ID_COL ", " ANSR_VAL_COL ") VALUES "
                       "(:qid, :id, :val)");
        insert.bindValue(":qid", id);
        for (QList<Answer>::const_iterator it2 = question.getAnswers().begin(); it2 != question.getAnswers().end(); ++it2) {
            const Answer& answer = *it2;
            insert.bindValue(":id", answer.getId());
            insert.bindValue(":val", answer.getValue());
            insert.exec();
        }

        int low = question.getAnswers().first().getId();
        int high = question.getAnswers().last().getId();
        insert.prepare("INSERT INTO " RESP_TABLE " (" RESP_STU_COL ", " RESP_QSTN_COL ", " RESP_PSNL_ANSR_COL ", " RESP_DESR_ANSR_COL ") "
                       " VALUES (:stu, :ques, :pern, :desr)");
        insert.bindValue(":ques", id);
        for (QList<int>::const_iterator it2 = users.begin(); it2 != users.end(); ++it2) {
            const int& student = *it2;
            int pern = qrand() % ((high + 1) - low) + low;
            int desr = qrand() % ((high + 1) - low) + low;

            insert.bindValue(":stu", student);
            insert.bindValue(":pern", pern);
            insert.bindValue(":desr", desr);
            insert.exec();
        }
    }

    db.close();
#endif
}
