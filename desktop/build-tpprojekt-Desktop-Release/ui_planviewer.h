/********************************************************************************
** Form generated from reading UI file 'planviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANVIEWER_H
#define UI_PLANVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlanViewer
{
public:
    QTextEdit *textViewer;
    QPushButton *newPlanButton;
    QPushButton *planDataButton;
    QPushButton *planReviewButton;
    QPushButton *setStateButton;
    QPushButton *newExecutiveButton;
    QPushButton *getPlansButton;
    QPushButton *makeNewButton;
    QLabel *label;

    void setupUi(QWidget *PlanViewer)
    {
        if (PlanViewer->objectName().isEmpty())
            PlanViewer->setObjectName(QStringLiteral("PlanViewer"));
        PlanViewer->resize(991, 567);
        textViewer = new QTextEdit(PlanViewer);
        textViewer->setObjectName(QStringLiteral("textViewer"));
        textViewer->setGeometry(QRect(480, 70, 481, 461));
        newPlanButton = new QPushButton(PlanViewer);
        newPlanButton->setObjectName(QStringLiteral("newPlanButton"));
        newPlanButton->setGeometry(QRect(200, 160, 88, 26));
        planDataButton = new QPushButton(PlanViewer);
        planDataButton->setObjectName(QStringLiteral("planDataButton"));
        planDataButton->setGeometry(QRect(200, 200, 88, 26));
        planReviewButton = new QPushButton(PlanViewer);
        planReviewButton->setObjectName(QStringLiteral("planReviewButton"));
        planReviewButton->setGeometry(QRect(200, 240, 88, 26));
        setStateButton = new QPushButton(PlanViewer);
        setStateButton->setObjectName(QStringLiteral("setStateButton"));
        setStateButton->setGeometry(QRect(200, 280, 88, 26));
        newExecutiveButton = new QPushButton(PlanViewer);
        newExecutiveButton->setObjectName(QStringLiteral("newExecutiveButton"));
        newExecutiveButton->setGeometry(QRect(200, 320, 88, 26));
        getPlansButton = new QPushButton(PlanViewer);
        getPlansButton->setObjectName(QStringLiteral("getPlansButton"));
        getPlansButton->setGeometry(QRect(200, 360, 88, 26));
        makeNewButton = new QPushButton(PlanViewer);
        makeNewButton->setObjectName(QStringLiteral("makeNewButton"));
        makeNewButton->setGeometry(QRect(880, 30, 88, 26));
        label = new QLabel(PlanViewer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(480, 30, 65, 18));

        retranslateUi(PlanViewer);

        QMetaObject::connectSlotsByName(PlanViewer);
    } // setupUi

    void retranslateUi(QWidget *PlanViewer)
    {
        PlanViewer->setWindowTitle(QApplication::translate("PlanViewer", "Form", Q_NULLPTR));
        newPlanButton->setText(QApplication::translate("PlanViewer", "newplan", Q_NULLPTR));
        planDataButton->setText(QApplication::translate("PlanViewer", "plandata", Q_NULLPTR));
        planReviewButton->setText(QApplication::translate("PlanViewer", "planreview", Q_NULLPTR));
        setStateButton->setText(QApplication::translate("PlanViewer", "setState", Q_NULLPTR));
        newExecutiveButton->setText(QApplication::translate("PlanViewer", "newExecutive", Q_NULLPTR));
        getPlansButton->setText(QApplication::translate("PlanViewer", "getPlans", Q_NULLPTR));
        makeNewButton->setText(QApplication::translate("PlanViewer", "Nowy", Q_NULLPTR));
        label->setText(QApplication::translate("PlanViewer", "Zadania:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlanViewer: public Ui_PlanViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANVIEWER_H
