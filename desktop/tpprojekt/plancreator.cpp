#include "plancreator.h"
#include "ui_plancreator.h"
#include "creatortaskwidget.h"
#include "qstring.h"

PlanCreator::PlanCreator(QWidget *parent, SessionManager *sm) :
    QDialog(parent),
    ui(new Ui::PlanCreator),
    sessionManager(sm)
    ,task_id(1)
{
    ui->setupUi(this);
    init();
}

PlanCreator::~PlanCreator()
{
    delete ui;
}

void PlanCreator::init(){
    ui->taskList->addWidget( makePlusik() );
    ui->taskList->setAlignment( Qt::AlignTop );

    connect(ui->stateModeCombo, SIGNAL( activated(int) ),
            this, SLOT( hideStatesEdit(int) ) );
    connect(ui->submitButton, SIGNAL( clicked() ),
            this, SLOT( submit() ) );
}

QPushButton* PlanCreator::makePlusik(){
    auto plusik = new QPushButton(this);
    plusik->setText("+");
    plusik->setFixedSize(40, 40);
    plusik->setFlat( true );
    plusik->setStyleSheet("QPushButton {"
                          "color: green;"
                          "font-size: 24px;"
                          "border-width: 2px;"
                          "border-style: solid; "
                          "border-radius: 4px;"
                          "border-color: green;"
                          ";}");
    plusik->setCursor(QCursor(Qt::PointingHandCursor));
    plusik->setAttribute(Qt::WA_TranslucentBackground);

    connect(plusik, SIGNAL(clicked()), this, SLOT(addNewTask()));
    return plusik;
}

void PlanCreator::hideStatesEdit( int index ){
    if( index == 0 ){
        ui->statesEdit->setVisible(true);
    }
    else{
        ui->statesEdit->setVisible(false);
    }
}

void PlanCreator::addNewTask(){
    auto task = new CreatorTaskWidget(this, task_id++);
    ui->taskList->insertWidget(  ui->taskList->count()-1
                                 , task);
}

#include <qdebug.h>
void PlanCreator::submit(){
    QString availableStates;
    QString displayMode;
    if( ui->stateModeCombo->currentIndex() == 0){
        availableStates = "\""+ui->statesEdit->toPlainText()+"\"";
        availableStates = availableStates.replace(QRegExp(",\\s*"), "\", \"" );
        displayMode="text";
    }
    else{
        availableStates = "\"true\", \"false\"";
        displayMode="checkbox";
    }

    QString json = QString( "{\"name\":\"%1\", "
    " \"description\":\"%2\", "
    " \"author\":\"%3\", "
    " \"plan\":{ "
    " \"features\":{ "
    " \"open\":%4, "
    " \"states\":[%5], "
    " \"display\":\"%6\", "
    " \"startdate\":false, "
    " \"enddate\":false"
    "}, ")  .arg(ui->nameEdit->text())
            .arg(ui->descriptionEdit->toPlainText())
            .arg(sessionManager->getUserId())
            .arg(ui->openAccess->isChecked() ? "true": "false" )
            .arg(availableStates)
            .arg(displayMode);

    QString tasks =  " \"tasks\":{ \"t0\":{";
    int tasksCount = ui->taskList->count();
    for (int i=0; i < tasksCount; i++){
        auto item = ui->taskList->itemAt(i);
        auto taskWidget = dynamic_cast<CreatorTaskWidget*>(item->widget());
        if(taskWidget){
            auto taskid = taskWidget->getId();
            auto content = taskWidget->getContent();
            tasks += QString("\"next\":\"t%1\"},")
                    .arg( taskid );
            tasks += QString("\"t%1\":"
                             "{\"text\":\"%2\",")
                    .arg(taskid)
                    .arg(content);

            if( i+2 >= tasksCount )
                tasks += QString("\"next\":\"t0\"}");
        }
    }
    tasks += " }";
    json += tasks;
    json += "}}";

    qDebug() << json;
    sessionManager->newPlan(json);
    qDebug() << sessionManager->getLastResponse().c_str();

}

