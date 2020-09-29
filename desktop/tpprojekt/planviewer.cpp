#include "planviewer.h"
#include "ui_planviewer.h"

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
    connect(ui->getPlansButton, SIGNAL(clicked()),
            this, SLOT( getPlans() ) );
    connect(ui->planDataButton, SIGNAL(clicked()),
            this, SLOT( planData() ) );
    connect(ui->planReviewButton, SIGNAL(clicked()),
            this, SLOT( planReview() ) );
    connect(ui->newPlanButton, SIGNAL(clicked()),
            this, SLOT( newPlan() ) );
    connect(ui->newExecutiveButton, SIGNAL(clicked()),
            this, SLOT( newExecutive() ) );
}

void PlanViewer::showResponse(){
    if( sessionManager ){
        ui->textViewer->setText(
                    QString::fromStdString( sessionManager->getLastResponse() ));
    }
}

void PlanViewer::getPlans(){
    sessionManager->getPlans( );
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

void PlanViewer::newPlan(){
    sessionManager->newPlan();
    showResponse();
}

void PlanViewer::newExecutive(){
    sessionManager->newExecutive();
    showResponse();
}


