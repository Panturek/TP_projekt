#include "creatortaskwidget.h"
#include <qpushbutton.h>

CreatorTaskWidget::CreatorTaskWidget(QWidget *parent, int task_id) : QWidget(parent)
  ,layout(nullptr)
  ,p_task_id( task_id )
{
    makeLayout();
    this->setLayout(layout);
    this->setFixedHeight(MINHEIGHT);
    this->setHidden(false);
}

void CreatorTaskWidget::makeLayout(){
    if(layout)
        return;
    layout = new QHBoxLayout(this);
    te = new QTextEdit( this );
    te->setPlaceholderText("Nowe zadanie: "
                           + QString::number(p_task_id));
    auto deleteButton = new QPushButton( this );
    deleteButton->setText("-");
    deleteButton->setFixedSize(40,40);
    deleteButton->setFlat( true );
    deleteButton->setStyleSheet("QPushButton {"
                          "color: red;"
                          "font-size: 24px;"
                          "border-width: 2px;"
                          "border-style: solid; "
                          "border-radius: 4px;"
                          "border-color: red;"
                          ";}");
    connect( deleteButton, SIGNAL(clicked()),
             this, SLOT( deleteLater() ) );

    layout->addWidget( te );
    layout->addWidget( deleteButton );

}

int CreatorTaskWidget::getId(){
    return p_task_id;
}

QString CreatorTaskWidget::getContent(){
    return te->toPlainText();
}
