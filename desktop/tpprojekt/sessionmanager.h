#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H
#include <qobject.h>
#include <qstring.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

class SessionManager : public QObject
{
    Q_OBJECT
private:
    std::string host="http://localhost";
    curlpp::Easy request;
public:
    explicit SessionManager(QObject *parent = nullptr, std::string host="http://localhost");
    ~SessionManager();
    void establishSession();

signals:

public slots:
    void registerRequest();
    void login(const QString, const QString);
};

#endif // SESSIONMANAGER_H
