/********************************************************************************
** Form generated from reading UI file 'stulogindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STULOGINDIALOG_H
#define UI_STULOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StuLoginDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *StuLoginDialog)
    {
        if (StuLoginDialog->objectName().isEmpty())
            StuLoginDialog->setObjectName(QStringLiteral("StuLoginDialog"));
        StuLoginDialog->resize(400, 300);
        StuLoginDialog->setStyleSheet(QLatin1String("QDialog {\n"
"	background-image: url(:/images/images/stuLoginBackground.jpg);\n"
"}"));
        horizontalLayout = new QHBoxLayout(StuLoginDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(92, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(StuLoginDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(StuLoginDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        buttonBox = new QDialogButtonBox(StuLoginDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(92, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(StuLoginDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), StuLoginDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StuLoginDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(StuLoginDialog);
    } // setupUi

    void retranslateUi(QDialog *StuLoginDialog)
    {
        StuLoginDialog->setWindowTitle(QApplication::translate("StuLoginDialog", "Dialog", 0));
        label->setText(QApplication::translate("StuLoginDialog", "Name", 0));
    } // retranslateUi

};

namespace Ui {
    class StuLoginDialog: public Ui_StuLoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STULOGINDIALOG_H
