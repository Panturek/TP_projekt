#include "searchbox.h"
#include <qtreewidget.h>
#include <qevent.h>
#include <qheaderview.h>
#include <qmessagebox.h>

#include <qdebug.h>

class SearchResultItem :public QTreeWidgetItem{
private:
    QString m_planId;
public:
    SearchResultItem(QTreeWidget* parent, QString planId)
        : QTreeWidgetItem( parent )
        , m_planId(planId){}
    QString getPlanId()const{ return m_planId; }
};

SuggestCompletion::SuggestCompletion(QLineEdit *parent, SessionManager* sm): QObject(parent), editor(parent)
  ,sessionManager(sm)
{
    popup = new QTreeWidget(0);
    popup->setWindowFlags(Qt::Popup);
    popup->setFocusPolicy(Qt::NoFocus);
    popup->setFocusProxy(parent);
    popup->setMouseTracking(true);

    popup->setColumnCount(2);
    popup->setUniformRowHeights(true);
    popup->setRootIsDecorated(false);
    popup->setEditTriggers(QTreeWidget::NoEditTriggers);
    popup->setSelectionBehavior(QTreeWidget::SelectRows);
    popup->setFrameStyle(QFrame::Box | QFrame::Plain);
    popup->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    popup->header()->hide();

    popup->installEventFilter(this);

    connect(popup, SIGNAL(itemClicked(QTreeWidgetItem*,int)),
            SLOT(doneCompletion()));

    connect(editor, SIGNAL(textEdited(QString)), this, SLOT(handleNetworkData(QString)));

//    connect(&networkManager, SIGNAL(finished(QNetworkReply*)),
//            this, SLOT(handleNetworkData(QNetworkReply*)));

}

SuggestCompletion::~SuggestCompletion()
{
    delete popup;
}

bool SuggestCompletion::eventFilter(QObject *obj, QEvent *ev)
{
    if (obj != popup)
        return false;

    if (ev->type() == QEvent::MouseButtonPress) {
        popup->hide();
        editor->setFocus();
        return true;
    }

    if (ev->type() == QEvent::KeyPress) {

        bool consumed = false;
        int key = static_cast<QKeyEvent*>(ev)->key();
        switch (key) {
        case Qt::Key_Enter:
        case Qt::Key_Return:
            doneCompletion();
            consumed = true;

        case Qt::Key_Escape:
            editor->setFocus();
            popup->hide();
            consumed = true;

        case Qt::Key_Up:
        case Qt::Key_Down:
        case Qt::Key_Home:
        case Qt::Key_End:
        case Qt::Key_PageUp:
        case Qt::Key_PageDown:
            break;

        default:
            editor->setFocus();
            editor->event(ev);
            popup->hide();
            break;
        }

        return consumed;
    }

    return false;
}

void SuggestCompletion::showCompletion(const QStringList& ids, const QStringList &choices, const QStringList &hits)
{
    if (choices.isEmpty() || choices.count() != hits.count())
        return;

    const QPalette &pal = editor->palette();
    QColor color = pal.color(QPalette::Disabled, QPalette::WindowText);

    popup->setUpdatesEnabled(false);
    popup->clear();
    for (int i = 0; i < choices.count(); ++i) {
        SearchResultItem * item;
        item = new SearchResultItem(popup, ids[i]);
        item->setText(0, choices[i]);
        item->setText(1, hits[i]);
        item->setTextAlignment(1, Qt::AlignRight);
        item->setTextColor(1, color);
    }
    popup->setCurrentItem(popup->topLevelItem(0));
    popup->resizeColumnToContents(0);
    popup->resizeColumnToContents(1);
    popup->adjustSize();
    popup->setUpdatesEnabled(true);

    int h = popup->sizeHintForRow(0) * qMin(7, choices.count()) + 3;
    popup->resize(popup->width(), h);

    popup->move(editor->mapToGlobal(QPoint(0, editor->height())));
    popup->setFocus();
    popup->show();
}

void SuggestCompletion::doneCompletion()
{
    popup->hide();
    editor->setFocus();
    QTreeWidgetItem *item = popup->currentItem();
    if(!item)
        return;
    auto searchResult = dynamic_cast<SearchResultItem*>(item);
    if( !searchResult )
        return;
    auto newExecId = searchResult->getPlanId();
    sessionManager->newExecutive( newExecId );
    editor->setText(item->text(0));

/*
    QMessageBox msgBox;
    msgBox.setWindowTitle("Dodawanie wykonawcy planu");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Ok);
    if( sessionManager->getPlans( item->text(0) )
            .contains( newExecId) )
        msgBox.setInformativeText("Dodano pomyślnie");
    else
        msgBox.setInformativeText("Nie udało się wykonać operacji");
    msgBox.exec();
*/    QMetaObject::invokeMethod(editor, "returnPressed");

    emit executiveAdded();
}

void SuggestCompletion::autoSuggest()
{
}

void SuggestCompletion::handleNetworkData(QString searched)
{
    QStringList choices;
    QStringList hits;
    QStringList ids;

    auto availablePlans =sessionManager->getPlans( searched );

    auto found = availablePlans.split(",");

    for(auto&& elem: found){
        auto strs = elem.split(":");
        if(strs.size() < 3)
            continue;
        ids << strs[0].trimmed().remove("\"");
        choices << strs[1];
        hits << strs[2];
    }
    showCompletion(ids, choices, hits);

}

SearchBox::SearchBox(QWidget *parent, SessionManager* sm): QLineEdit(parent)
  ,sessionManager(sm)
{
    completer = new SuggestCompletion(this, sm);

    connect(this, SIGNAL(returnPressed()),this, SLOT(doSearch()));
    connect(completer, SIGNAL(executiveAdded()),this, SIGNAL(executiveAdded()));

    setWindowTitle("Search");
    setPlaceholderText("Szukaj");

    adjustSize();
    resize(400, height());
    setFocus();
}

void SearchBox::doSearch()
{
}
