/****************************************************************************
** Meta object code from reading C++ file 'history.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../history.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'history.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_history_t {
    QByteArrayData data[13];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_history_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_history_t qt_meta_stringdata_history = {
    {
QT_MOC_LITERAL(0, 0, 7), // "history"
QT_MOC_LITERAL(1, 8, 3), // "ret"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 10), // "drawPoints"
QT_MOC_LITERAL(4, 24, 8), // "testdata"
QT_MOC_LITERAL(5, 33, 10), // "judgeColor"
QT_MOC_LITERAL(6, 44, 7), // "QBrush&"
QT_MOC_LITERAL(7, 52, 12), // "timerShowHis"
QT_MOC_LITERAL(8, 65, 8), // "loadfile"
QT_MOC_LITERAL(9, 74, 12), // "saveShowData"
QT_MOC_LITERAL(10, 87, 10), // "grabwindow"
QT_MOC_LITERAL(11, 98, 8), // "stopshow"
QT_MOC_LITERAL(12, 107, 7) // "showret"

    },
    "history\0ret\0\0drawPoints\0testdata\0"
    "judgeColor\0QBrush&\0timerShowHis\0"
    "loadfile\0saveShowData\0grabwindow\0"
    "stopshow\0showret"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_history[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    2,   67,    2, 0x0a /* Public */,
       7,    0,   72,    2, 0x0a /* Public */,
       8,    0,   73,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort, 0x80000000 | 6,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void history::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        history *_t = static_cast<history *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ret(); break;
        case 1: _t->drawPoints(); break;
        case 2: _t->testdata(); break;
        case 3: _t->judgeColor((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< QBrush(*)>(_a[2]))); break;
        case 4: _t->timerShowHis(); break;
        case 5: _t->loadfile(); break;
        case 6: _t->saveShowData(); break;
        case 7: _t->grabwindow(); break;
        case 8: _t->stopshow(); break;
        case 9: _t->showret(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (history::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&history::ret)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject history::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_history.data,
      qt_meta_data_history,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *history::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *history::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_history.stringdata0))
        return static_cast<void*>(const_cast< history*>(this));
    return QWidget::qt_metacast(_clname);
}

int history::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void history::ret()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
