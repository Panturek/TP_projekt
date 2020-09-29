#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sessionManager( new SessionManager(this) ),
    viewer( new PlanViewer(this, sessionManager) )
{
    ui->setupUi(this);
    viewer->hide();

    connect( ui->loginButton, SIGNAL( released() ),
             this, SLOT( loginPanel() ) ) ;
    connect( ui->registerButton, SIGNAL( released() ),
             sessionManager, SLOT( registerRequest() ) ) ;
    connect( sessionManager, SIGNAL( loggedIn()),
             this, SLOT( showViewer() ));
    connect( viewer, SIGNAL( closing()),
             this, SLOT( show() ));
}

MainWindow::~MainWindow()
{
    delete ui;
    viewer->close();
    delete viewer;
}

void MainWindow::loginPanel(){
    auto login = ui->loginEdit->text();
    auto password = ui->passwordEdit->text();
    sessionManager->login(login, password);
}

void MainWindow::showViewer(){
    this->hide();
    viewer = new PlanViewer( 0, sessionManager );
    viewer->show();
}
