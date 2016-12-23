/****************************************************************************
** Meta object code from reading C++ file 'effLine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../effLine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'effLine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_effLine_t {
    QByteArrayData data[6];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_effLine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_effLine_t qt_meta_stringdata_effLine = {
    {
QT_MOC_LITERAL(0, 0, 7), // "effLine"
QT_MOC_LITERAL(1, 8, 3), // "ret"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 10), // "drawPoints"
QT_MOC_LITERAL(4, 24, 10), // "grabwindow"
QT_MOC_LITERAL(5, 35, 7) // "showret"

    },
    "effLine\0ret\0\0drawPoints\0grabwindow\0"
    "showret"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_effLine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void effLine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        effLine *_t = static_cast<effLine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ret(); break;
        case 1: _t->drawPoints(); break;
        case 2: _t->grabwindow(); break;
        case 3: _t->showret(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (effLine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&effLine::ret)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject effLine::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_effLine.data,
      qt_meta_data_effLine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *effLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *effLine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_effLine.stringdata0))
        return static_cast<void*>(const_cast< effLine*>(this));
    return QWidget::qt_metacast(_clname);
}

int effLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void effLine::ret()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
