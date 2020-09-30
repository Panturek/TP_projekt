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
/*



QStringList ReviewedTasks::getAvailableStates( QString planData ){
    QRegularExpression re("\"states\":\\s*\\[(?<states>.+)\\]");
    QRegularExpressionMatch match = re.match( planData );
    if( match.hasMatch() ){
        return match.captured("states").remove("\"").split(',');
    }
    return QStringList();
}

QString ReviewedTasks::stateDisplay( QString planData ){
    QRegularExpression re("\"display\":\\s*\"(?<display>.+),\"");
    QRegularExpressionMatch match = re.match( planData );
    if( match.hasMatch() ){
        return match.captured("display");
    }
    return "text";
}

QStringList ReviewedTasks::getTasks(QString planData){
    QStringList res;
    auto splits = planData.split("\"tasks\":");
    for(auto&& pl: splits){
        if( pl.contains(QRegExp("\"next\"\\s*:")))
            continue;
        res.append(QString(pl));
    }
}

void ReviewedTasks::addTask(int row, QString TaskText, QString TaskState ){
    layout->addWidget(new QLabel(user_name, this), 0, 0, 1, 5);
    if(!sessionManager)
        return;
    auto planData = sessionManager->planData(plan_id).remove("\n");

    qDebug() << planData;

    auto availableStates = getAvailableStates( planData );

    for(auto &&sta : availableStates){
        qDebug() << sta;
    }

    auto planState = sessionManager->planState(plan_id, user_id);
    for( int i=0; i < 1; i++){

        layout->addWidget(new QLabel( TaskText, this ), row, 1, 1, 3);
        auto podpacza = stateDisplay(planData);
        if( stateDisplay(planData) == "text"){
            auto states = new QComboBox(this);
            states->addItems(availableStates);
            layout->addWidget(states, row, 4, 1, 1);
        }
        else{
            auto states = new QCheckBox(this);
            layout->addWidget( states, row, 4, 1, 1);
        }
    }
}



*/
