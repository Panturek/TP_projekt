#include "reviewedtasks.h"
#include <qlabel.h>
#include <qdebug.h>
#include <qregularexpression.h>
#include <qcombobox.h>
#include <qcheckbox.h>

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
    while((item = layout->takeAt(0)))
        if (item->widget()){
            delete item->widget();
            delete item;
        }

    fill();
}

void ReviewedTasks::fill(){
    addTask(1, "ALOHA", "START");
}

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

std::map<QString, QString> ReviewedTasks::mapStates(QString planStates){
    std::map<QString, QString> map;
    int begin = 1;
    for (int i = 1 ; i < planStates.length(); i++ ){
        if( planStates[i] == "}"){
            auto task = planStates.mid(begin, i-begin);
            begin = i;
            QString taskId = task.mid(0, task.indexOf(':', 0));

            int ind = task.indexOf("state", 0)+6;
            QString taskState = task.mid( ind, task.indexOf(',',ind )-ind  );

            taskState.remove('}').remove(',').remove('\"').remove(':');
            taskId.remove('}').remove(',').remove('\"');
            map[taskId.trimmed()] = taskState;
            qDebug() << taskId << taskState;
        }
    }
    return map;
}


std::map<QString, QString> ReviewedTasks::mapTexts(QString planData){
    std::map<QString, QString> map;
    int begin = planData.indexOf( "}", planData.indexOf("\"tasks\"") )+1 ;
    for (int i = begin ; i < planData.length(); i++ ){
        if( planData[i] == "}"){
            auto task = planData.mid(begin, i-begin);
            begin = i;
            QString taskId = task.mid(0, task.indexOf(':', 0));

            int ind = task.indexOf("text", 0)+5;
            QString taskState = task.mid( ind, task.indexOf("next",ind )-ind-3 );

            taskState.remove('}').remove(',').remove('\"').remove(':');
            taskId.remove('}').remove(',').remove('\"');
            if(taskId.contains("t0") || taskId.trimmed() == "")
                continue;
            map[taskId.trimmed()] = taskState;
            qDebug() << taskId << taskState;
        }
    }
    return map;
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

    auto textsMap = mapTexts(planData);
    auto statesMap = mapStates(planState);

    int i = 1;
    for( auto&& item: textsMap){

        layout->addWidget(new QLabel( item.second, this ), row, 1, 1, 3);

        auto taskId = item.first;
        if( stateDisplay(planData).trimmed() != "checkbox"){
            auto states = new QLabel( statesMap[ taskId ] , this);
            layout->addWidget(states, row++, 4, 1, 1);
        }
        else{
            auto states = new QCheckBox(this);
            layout->addWidget( states, row++, 4, 1, 1);
        }
    }
}
