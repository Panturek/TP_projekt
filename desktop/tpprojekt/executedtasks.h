#ifndef EXECUTEDTASKS_H
#define EXECUTEDTASKS_H
#include <QWidget>
#include "sessionmanager.h"
#include <qgridlayout.h>


class ExecutedTasks : public QWidget
{
    Q_OBJECT
private:
    SessionManager* sessionManager;
    QString user_id;
    QString plan_id;
    QGridLayout* layout;
    void addTask(int row, QString TaskText, QString TaskState );
public:
    ExecutedTasks(QWidget *parent = nullptr,
                  QString user_name="", QString plan_id="",
                  SessionManager* sm=nullptr );
    void fill();
};

#endif // EXECUTEDTASKS_H
