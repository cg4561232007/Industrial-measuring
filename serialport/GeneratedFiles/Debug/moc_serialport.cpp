/****************************************************************************
** Meta object code from reading C++ file 'serialport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../serialport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Serial_port_t {
    QByteArrayData data[21];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Serial_port_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Serial_port_t qt_meta_stringdata_Serial_port = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Serial_port"
QT_MOC_LITERAL(1, 12, 3), // "ret"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 13), // "connectSocket"
QT_MOC_LITERAL(4, 31, 21), // "on_openbutton_clicked"
QT_MOC_LITERAL(5, 53, 13), // "timeToRecieve"
QT_MOC_LITERAL(6, 67, 8), // "sendData"
QT_MOC_LITERAL(7, 76, 8), // "sendFile"
QT_MOC_LITERAL(8, 85, 12), // "stopShowData"
QT_MOC_LITERAL(9, 98, 11), // "clearWindow"
QT_MOC_LITERAL(10, 110, 11), // "saveInfoAdd"
QT_MOC_LITERAL(11, 122, 9), // "saveLocal"
QT_MOC_LITERAL(12, 132, 9), // "clearFile"
QT_MOC_LITERAL(13, 142, 9), // "clearsend"
QT_MOC_LITERAL(14, 152, 7), // "showret"
QT_MOC_LITERAL(15, 160, 12), // "getAsciiView"
QT_MOC_LITERAL(16, 173, 12), // "autosendshow"
QT_MOC_LITERAL(17, 186, 9), // "recieveUi"
QT_MOC_LITERAL(18, 196, 11), // "showwaveact"
QT_MOC_LITERAL(19, 208, 10), // "transToWav"
QT_MOC_LITERAL(20, 219, 10) // "sendfixfre"

    },
    "Serial_port\0ret\0\0connectSocket\0"
    "on_openbutton_clicked\0timeToRecieve\0"
    "sendData\0sendFile\0stopShowData\0"
    "clearWindow\0saveInfoAdd\0saveLocal\0"
    "clearFile\0clearsend\0showret\0getAsciiView\0"
    "autosendshow\0recieveUi\0showwaveact\0"
    "transToWav\0sendfixfre"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Serial_port[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  110,    2, 0x0a /* Public */,
       4,    0,  111,    2, 0x08 /* Private */,
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    0,  114,    2, 0x08 /* Private */,
       8,    0,  115,    2, 0x08 /* Private */,
       9,    0,  116,    2, 0x08 /* Private */,
      10,    0,  117,    2, 0x08 /* Private */,
      11,    0,  118,    2, 0x08 /* Private */,
      12,    0,  119,    2, 0x08 /* Private */,
      13,    0,  120,    2, 0x08 /* Private */,
      14,    0,  121,    2, 0x08 /* Private */,
      15,    0,  122,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,
      17,    1,  124,    2, 0x08 /* Private */,
      18,    0,  127,    2, 0x08 /* Private */,
      19,    0,  128,    2, 0x08 /* Private */,
      20,    1,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,

       0        // eod
};

void Serial_port::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Serial_port *_t = static_cast<Serial_port *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ret(); break;
        case 1: _t->connectSocket(); break;
        case 2: _t->on_openbutton_clicked(); break;
        case 3: _t->timeToRecieve(); break;
        case 4: _t->sendData(); break;
        case 5: _t->sendFile(); break;
        case 6: _t->stopShowData(); break;
        case 7: _t->clearWindow(); break;
        case 8: _t->saveInfoAdd(); break;
        case 9: _t->saveLocal(); break;
        case 10: _t->clearFile(); break;
        case 11: _t->clearsend(); break;
        case 12: _t->showret(); break;
        case 13: _t->getAsciiView(); break;
        case 14: _t->autosendshow(); break;
        case 15: _t->recieveUi((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->showwaveact(); break;
        case 17: _t->transToWav(); break;
        case 18: _t->sendfixfre((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Serial_port::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Serial_port::ret)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Serial_port::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Serial_port.data,
      qt_meta_data_Serial_port,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Serial_port::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Serial_port::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Serial_port.stringdata0))
        return static_cast<void*>(const_cast< Serial_port*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Serial_port::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void Serial_port::ret()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
