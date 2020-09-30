#include "executedtasks.h"
#include <qlabel.h>

ExecutedTasks::ExecutedTasks(QWidget *parent,
                             QString user_id,
                             QString plan_id,
                             SessionManager* sm)
    : QWidget(parent)
    , user_id(user_id)
    , plan_id(plan_id)
    , sessionManager( sm )
    , layout(nullptr)
{
    layout = new QGridLayout();
    this->setLayout(layout);
    fill();
}

void ExecutedTasks::fill(){
    addTask(1, "KURDE", "TASKSTATE");
    addTask(2, "ALOHA", "START");
}

void ExecutedTasks::addTask(int row, QString TaskText, QString TaskState ){
//    layout->addWidget(new QLabel(user_name, this), 0, 0, 1, 5);
    if(!sessionManager)
        return;
    sessionManager->planReview( plan_id.toStdString() );
    layout->addWidget(new QLabel( TaskText, this ), row, 1, 1, 3);
    layout->addWidget(new QLabel( TaskState, this ), row, 4, 1, 1);
}
