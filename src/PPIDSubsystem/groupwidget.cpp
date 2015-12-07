#include "groupwidget.h"

#include <QVBoxLayout>
#include <QLabel>

GroupWidget::GroupWidget(const Group& group, QWidget *parent)
    : QGroupBox(parent)
{
    if (group.getId() < 0) {
        setTitle("Ungrouped");
    }
    else {
        setTitle("Group " + QString::number(group.getId()) + " (" + QString::number(group.getMatch()) + "% Match)");
    }

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
