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

    void setupUi(QWidget *PlanViewer)
    {
        if (PlanViewer->objectName().isEmpty())
            PlanViewer->setObjectName(QStringLiteral("PlanViewer"));
        PlanViewer->resize(731, 524);
        textViewer = new QTextEdit(PlanViewer);
        textViewer->setObjectName(QStringLiteral("textViewer"));
        textViewer->setGeometry(QRect(230, 10, 481, 491));
        newPlanButton = new QPushButton(PlanViewer);
        newPlanButton->setObjectName(QStringLiteral("newPlanButton"));
        newPlanButton->setGeometry(QRect(60, 60, 88, 26));
        planDataButton = new QPushButton(PlanViewer);
        planDataButton->setObjectName(QStringLiteral("planDataButton"));
        planDataButton->setGeometry(QRect(60, 100, 88, 26));
        planReviewButton = new QPushButton(PlanViewer);
        planReviewButton->setObjectName(QStringLiteral("planReviewButton"));
        planReviewButton->setGeometry(QRect(60, 140, 88, 26));
        setStateButton = new QPushButton(PlanViewer);
        setStateButton->setObjectName(QStringLiteral("setStateButton"));
        setStateButton->setGeometry(QRect(60, 180, 88, 26));
        newExecutiveButton = new QPushButton(PlanViewer);
        newExecutiveButton->setObjectName(QStringLiteral("newExecutiveButton"));
        newExecutiveButton->setGeometry(QRect(60, 220, 88, 26));
        getPlansButton = new QPushButton(PlanViewer);
        getPlansButton->setObjectName(QStringLiteral("getPlansButton"));
        getPlansButton->setGeometry(QRect(60, 260, 88, 26));

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
    } // retranslateUi

};

namespace Ui {
    class PlanViewer: public Ui_PlanViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANVIEWER_H
