/********************************************************************************
** Form generated from reading UI file 'plancreator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANCREATOR_H
#define UI_PLANCREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlanCreator
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *nameEdit;
    QPlainTextEdit *descriptionEdit;
    QLabel *label_5;
    QPushButton *submitButton;
    QCheckBox *openAccess;
    QComboBox *stateModeCombo;
    QPlainTextEdit *statesEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *taskList;

    void setupUi(QWidget *PlanCreator)
    {
        if (PlanCreator->objectName().isEmpty())
            PlanCreator->setObjectName(QStringLiteral("PlanCreator"));
        PlanCreator->resize(816, 545);
        label = new QLabel(PlanCreator);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 65, 18));
        label_2 = new QLabel(PlanCreator);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 65, 18));
        label_4 = new QLabel(PlanCreator);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 320, 141, 18));
        nameEdit = new QLineEdit(PlanCreator);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(30, 60, 231, 26));
        descriptionEdit = new QPlainTextEdit(PlanCreator);
        descriptionEdit->setObjectName(QStringLiteral("descriptionEdit"));
        descriptionEdit->setGeometry(QRect(30, 110, 231, 161));
        label_5 = new QLabel(PlanCreator);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(290, 30, 65, 18));
        submitButton = new QPushButton(PlanCreator);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setGeometry(QRect(700, 490, 91, 26));
        openAccess = new QCheckBox(PlanCreator);
        openAccess->setObjectName(QStringLiteral("openAccess"));
        openAccess->setGeometry(QRect(30, 280, 171, 24));
        openAccess->setLayoutDirection(Qt::RightToLeft);
        openAccess->setChecked(true);
        stateModeCombo = new QComboBox(PlanCreator);
        stateModeCombo->setObjectName(QStringLiteral("stateModeCombo"));
        stateModeCombo->setGeometry(QRect(30, 340, 231, 26));
        statesEdit = new QPlainTextEdit(PlanCreator);
        statesEdit->setObjectName(QStringLiteral("statesEdit"));
        statesEdit->setGeometry(QRect(30, 380, 231, 61));
        scrollArea = new QScrollArea(PlanCreator);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(280, 60, 501, 421));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 499, 419));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        taskList = new QVBoxLayout();
        taskList->setObjectName(QStringLiteral("taskList"));

        verticalLayout->addLayout(taskList);

        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(PlanCreator);

        QMetaObject::connectSlotsByName(PlanCreator);
    } // setupUi

    void retranslateUi(QWidget *PlanCreator)
    {
        PlanCreator->setWindowTitle(QApplication::translate("PlanCreator", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("PlanCreator", "Nazwa:", Q_NULLPTR));
        label_2->setText(QApplication::translate("PlanCreator", "Opis:", Q_NULLPTR));
        label_4->setText(QApplication::translate("PlanCreator", "Wy\305\233wietlanie stanu:", Q_NULLPTR));
        label_5->setText(QApplication::translate("PlanCreator", "Zadania:", Q_NULLPTR));
        submitButton->setText(QApplication::translate("PlanCreator", "zatwierd\305\272", Q_NULLPTR));
        openAccess->setText(QApplication::translate("PlanCreator", "Otwarty dost\304\231p              ", Q_NULLPTR));
        stateModeCombo->clear();
        stateModeCombo->insertItems(0, QStringList()
         << QApplication::translate("PlanCreator", "tekstowy", Q_NULLPTR)
         << QApplication::translate("PlanCreator", "odhaczanie", Q_NULLPTR)
        );
        statesEdit->setPlaceholderText(QApplication::translate("PlanCreator", "Podaj stany po przecinku", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlanCreator: public Ui_PlanCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANCREATOR_H
