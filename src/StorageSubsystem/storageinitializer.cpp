#include "storageinitializer.h"

#define DEBUG
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
            STU_NAME_COL " text NOT NULL, ");

    db.exec("CREATE TABLE IF NOT EXISTS " ADMN_TABLE
            " (" ADMN_ID_COL " integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, "
            ADMN_NAME_COL " text NOT NULL, ");

    db.exec("CREATE TABLE IF NOT EXISTS " PRO_TABLE
            " (" PRO_ID_COL " integer PRIMARY KEY ASC AUTOINCREMENT NOT NULL, "
            PRO_NAME_COL " text UNIQUE COLLATE NOCASE NOT NULL, "
            PRO_MAX_GRP_COL " integer NOT NULL, "
            PRO_MIN_GRP_COL " integer NOT NULL)");

    db.exec("CREATE TABLE IF NOT EXISTS " ENRL_TABLE
            " (" ENRL_STU_COL " REFERENCES " STU_TABLE " (" STU_ID_COL ") ON DELETE CASCADE ON UPDATE CASCADE NOT NULL, "
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
            " (" RESP_STU_COL " REFERENCES " STU_TABLE " (" STU_ID_COL ") ON DELETE CASCADE NOT NULL, "
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
    populate(db);
#endif

    db.close();
}

void StorageInitializer::populate(QSqlDatabase& db)
{
#ifdef DEBUG
    db.open();

    // Populating database for testing
    // Adding Students
    db.exec("INSERT INTO " STU_TABLE " (" STU_NAME_COL ") "
            "VALUES "
            "('Stuart Dent'), ('Harvey Dent'), ('Bruce Wayne'), ('Frodo Baggins'), ('Cheese Man'), "
            "('Nathan Drake'), ('Jeremy Clarkson'), ('James T. Kirk'), ('Clark Kent'), ('Barry Allen')");

    // Adding Admins
    db.exec("INSERT INTO " ADMN_TABLE " (" ADMN_NAME_COL ") "
            "VALUES ('Gandalf the Grey'), ('Ad Min')");

    db.close();
#endif
}
