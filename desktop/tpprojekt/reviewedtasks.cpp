#include "reviewedtasks.h"
#include <qlabel.h>
#include <qdebug.h>

ReviewedTasks::ReviewedTasks(QWidget *parent,
                             QString plan_id,
                             int user_id,
                             QString user_name,
                             SessionManager* sm)
    : QWidget(parent)
    , plan_id(plan_id)
    , sessionManager( sm )
    , layout(nullptr)
{
    layout = new QGridLayout();
    this->setLayout(layout);
    fill();
}

void ReviewedTasks::mousePressEvent ( QMouseEvent * event ){
    QLayoutItem *item;
    while((item = ui->plansList->takeAt(0)))
        if (item->widget()){
            delete item->widget();
            delete item;
        }

    fill();
}

void ReviewedTasks::getPlanData(){
    sessionManager->planData(plan_id);
}

void ReviewedTasks::getPlanStates(){
    sessionManager->planState();
}


void ReviewedTasks::fill(){
    addTask(1, "ALOHA", "START");
}

void ReviewedTasks::addTask(int row, QString TaskText, QString TaskState ){
    layout->addWidget(new QLabel(user_name, this), 0, 0, 1, 5);
    if(!sessionManager)
        return;

    sessionManager->planData();
    layout->addWidget(new QLabel( TaskText, this ), row, 1, 1, 3);
    layout->addWidget(new QLabel( TaskState, this ), row, 4, 1, 1);
}
