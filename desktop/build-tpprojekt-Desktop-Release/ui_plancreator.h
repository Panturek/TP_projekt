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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
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
    QLabel *tasksCountLabel;
    QPushButton *submitButton;
    QCheckBox *openAccess;
    QPushButton *plusikButton;
    QComboBox *stateModeCombo;
    QPlainTextEdit *statesEdit;
    QListWidget *taskList;

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
        tasksCountLabel = new QLabel(PlanCreator);
        tasksCountLabel->setObjectName(QStringLiteral("tasksCountLabel"));
        tasksCountLabel->setGeometry(QRect(350, 30, 65, 18));
        submitButton = new QPushButton(PlanCreator);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setGeometry(QRect(710, 490, 91, 26));
        openAccess = new QCheckBox(PlanCreator);
        openAccess->setObjectName(QStringLiteral("openAccess"));
        openAccess->setGeometry(QRect(30, 280, 171, 24));
        openAccess->setLayoutDirection(Qt::RightToLeft);
        openAccess->setChecked(true);
        plusikButton = new QPushButton(PlanCreator);
        plusikButton->setObjectName(QStringLiteral("plusikButton"));
        plusikButton->setGeometry(QRect(300, 490, 31, 26));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(138, 226, 52, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(198, 255, 143, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(168, 240, 97, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(69, 113, 26, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(92, 151, 34, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(196, 240, 153, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        plusikButton->setPalette(palette);
        plusikButton->setFlat(true);
        stateModeCombo = new QComboBox(PlanCreator);
        stateModeCombo->setObjectName(QStringLiteral("stateModeCombo"));
        stateModeCombo->setGeometry(QRect(30, 340, 231, 26));
        statesEdit = new QPlainTextEdit(PlanCreator);
        statesEdit->setObjectName(QStringLiteral("statesEdit"));
        statesEdit->setGeometry(QRect(30, 380, 231, 61));
        taskList = new QListWidget(PlanCreator);
        taskList->setObjectName(QStringLiteral("taskList"));
        taskList->setGeometry(QRect(290, 60, 511, 411));

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
        tasksCountLabel->setText(QApplication::translate("PlanCreator", "0", Q_NULLPTR));
        submitButton->setText(QApplication::translate("PlanCreator", "zatwierd\305\272", Q_NULLPTR));
        openAccess->setText(QApplication::translate("PlanCreator", "Otwarty dost\304\231p              ", Q_NULLPTR));
        plusikButton->setText(QApplication::translate("PlanCreator", "+", Q_NULLPTR));
        stateModeCombo->clear();
        stateModeCombo->insertItems(0, QStringList()
         << QApplication::translate("PlanCreator", "tekstowy", Q_NULLPTR)
         << QApplication::translate("PlanCreator", "odhaczanie", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class PlanCreator: public Ui_PlanCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANCREATOR_H
