#include "planviewer.h"
#include "ui_planviewer.h"
#include "searchbox.h"

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
    ui->searcherLayout->addWidget( new SearchBox(this, sessionManager) );
    fillPlansList();

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
}

void PlanViewer::fillPlansList( ){
    sessionManager->getPlans();
    ui->plansList
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
}

void PlanViewer::getPlans(){
    sessionManager->getPlans( "ch" );
    showResponse();
}

void PlanViewer::planData(){
    sessionManager->planData( );
    showResponse();
}

void PlanViewer::planReview(){
    sessionManager->planReview("12009232331491");
    showResponse();
}

void PlanViewer::setState(){
    sessionManager->setState();
    showResponse();
}

void PlanViewer::planState(){
    sessionManager->planState();
    showResponse();
}

void PlanViewer::switchToExecuted(){
    ui->executedButton->setChecked(true);
    ui->inspectedButton->setChecked(false);
}

void PlanViewer::switchToInspected(){
    ui->inspectedButton->setChecked(true);
    ui->executedButton->setChecked(false);
}



