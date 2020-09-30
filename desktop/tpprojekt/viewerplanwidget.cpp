#include "viewerplanwidget.h"
#include <qlabel.h>

ViewerPlan::ViewerPlan(QWidget *parent, QString name, QString id)
    : QPushButton(parent)
    , name(name)
    , plan_id( id )
    , m_mode( 0 )
{
    this->setText(name);
    this->setFlat(true);
    this->setStyleSheet("QPushButton{text-align: left;}");
    this->show();
}

void ViewerPlan::setMode(const int mode ){
    this->m_mode = mode;
}

QString ViewerPlan::getPlanId() const
{
    return plan_id;
}

int ViewerPlan::getMode() const{
    return m_mode;
}
