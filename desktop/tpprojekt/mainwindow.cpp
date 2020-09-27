#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    sessionManager = new SessionManager(this);
    ui->setupUi(this);

    connect( ui->loginButton, SIGNAL( released() ),
             this, SLOT( loginPanel() ) ) ;
    connect( ui->registerButton, SIGNAL( released() ),
             sessionManager, SLOT( registerRequest() ) ) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginPanel(){
    auto login = ui->loginEdit->text();
    auto password = ui->passwordEdit->text();
    sessionManager->login(login, password);
}
