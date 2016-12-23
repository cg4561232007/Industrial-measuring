/****************************************************************************
** Meta object code from reading C++ file 'fixCheck.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../fixCheck.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fixCheck.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fixCheck_t {
    QByteArrayData data[16];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fixCheck_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fixCheck_t qt_meta_stringdata_fixCheck = {
    {
QT_MOC_LITERAL(0, 0, 8), // "fixCheck"
QT_MOC_LITERAL(1, 9, 3), // "ret"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 8), // "sendStop"
QT_MOC_LITERAL(4, 23, 10), // "sendResume"
QT_MOC_LITERAL(5, 34, 7), // "sendFre"
QT_MOC_LITERAL(6, 42, 12), // "saveShowData"
QT_MOC_LITERAL(7, 55, 10), // "grabwindow"
QT_MOC_LITERAL(8, 66, 8), // "stopshow"
QT_MOC_LITERAL(9, 75, 7), // "showret"
QT_MOC_LITERAL(10, 83, 9), // "getSVdata"
QT_MOC_LITERAL(11, 93, 19), // "vector<deque<int> >"
QT_MOC_LITERAL(12, 113, 11), // "vector<int>"
QT_MOC_LITERAL(13, 125, 14), // "vector<double>"
QT_MOC_LITERAL(14, 140, 20), // "vector<vector<int> >"
QT_MOC_LITERAL(15, 161, 11) // "mapfrequecy"

    },
    "fixCheck\0ret\0\0sendStop\0sendResume\0"
    "sendFre\0saveShowData\0grabwindow\0"
    "stopshow\0showret\0getSVdata\0"
    "vector<deque<int> >\0vector<int>\0"
    "vector<double>\0vector<vector<int> >\0"
    "mapfrequecy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fixCheck[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   70,    2, 0x08 /* Private */,
       7,    0,   71,    2, 0x08 /* Private */,
       8,    0,   72,    2, 0x08 /* Private */,
       9,    0,   73,    2, 0x08 /* Private */,
      10,    5,   74,    2, 0x0a /* Public */,
      15,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int, 0x80000000 | 12, 0x80000000 | 13, 0x80000000 | 14,    2,    2,    2,    2,    2,
    QMetaType::Void,

       0        // eod
};

void fixCheck::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fixCheck *_t = static_cast<fixCheck *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ret(); break;
        case 1: _t->sendStop(); break;
        case 2: _t->sendResume(); break;
        case 3: _t->sendFre((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->saveShowData(); break;
        case 5: _t->grabwindow(); break;
        case 6: _t->stopshow(); break;
        case 7: _t->showret(); break;
        case 8: _t->getSVdata((*reinterpret_cast< vector<deque<int> >(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< vector<int>(*)>(_a[3])),(*reinterpret_cast< vector<double>(*)>(_a[4])),(*reinterpret_cast< vector<vector<int> >(*)>(_a[5]))); break;
        case 9: _t->mapfrequecy(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (fixCheck::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fixCheck::ret)) {
                *result = 0;
            }
        }
        {
            typedef void (fixCheck::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fixCheck::sendStop)) {
                *result = 1;
            }
        }
        {
            typedef void (fixCheck::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fixCheck::sendResume)) {
                *result = 2;
            }
        }
        {
            typedef void (fixCheck::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fixCheck::sendFre)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject fixCheck::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_fixCheck.data,
      qt_meta_data_fixCheck,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fixCheck::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fixCheck::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fixCheck.stringdata0))
        return static_cast<void*>(const_cast< fixCheck*>(this));
    return QWidget::qt_metacast(_clname);
}

int fixCheck::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void fixCheck::ret()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void fixCheck::sendStop()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void fixCheck::sendResume()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void fixCheck::sendFre(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
