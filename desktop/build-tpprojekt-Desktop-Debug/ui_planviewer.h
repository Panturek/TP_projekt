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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlanViewer
{
public:
    QTextEdit *textViewer;
    QPushButton *planDataButton;
    QPushButton *planReviewButton;
    QPushButton *setStateButton;
    QPushButton *newExecutiveButton;
    QPushButton *getPlansButton;
    QPushButton *makeNewButton;
    QLabel *label;
    QWidget *plansListWidget;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *searcherLayout;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *inspectedButton;
    QPushButton *executedButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *taskList;

    void setupUi(QWidget *PlanViewer)
    {
        if (PlanViewer->objectName().isEmpty())
            PlanViewer->setObjectName(QStringLiteral("PlanViewer"));
        PlanViewer->resize(991, 567);
        textViewer = new QTextEdit(PlanViewer);
        textViewer->setObjectName(QStringLiteral("textViewer"));
        textViewer->setGeometry(QRect(410, 500, 551, 61));
        planDataButton = new QPushButton(PlanViewer);
        planDataButton->setObjectName(QStringLiteral("planDataButton"));
        planDataButton->setGeometry(QRect(380, 130, 88, 26));
        planReviewButton = new QPushButton(PlanViewer);
        planReviewButton->setObjectName(QStringLiteral("planReviewButton"));
        planReviewButton->setGeometry(QRect(380, 170, 88, 26));
        setStateButton = new QPushButton(PlanViewer);
        setStateButton->setObjectName(QStringLiteral("setStateButton"));
        setStateButton->setGeometry(QRect(380, 210, 88, 26));
        newExecutiveButton = new QPushButton(PlanViewer);
        newExecutiveButton->setObjectName(QStringLiteral("newExecutiveButton"));
        newExecutiveButton->setGeometry(QRect(380, 250, 88, 26));
        getPlansButton = new QPushButton(PlanViewer);
        getPlansButton->setObjectName(QStringLiteral("getPlansButton"));
        getPlansButton->setGeometry(QRect(380, 290, 88, 26));
        makeNewButton = new QPushButton(PlanViewer);
        makeNewButton->setObjectName(QStringLiteral("makeNewButton"));
        makeNewButton->setGeometry(QRect(880, 30, 88, 26));
        label = new QLabel(PlanViewer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(480, 30, 65, 18));
        plansListWidget = new QWidget(PlanViewer);
        plansListWidget->setObjectName(QStringLiteral("plansListWidget"));
        plansListWidget->setGeometry(QRect(20, 90, 351, 451));
        label_2 = new QLabel(plansListWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 170, 161, 91));
        verticalLayoutWidget = new QWidget(plansListWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 351, 31));
        searcherLayout = new QVBoxLayout(verticalLayoutWidget);
        searcherLayout->setObjectName(QStringLiteral("searcherLayout"));
        searcherLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget = new QWidget(PlanViewer);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(19, 39, 351, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        inspectedButton = new QPushButton(horizontalLayoutWidget);
        inspectedButton->setObjectName(QStringLiteral("inspectedButton"));
        inspectedButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: rgb(237, 212, 0);\n"
"}"));
        inspectedButton->setCheckable(true);
        inspectedButton->setChecked(true);
        inspectedButton->setFlat(true);

        horizontalLayout->addWidget(inspectedButton);

        executedButton = new QPushButton(horizontalLayoutWidget);
        executedButton->setObjectName(QStringLiteral("executedButton"));
        executedButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: rgb(237, 212, 0);\n"
"}"));
        executedButton->setCheckable(true);
        executedButton->setFlat(true);

        horizontalLayout->addWidget(executedButton);

        scrollArea = new QScrollArea(PlanViewer);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(470, 70, 501, 421));
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

        retranslateUi(PlanViewer);

        executedButton->setDefault(false);


        QMetaObject::connectSlotsByName(PlanViewer);
    } // setupUi

    void retranslateUi(QWidget *PlanViewer)
    {
        PlanViewer->setWindowTitle(QApplication::translate("PlanViewer", "Form", Q_NULLPTR));
        planDataButton->setText(QApplication::translate("PlanViewer", "plandata", Q_NULLPTR));
        planReviewButton->setText(QApplication::translate("PlanViewer", "planreview", Q_NULLPTR));
        setStateButton->setText(QApplication::translate("PlanViewer", "setState", Q_NULLPTR));
        newExecutiveButton->setText(QApplication::translate("PlanViewer", "newExecutive", Q_NULLPTR));
        getPlansButton->setText(QApplication::translate("PlanViewer", "getPlans", Q_NULLPTR));
        makeNewButton->setText(QApplication::translate("PlanViewer", "Nowy", Q_NULLPTR));
        label->setText(QApplication::translate("PlanViewer", "Zadania:", Q_NULLPTR));
        label_2->setText(QApplication::translate("PlanViewer", "NADZOROWANE", Q_NULLPTR));
        inspectedButton->setText(QApplication::translate("PlanViewer", "Nadzorowane", Q_NULLPTR));
        executedButton->setText(QApplication::translate("PlanViewer", "Wykonywane", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlanViewer: public Ui_PlanViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANVIEWER_H
