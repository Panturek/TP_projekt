#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sessionManager( new SessionManager(this) )
{
    ui->setupUi(this);
    viewer = nullptr;

    connect( ui->loginButton, SIGNAL( released() ),
             this, SLOT( loginPanel() ) ) ;
    connect( ui->registerButton, SIGNAL( released() ),
             sessionManager, SLOT( registerRequest() ) ) ;
    connect( sessionManager, SIGNAL( loggedIn()),
             this, SLOT( showViewer() ));
}

MainWindow::~MainWindow()
{
    delete ui;
    if( viewer ){
        viewer->close();
        delete viewer;
    }
}

void MainWindow::loginPanel(){
    auto login = ui->loginEdit->text();
    auto password = ui->passwordEdit->text();
    sessionManager->login(login, password);
}

void MainWindow::showViewer(){
    this->hide();
    if( !viewer ){
        viewer = new PlanViewer( 0, sessionManager );
        connect( viewer, SIGNAL( closing()),
                 this, SLOT( show() ));
    }
    viewer->show();
}

