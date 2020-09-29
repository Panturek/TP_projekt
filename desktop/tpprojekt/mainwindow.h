#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sessionmanager.h"
#include "planviewer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void loginPanel();
    void showViewer();

private:
    Ui::MainWindow* ui;
    PlanViewer* viewer;
    PlanCreator* creator;
    SessionManager* sessionManager;
};

#endif // MAINWINDOW_H
