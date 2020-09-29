#ifndef PLANCREATOR_H
#define PLANCREATOR_H

#include <QDialog>
#include <QVBoxLayout>
#include <qpushbutton.h>
#include "sessionmanager.h"

namespace Ui {
class PlanCreator;
}

class PlanCreator : public QDialog
{
    Q_OBJECT

public:
    explicit PlanCreator(QWidget *parent = 0, SessionManager* sm = 0);
    ~PlanCreator();

    void clear();
public slots:
    void hideStatesEdit(int);
    void addNewTask();
    void submit();

private:
    Ui::PlanCreator *ui;
    SessionManager *sessionManager;
    int task_id;

    void init();
    QPushButton* makePlusik();
};

#endif // PLANCREATOR_H
