#include "questionstorage.h"

QuestionStorage::QuestionStorage()
{
}

QuestionStorage::~QuestionStorage()
{
    if(db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(db.connectionName());
}
