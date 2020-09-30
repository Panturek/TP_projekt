#ifndef REVIEWEDTASKS_H
#define REVIEWEDTASKS_H
#include <QWidget>
#include "sessionmanager.h"
#include <qgridlayout.h>
#include <vector>

class ReviewedTasks : public QWidget
{
    Q_OBJECT
private:
    SessionManager* sessionManager;
    QString plan_id;
    int user_id;
    QString user_name;
    QGridLayout* layout;
    void addTask(int row, QString TaskText, QString TaskState );

protected:
    void mousePressEvent ( QMouseEvent * event );
public:
    ReviewedTasks(QWidget *parent = nullptr, QString plan_id="",
                  int user_id=0, QString user_name="",
                  SessionManager* sm=nullptr );
    void fill();
};

#endif // REVIEWEDTASKS_H
