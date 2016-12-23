/****************************************************************************
** Meta object code from reading C++ file 'paintthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../paintthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_paintthread_t {
    QByteArrayData data[23];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_paintthread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_paintthread_t qt_meta_stringdata_paintthread = {
    {
QT_MOC_LITERAL(0, 0, 11), // "paintthread"
QT_MOC_LITERAL(1, 12, 11), // "pixmapReady"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "QPixmap*"
QT_MOC_LITERAL(4, 34, 4), // "stop"
QT_MOC_LITERAL(5, 39, 11), // "threadpause"
QT_MOC_LITERAL(6, 51, 12), // "threadresume"
QT_MOC_LITERAL(7, 64, 9), // "setXYcord"
QT_MOC_LITERAL(8, 74, 8), // "showGrid"
QT_MOC_LITERAL(9, 83, 7), // "showSin"
QT_MOC_LITERAL(10, 91, 8), // "showReal"
QT_MOC_LITERAL(11, 100, 8), // "slideavg"
QT_MOC_LITERAL(12, 109, 7), // "mathavg"
QT_MOC_LITERAL(13, 117, 12), // "addWeightavg"
QT_MOC_LITERAL(14, 130, 6), // "midavg"
QT_MOC_LITERAL(15, 137, 6), // "getnum"
QT_MOC_LITERAL(16, 144, 4), // "int*"
QT_MOC_LITERAL(17, 149, 7), // "getstop"
QT_MOC_LITERAL(18, 157, 6), // "getsin"
QT_MOC_LITERAL(19, 164, 8), // "getstate"
QT_MOC_LITERAL(20, 173, 12), // "SWITCH_STATE"
QT_MOC_LITERAL(21, 186, 8), // "getclear"
QT_MOC_LITERAL(22, 195, 7) // "getgrid"

    },
    "paintthread\0pixmapReady\0\0QPixmap*\0"
    "stop\0threadpause\0threadresume\0setXYcord\0"
    "showGrid\0showSin\0showReal\0slideavg\0"
    "mathavg\0addWeightavg\0midavg\0getnum\0"
    "int*\0getstop\0getsin\0getstate\0SWITCH_STATE\0"
    "getclear\0getgrid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_paintthread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  107,    2, 0x0a /* Public */,
       5,    0,  108,    2, 0x0a /* Public */,
       6,    0,  109,    2, 0x0a /* Public */,
       7,    0,  110,    2, 0x0a /* Public */,
       8,    0,  111,    2, 0x0a /* Public */,
       9,    0,  112,    2, 0x0a /* Public */,
      10,    0,  113,    2, 0x0a /* Public */,
      11,    0,  114,    2, 0x0a /* Public */,
      12,    0,  115,    2, 0x0a /* Public */,
      13,    0,  116,    2, 0x0a /* Public */,
      14,    0,  117,    2, 0x0a /* Public */,
      15,    1,  118,    2, 0x0a /* Public */,
      17,    1,  121,    2, 0x0a /* Public */,
      18,    1,  124,    2, 0x0a /* Public */,
      19,    1,  127,    2, 0x0a /* Public */,
      21,    1,  130,    2, 0x0a /* Public */,
      22,    1,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void paintthread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        paintthread *_t = static_cast<paintthread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pixmapReady((*reinterpret_cast< QPixmap*(*)>(_a[1]))); break;
        case 1: _t->stop(); break;
        case 2: _t->threadpause(); break;
        case 3: _t->threadresume(); break;
        case 4: _t->setXYcord(); break;
        case 5: _t->showGrid(); break;
        case 6: _t->showSin(); break;
        case 7: _t->showReal(); break;
        case 8: _t->slideavg(); break;
        case 9: _t->mathavg(); break;
        case 10: _t->addWeightavg(); break;
        case 11: _t->midavg(); break;
        case 12: _t->getnum((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 13: _t->getstop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->getsin((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->getstate((*reinterpret_cast< SWITCH_STATE(*)>(_a[1]))); break;
        case 16: _t->getclear((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->getgrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (paintthread::*_t)(QPixmap * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&paintthread::pixmapReady)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject paintthread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_paintthread.data,
      qt_meta_data_paintthread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *paintthread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *paintthread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_paintthread.stringdata0))
        return static_cast<void*>(const_cast< paintthread*>(this));
    return QThread::qt_metacast(_clname);
}

int paintthread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void paintthread::pixmapReady(QPixmap * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
