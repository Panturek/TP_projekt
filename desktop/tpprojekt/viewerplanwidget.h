#ifndef VIEWERPLANWIDGET_H
#define VIEWERPLANWIDGET_H

#include <QPushButton>

class ViewerPlan : public QPushButton
{
    QString name;
    QString plan_id;
    int m_mode;
    Q_OBJECT
public:
    explicit ViewerPlan(QWidget *parent = nullptr, QString name="", QString id="");
    void setMode(const int mode);
    QString getPlanId() const;
    int getMode() const;
signals:

public slots:
};

#endif // VIEWERPLANWIDGET_H
