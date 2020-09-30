#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H
#include <qobject.h>
#include <qstring.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
#include "writememory.h"

class SessionManager : public QObject
{
    Q_OBJECT
private:
    int user_id;
    std::string host="http://localhost";
    curlpp::Easy request;
    WriterMemory writer;
    void makeWriter();

public:
    explicit SessionManager(QObject *parent = nullptr, std::string host="http://localhost");
    ~SessionManager();

    int getUserId() const;
signals:
    void loggedIn();

public slots:
    void registerRequest();
    void login(const QString, const QString);
    QString getPlans(const QString searched );
    QString myPlans();
    QString planData(const QString planId );
    QString planReview( const std::string plan_id );
    QString planState(const QString planId, const int userId);
    void newPlan( const QString plan = "" );
    void newExecutive(const QString plan_id);
    void setState(const QString planId, const int userId, const QString taskId, const QString state);
    std::string getLastResponse();
};

#endif // SESSIONMANAGER_H
