/****************************************************************************
** Meta object code from reading C++ file 'sessionmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tpprojekt/sessionmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sessionmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SessionManager_t {
    QByteArrayData data[15];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SessionManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SessionManager_t qt_meta_stringdata_SessionManager = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SessionManager"
QT_MOC_LITERAL(1, 15, 8), // "loggedIn"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "registerRequest"
QT_MOC_LITERAL(4, 41, 5), // "login"
QT_MOC_LITERAL(5, 47, 8), // "getPlans"
QT_MOC_LITERAL(6, 56, 11), // "std::string"
QT_MOC_LITERAL(7, 68, 7), // "user_id"
QT_MOC_LITERAL(8, 76, 8), // "planData"
QT_MOC_LITERAL(9, 85, 10), // "planReview"
QT_MOC_LITERAL(10, 96, 9), // "planState"
QT_MOC_LITERAL(11, 106, 7), // "newPlan"
QT_MOC_LITERAL(12, 114, 12), // "newExecutive"
QT_MOC_LITERAL(13, 127, 8), // "setState"
QT_MOC_LITERAL(14, 136, 15) // "getLastResponse"

    },
    "SessionManager\0loggedIn\0\0registerRequest\0"
    "login\0getPlans\0std::string\0user_id\0"
    "planData\0planReview\0planState\0newPlan\0"
    "newExecutive\0setState\0getLastResponse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SessionManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   75,    2, 0x0a /* Public */,
       4,    2,   76,    2, 0x0a /* Public */,
       5,    1,   81,    2, 0x0a /* Public */,
       5,    0,   84,    2, 0x2a /* Public | MethodCloned */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    1,   86,    2, 0x0a /* Public */,
      10,    0,   89,    2, 0x0a /* Public */,
      11,    0,   90,    2, 0x0a /* Public */,
      12,    0,   91,    2, 0x0a /* Public */,
      13,    0,   92,    2, 0x0a /* Public */,
      14,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 6,

       0        // eod
};

void SessionManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SessionManager *_t = static_cast<SessionManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loggedIn(); break;
        case 1: _t->registerRequest(); break;
        case 2: _t->login((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->getPlans((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 4: _t->getPlans(); break;
        case 5: _t->planData(); break;
        case 6: _t->planReview((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 7: _t->planState(); break;
        case 8: _t->newPlan(); break;
        case 9: _t->newExecutive(); break;
        case 10: _t->setState(); break;
        case 11: { std::string _r = _t->getLastResponse();
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SessionManager::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SessionManager::loggedIn)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SessionManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SessionManager.data,
      qt_meta_data_SessionManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SessionManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SessionManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SessionManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SessionManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void SessionManager::loggedIn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
