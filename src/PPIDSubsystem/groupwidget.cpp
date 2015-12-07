#include "groupwidget.h"

#include <QVBoxLayout>
#include <QLabel>

GroupWidget::GroupWidget(const Group& group, QWidget *parent)
    : QGroupBox(parent)
{
    setTitle("Group " + QString::number(group.getId()));

    QVBoxLayout* layout = new QVBoxLayout(this);

    const QMap<int, Student*>& students = group.getStudents();
    QMap<int, Student*>::const_iterator it;

    for (it = students.constBegin(); it != students.constEnd(); ++it) {
        const QString& text = (*it)->getName() + " (" + QString::number((*it)->getId()) + ")";
        layout->addWidget(new QLabel(text, this));
    }
    setLayout(layout);
}

GroupWidget::~GroupWidget()
{ }
