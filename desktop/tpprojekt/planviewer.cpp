#include "planviewer.h"
#include "ui_planviewer.h"
#include "searchbox.h"
#include "viewerplanwidget.h"
#include "reviewedtasks.h"
#include "executedtasks.h"

#include <qdebug.h>

PlanViewer::PlanViewer(QWidget *parent, SessionManager* sm) :
    QWidget(parent),
    ui(new Ui::PlanViewer),
    sessionManager(sm)
{
    ui->setupUi(this);
    init();
}

PlanViewer::~PlanViewer()
{
    delete ui;
}

void PlanViewer::close(){
    emit closing();
}

void PlanViewer::init(){
    searchBox = new SearchBox(this, sessionManager);
    searchBox->setVisible(false);
    ui->searcherLayout->addWidget( searchBox );

    connect(ui->makeNewButton, SIGNAL(clicked()),
            this, SLOT( showCreator() ) );
    connect(ui->getPlansButton, SIGNAL(clicked()),
            this, SLOT( getPlans() ) );
    connect(ui->planDataButton, SIGNAL(clicked()),
            this, SLOT( planData() ) );
    connect(ui->planReviewButton, SIGNAL(clicked()),
            this, SLOT( planReview() ) );
    connect(ui->setStateButton, SIGNAL(clicked()),
            this, SLOT( setState() ) );
    connect(ui->executedButton, SIGNAL(clicked()),
            this, SLOT(switchToExecuted()));
    connect(ui->inspectedButton, SIGNAL(clicked()),
            this, SLOT(switchToInspected()));
    connect( searchBox, SIGNAL(executiveAdded()),
             this, SLOT(switchToExecuted()));

    ui->plansList->setAlignment( Qt::AlignTop );
    ui->taskList->setAlignment( Qt::AlignTop );
    fillPlansList();
    fillTaskList();
}

void PlanViewer::fillPlansList( ViewMode vm ){
    QLayoutItem *item;
    while((item = ui->plansList->takeAt(0)))
        if (item->widget()){
            delete item->widget();
            delete item;
        }

    auto myPlans = sessionManager->myPlans();
    if(myPlans=="") return;
    myPlans = myPlans.remove("{");
    myPlans = myPlans.remove("}");
    myPlans = myPlans.remove("\"rev\":");
    auto seperate = myPlans.split("\"exec\":");
    if (seperate.length() < 2 ) return;
    auto rev = seperate[ int(vm) ];

    for(auto&& data :rev.split(']')){
        auto gesplitten = data.remove(",[").split(",");
        if( gesplitten.length() < 2 )
            continue;
        auto planId = gesplitten[0].remove('[').trimmed().remove('\"');
        auto planName = gesplitten[1].remove('\"');
        auto planButton = new ViewerPlan(this, planName, planId);
        planButton->setMode( int(vm) );
        connect( planButton, SIGNAL(clicked()),
                 this, SLOT( showPlanData( ) ) );
        ui->plansList->addWidget( planButton );
    }

}

void PlanViewer::fillTaskList(){
//    ui->taskList->addWidget(new ReviewedTasks(this, "OUT", sessionManager));
}

void PlanViewer::showResponse(){
    if( sessionManager ){
        ui->textViewer->setText(
                    QString::fromStdString( sessionManager->getLastResponse() ));
    }
}

void PlanViewer::showCreator(){
    auto creator = new PlanCreator( 0, sessionManager);
    creator->exec();
    connect(creator, SIGNAL(closing()),
            this, SLOT(fillPlansList()));
}

void PlanViewer::switchToExecuted(){
    ui->executedButton->setChecked(true);
    ui->inspectedButton->setChecked(false);
    searchBox->setVisible(true);
    fillPlansList(ViewMode::Executed);
}

void PlanViewer::switchToInspected(){
    ui->inspectedButton->setChecked(true);
    ui->executedButton->setChecked(false);
    searchBox->setVisible(false);
    fillPlansList(ViewMode::Reviewed);
}

void PlanViewer::showPlanData(  ){
    auto senderWidget = dynamic_cast<ViewerPlan*>(sender());
    if( !senderWidget )
        return;
    auto mode = senderWidget->getMode();
    auto planId = senderWidget->getPlanId();

    clearTaskList();
    if( ViewMode::Reviewed == mode )
        viewPlanAsReviewed(planId);
    if( ViewMode::Executed == mode )
        viewPlanAsExecuted(planId);
}

void PlanViewer::clearTaskList(){
    QLayoutItem *item;
    while((item = ui->taskList->takeAt(0)))
        if (item->widget()){
            delete item->widget();
            delete item;
        }
}

void PlanViewer::viewPlanAsReviewed(QString planId){
    clearTaskList();
    auto users = sessionManager->planReview( planId.toStdString() );
    auto arrs = users.remove("{").remove("}").remove("\"")
            .remove("[").remove("]");
    auto pairs = arrs.split(",");
    for( int i=0; i< pairs.size()-1; i++){
        auto usrId = pairs[i].toInt();
        auto usrName = pairs[++i];
        ui->taskList->addWidget(
                    new ReviewedTasks(this, planId,
                                      usrId, usrName,
                                      sessionManager));
    }
}

void PlanViewer::viewPlanAsExecuted(QString planId){
    //ui->taskList->addWidget(new ExecutiveTasksWidget(this, "TRY", "OUT"));
}


