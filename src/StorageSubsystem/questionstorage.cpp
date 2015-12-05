#include "questionstorage.h"

QuestionStorage::QuestionStorage(QSqlDatabase& db)
    : db(db)
{

}

QuestionStorage::~QuestionStorage()
{
    if(db.isOpen()) {
        db.close();
    }
}
