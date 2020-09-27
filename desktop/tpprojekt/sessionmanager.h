#ifndef LOGINGSERVICE_H
#define LOGINGSERVICE_H


class LogingService : public QObject
{
    Q_OBJECT
public:
    explicit LogingService(QObject *parent = nullptr);

signals:

public slots:
};

#endif // LOGINGSERVICE_H