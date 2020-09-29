#ifndef PLANVIEWER_H
#define PLANVIEWER_H

#include <QWidget>
#include "sessionmanager.h"

namespace Ui {
class PlanViewer;
}

class PlanViewer : public QWidget
{
    Q_OBJECT
public:
    explicit PlanViewer(QWidget *parent = 0, SessionManager* sm = 0);
    ~PlanViewer();
    void showResponse();

signals:
    void closing();

public slots:
    void getPlans();
    void planData();
    void planReview();
    void newPlan();
    void newExecutive();

    void close();

private:
    Ui::PlanViewer *ui;
    SessionManager* sessionManager;
    void init();
};

#endif // PLANVIEWER_H
