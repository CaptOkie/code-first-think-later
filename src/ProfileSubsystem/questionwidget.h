#ifndef QUESTIONWIDGET_H
#define QUESTIONWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include "StorageSubsystem/question.h"

class QuestionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionWidget(const Question& question, QWidget *parent = 0);
    ~QuestionWidget();

    int getPersonal();
    int getDesired();

private:
    QButtonGroup personal;
    QButtonGroup desired;
};

#endif // QUESTIONWIDGET_H
