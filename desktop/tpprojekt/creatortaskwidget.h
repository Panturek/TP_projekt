#ifndef CREATORTASKWIDGET_H
#define CREATORTASKWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <qtextedit.h>

class CreatorTaskWidget : public QWidget
{
    Q_OBJECT
    int p_task_id;
    const int MINHEIGHT = 100;
    QHBoxLayout* layout;
    QTextEdit* te;
    void makeLayout();
public:
    explicit CreatorTaskWidget(QWidget *parent = nullptr, int task_id=0);

    QString getContent();
    int getId();
signals:
    void deleting();

public slots:
};

#endif // CREATORTASKWIDGET_H
