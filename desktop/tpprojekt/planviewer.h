#ifndef PLANVIEWER_H
#define PLANVIEWER_H

#include <QWidget>
#include "sessionmanager.h"
#include "plancreator.h"

class SearchBox;

namespace Ui {
class PlanViewer;
}

enum ViewMode {
    Reviewed,
    Executed
};

class PlanViewer : public QWidget
{
    Q_OBJECT
public:
    explicit PlanViewer(QWidget *parent = 0, SessionManager* sm = 0);
    ~PlanViewer();

    void clearTaskList();
signals:
    void closing();

public slots:
    void showCreator();
    void close();
    void switchToExecuted();
    void switchToInspected();
    void showPlanData();

    void fillPlansList(ViewMode vm=Reviewed);
    void fillTaskList();
private:
    Ui::PlanViewer *ui;
    SessionManager* sessionManager;
    SearchBox* searchBox;
    void init();
    void viewPlanAsReviewed(QString planId);
    void viewPlanAsExecuted(QString planId);
};

#endif // PLANVIEWER_H
