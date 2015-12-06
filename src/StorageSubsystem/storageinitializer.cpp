#include "storageinitializer.h"
#include "realquestion.h"

#define DEBUG
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#ifdef DEBUG
#include <QDebug>
#endif

StorageInitializer::StorageInitializer()
{ }

StorageInitializer::~StorageInitializer()
{ }

void StorageInitializer::init(QSqlDatabase &db)
{
    db.open();

#ifdef DEBUG
    db.exec("DROP TABLE IF EXISTS " STU_TABLE);
    db.exec("DROP TABLE IF EXISTS " ADMN_TABLE);
    db.exec("DROP TABLE IF EXISTS " PRO_TABLE);
    db.exec("DROP TABLE IF EXISTS " ENRL_TABLE);
    db.exec("DROP TABLE IF EXISTS " QSTN_TABLE);
    db.exec("DROP TABLE IF EXISTS " ANSR_TABLE);
    db.exec("DROP TABLE IF EXISTS " RESP_TABLE);
#endif

    db.exec("CREATE TABLE IF NOT EXISTS " STU_TABLE
            " (" STU_ID_COL " integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, "
            STU_NAME_COL " text NOT NULL)");

    db.exec("CREATE TABLE IF NOT EXISTS " ADMN_TABLE
            " (" ADMN_ID_COL " integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, "
            ADMN_NAME_COL " text NOT NULL)");

    db.exec("CREATE TABLE IF NOT EXISTS " PRO_TABLE
            " (" PRO_ID_COL " integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, "
            PRO_NAME_COL " text UNIQUE COLLATE NOCASE NOT NULL, "
            PRO_MIN_GRP_COL " integer NOT NULL, "
            PRO_MAX_GRP_COL " integer NOT NULL)");

    db.exec("CREATE TABLE IF NOT EXISTS " ENRL_TABLE
            " (" ENRL_STU_COL " REFERENCES " STU_TABLE " (" STU_ID_COL ") ON DELETE CASCADE ON UPDATE CASCADE NOT NULL, "
            ENRL_PRO_COL " REFERENCES " PRO_TABLE " (" PRO_ID_COL ") ON DELETE CASCADE ON UPDATE CASCADE NOT NULL, "
            ENRL_GRP_COL " integer DEFAULT " STR(ENRL_GRP_NUM) " NOT NULL, "
            "PRIMARY KEY (" ENRL_STU_COL " , " ENRL_PRO_COL "))");

    db.exec("CREATE TABLE IF NOT EXISTS " QSTN_TABLE
            " (" QSTN_ID_COL " integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, "
            QSTN_TEXT_COL " text NOT NULL, "
            QSTN_CAT_COL " text NOT NULL)");

    db.exec("CREATE TABLE IF NOT EXISTS " ANSR_TABLE
            " (" ANSR_QID_COL " REFERENCES " QSTN_TABLE " (" QSTN_ID_COL ") ON DELETE CASCADE NOT NULL, "
            ANSR_ID_COL " integer NOT NULL, "
            ANSR_VAL_COL " text NOT NULL, "
            "PRIMARY KEY (" ANSR_QID_COL " , " ANSR_ID_COL "))");

    db.exec("CREATE TABLE IF NOT EXISTS " RESP_TABLE
            " (" RESP_STU_COL " REFERENCES " STU_TABLE " (" STU_ID_COL ") ON DELETE CASCADE NOT NULL, "
            RESP_QSTN_COL " NOT NULL, "
            RESP_PSNL_ANSR_COL " NOT NULL, "
            RESP_DESR_ANSR_COL " NOT NULL, "
            "FOREIGN KEY (" RESP_QSTN_COL " , " RESP_PSNL_ANSR_COL ") "
                          "REFERENCES " ANSR_TABLE " (" ANSR_QID_COL " , " ANSR_ID_COL ") "
                          "ON DELETE CASCADE ON UPDATE CASCADE, "
            "FOREIGN KEY (" RESP_QSTN_COL " , " RESP_DESR_ANSR_COL ") "
                          "REFERENCES " ANSR_TABLE " (" ANSR_QID_COL " , " ANSR_ID_COL ") "
                          "ON DELETE CASCADE ON UPDATE CASCADE, "
            "PRIMARY KEY (" RESP_STU_COL " , " RESP_QSTN_COL "))");

    db.close();

#ifdef DEBUG
    populate(db);
#endif
}

