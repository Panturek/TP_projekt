#ifndef SEARCHBOX_H
#define SEARCHBOX_H

#include <QLineEdit>
#include "sessionmanager.h"

class QTreeWidget;

class SuggestCompletion : public QObject
{
    Q_OBJECT

public:
    SuggestCompletion(QLineEdit *parent = 0, SessionManager* sm = 0);
    ~SuggestCompletion();
    bool eventFilter(QObject *obj, QEvent *ev);
    void showCompletion(const QStringList &ids, const QStringList &choices, const QStringList &hits);
signals:
    void executiveAdded();
public slots:
    void doneCompletion();
    void autoSuggest();
    void handleNetworkData(QString);

private:
    QLineEdit *editor;
    QTreeWidget *popup;
    SessionManager* sessionManager;
};

class SearchBox: public QLineEdit
{
    Q_OBJECT

public:
    SearchBox(QWidget *parent = 0, SessionManager* sm = 0);

protected slots:
    void doSearch();

private:
    SuggestCompletion* completer;
    SessionManager* sessionManager;
};
#endif // SEARCHBOX_H