void StorageInitializer::populate(QSqlDatabase& db)
{
#ifdef DEBUG

#define LEADERSHIP   "Leadership"
#define PERSONALITY  "Personality"
#define SKILLS       "Skills"
#define AVAILABILITY "Availability"

    db.open();

    db.transaction();
    QSqlQuery query(db);

    // Populating database for testing
    // Adding Students
    query.exec("INSERT INTO " STU_TABLE " (" STU_NAME_COL ") "
               "VALUES ('Stuart Dent'), ('Harvey Dent'), ('Bruce Wayne'), ('Frodo Baggins'), ('Cheese Man'), "
               "('Nathan Drake'), ('Jeremy Clarkson'), ('James T. Kirk'), ('Clark Kent'), ('Barry Allen'), "
               "('Timothy Burr'), ('Luke Skywalker'), ('Tony Stark'), ('Natasha Romanova'), ('Steve Rogers'), "
               "('Pepper Roni'), ('The Brickster'), ('Woody'), ('Buzz Lightyear'), ('Matt Murdock'), "
               "('He-Man'), ('Optimus Prime'), ('Gordon Freeman'), ('Jeff Goldblum'), ('Obi-Wan Kenobi')");

    // Adding Admins
    query.exec("INSERT INTO " ADMN_TABLE " (" ADMN_NAME_COL ") "
               "VALUES ('Gandalf the Grey'), ('Ad Min')");

    // Adding projects
    query.exec("INSERT INTO " PRO_TABLE " (" PRO_NAME_COL ", " PRO_MIN_GRP_COL ", " PRO_MAX_GRP_COL ") "
               "VALUES ('HAL', 1, 4), ('Project Thing', 5, 10), ('Pizza', 1, 3)");

    // Enrolling students
//    query.exec("INSERT INTO " ENRL_TABLE " (" ENRL_STU_COL ", " ENRL_PRO_COL ") "
//               "VALUES (1, 1), (4, 3), (2,1), (2,2), (2,3), (8, 2), (7, 1)");
    query.exec("INSERT INTO " ENRL_TABLE " (" ENRL_STU_COL ", " ENRL_PRO_COL ") "
               "SELECT " STU_ID_COL ", 1 FROM " STU_TABLE);

    // Adding questions
    QList<Question*> questions;
    RealQuestion* question = NULL;
    QMap<int, Answer*>* answers = NULL;

    question = new RealQuestion(0, "COMP 2401 Grade", SKILLS);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "A- to A+"));
    answers->insert(2, new Answer(0, "B- to B+"));
    answers->insert(3, new Answer(0, "C- to C+"));
    answers->insert(4, new Answer(0, "D- to D+"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "COMP 2404 Grade", SKILLS);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "A- to A+"));
    answers->insert(2, new Answer(0, "B- to B+"));
    answers->insert(3, new Answer(0, "C- to C+"));
    answers->insert(4, new Answer(0, "D- to D+"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "Rate your confidence/comfortability with report writing.", SKILLS);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Very low"));
    answers->insert(2, new Answer(0, "Low"));
    answers->insert(3, new Answer(0, "Average"));
    answers->insert(4, new Answer(0, "High"));
    answers->insert(5, new Answer(0, "Very high"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "Rate your proficiency at software debugging.", SKILLS);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Very low"));
    answers->insert(2, new Answer(0, "Low"));
    answers->insert(3, new Answer(0, "Average"));
    answers->insert(4, new Answer(0, "High"));
    answers->insert(5, new Answer(0, "Very high"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "Rate your comfortability in the seat of power.", LEADERSHIP);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Very low"));
    answers->insert(2, new Answer(0, "Low"));
    answers->insert(3, new Answer(0, "Average"));
    answers->insert(4, new Answer(0, "High"));
    answers->insert(5, new Answer(0, "Very high"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "Rate your level of organization.", LEADERSHIP);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Very low"));
    answers->insert(2, new Answer(0, "Low"));
    answers->insert(3, new Answer(0, "Average"));
    answers->insert(4, new Answer(0, "High"));
    answers->insert(5, new Answer(0, "Very high"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "Rate your comfortablility in making big, important decisions.", LEADERSHIP);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Very low"));
    answers->insert(2, new Answer(0, "Low"));
    answers->insert(3, new Answer(0, "Average"));
    answers->insert(4, new Answer(0, "High"));
    answers->insert(5, new Answer(0, "Very high"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "Rate your willingness to step up to the plate and take the initiative.", LEADERSHIP);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Very low"));
    answers->insert(2, new Answer(0, "Low"));
    answers->insert(3, new Answer(0, "Average"));
    answers->insert(4, new Answer(0, "High"));
    answers->insert(5, new Answer(0, "Very high"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "Rate your tendency to procrastinate to the last minute.", PERSONALITY);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Very low"));
    answers->insert(2, new Answer(0, "Low"));
    answers->insert(3, new Answer(0, "Average"));
    answers->insert(4, new Answer(0, "High"));
    answers->insert(5, new Answer(0, "Very high"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "Rate your tendency to start discussions with relative strangers.", PERSONALITY);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Very low"));
    answers->insert(2, new Answer(0, "Low"));
    answers->insert(3, new Answer(0, "Average"));
    answers->insert(4, new Answer(0, "High"));
    answers->insert(5, new Answer(0, "Very high"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "When working on large projects, what is your preferred way of working?", PERSONALITY);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Working on everything at once"));
    answers->insert(2, new Answer(0, "Working on several things at once"));
    answers->insert(3, new Answer(0, "Working on a couple of things at once"));
    answers->insert(4, new Answer(0, "Working on exactly one thing at a time"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "If you have a meeting tomorrow, what time would you usually arrive?", PERSONALITY);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Very late"));
    answers->insert(2, new Answer(0, "Late"));
    answers->insert(3, new Answer(0, "Right on time"));
    answers->insert(4, new Answer(0, "Early"));
    answers->insert(5, new Answer(0, "Very early"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "During a typical day, when is your preferred working time?", AVAILABILITY);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Morning"));
    answers->insert(2, new Answer(0, "Afternoon"));
    answers->insert(3, new Answer(0, "Evening"));
    answers->insert(4, new Answer(0, "Late at night"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "What days are you usually available?", AVAILABILITY);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Weekends"));
    answers->insert(2, new Answer(0, "Some weekdays"));
    answers->insert(3, new Answer(0, "Any day except weekends"));
    answers->insert(4, new Answer(0, "Every day of the week"));
    question->setAnswers(answers);
    questions.append(question);

    question = new RealQuestion(0, "What is your preferred mode of communication?", AVAILABILITY);
    answers = new QMap<int, Answer*>;
    answers->insert(1, new Answer(0, "Phone calls"));
    answers->insert(2, new Answer(0, "Text messages"));
    answers->insert(3, new Answer(0, "Email"));
    answers->insert(4, new Answer(0, "Forums"));
    question->setAnswers(answers);
    questions.append(question);

    query.prepare("INSERT INTO " QSTN_TABLE " (" QSTN_TEXT_COL ", " QSTN_CAT_COL ") "
                  "VALUES (:text, :category)");

    for (QList<Question*>::iterator it = questions.begin(); it != questions.end(); ++it) {

        Question* q = *it;
        query.bindValue(":text", q->getText());
        query.bindValue(":category", q->getCategory());
        query.exec();

        QSqlQuery a(db);
        a.prepare("INSERT INTO " ANSR_TABLE " (" ANSR_QID_COL ", " ANSR_ID_COL ", " ANSR_VAL_COL ") "
                  "VALUES (:qid, :id, :val)");

        int qid = query.lastInsertId().toInt();
        for (QMap<int, Answer*>::const_iterator ait = q->getAnswers().cbegin(); ait != q->getAnswers().cend(); ++ait) {

            const Answer* answer = ait.value();
            a.bindValue(":qid", qid);
            a.bindValue(":id", ait.key());
            a.bindValue(":val", answer->getText());
            a.exec();
        }

        a.prepare("INSERT INTO " RESP_TABLE " (" RESP_STU_COL ", " RESP_QSTN_COL ", " RESP_PSNL_ANSR_COL ", " RESP_DESR_ANSR_COL ") "
                  "VALUES (:sid, :qid, :pid, :did)");
        a.bindValue(":qid", qid);

        QSqlQuery select(db);
        select.exec("SELECT " STU_ID_COL " FROM " STU_TABLE);
        while (select.next()) {
            int sid = select.value(STU_ID_COL).toInt();
            int pid = qrand() % ((q->getAnswers().lastKey() + 1) - q->getAnswers().firstKey()) + q->getAnswers().firstKey();
            int did = qrand() % ((q->getAnswers().lastKey() + 1) - q->getAnswers().firstKey()) + q->getAnswers().firstKey();
            a.bindValue(":sid", sid);
            a.bindValue(":pid", pid);
            a.bindValue(":did", did);
            a.exec();
        }

        delete q;
    }

    // Commit or rollback
    if (db.lastError().isValid()) {
        db.rollback();
    }
    else {
        db.commit();
    }

    db.close();
#endif
}
