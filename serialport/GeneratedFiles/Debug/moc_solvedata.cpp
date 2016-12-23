/****************************************************************************
** Meta object code from reading C++ file 'solvedata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../solvedata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'solvedata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_solvedata_t {
    QByteArrayData data[14];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_solvedata_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_solvedata_t qt_meta_stringdata_solvedata = {
    {
QT_MOC_LITERAL(0, 0, 9), // "solvedata"
QT_MOC_LITERAL(1, 10, 10), // "sendSVdata"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 19), // "vector<deque<int> >"
QT_MOC_LITERAL(4, 42, 11), // "vector<int>"
QT_MOC_LITERAL(5, 54, 14), // "vector<double>"
QT_MOC_LITERAL(6, 69, 20), // "vector<vector<int> >"
QT_MOC_LITERAL(7, 90, 8), // "testdata"
QT_MOC_LITERAL(8, 99, 16), // "processSharedata"
QT_MOC_LITERAL(9, 116, 12), // "saveShowData"
QT_MOC_LITERAL(10, 129, 8), // "QWidget*"
QT_MOC_LITERAL(11, 138, 6), // "widget"
QT_MOC_LITERAL(12, 145, 6), // "setpal"
QT_MOC_LITERAL(13, 152, 22) // "QMap<QString,QString>&"

    },
    "solvedata\0sendSVdata\0\0vector<deque<int> >\0"
    "vector<int>\0vector<double>\0"
    "vector<vector<int> >\0testdata\0"
    "processSharedata\0saveShowData\0QWidget*\0"
    "widget\0setpal\0QMap<QString,QString>&"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_solvedata[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,
       9,    1,   52,    2, 0x0a /* Public */,
      12,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 5, 0x80000000 | 6,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,    2,

       0        // eod
};

void solvedata::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        solvedata *_t = static_cast<solvedata *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSVdata((*reinterpret_cast< vector<deque<int> >(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< vector<int>(*)>(_a[3])),(*reinterpret_cast< vector<double>(*)>(_a[4])),(*reinterpret_cast< vector<vector<int> >(*)>(_a[5]))); break;
        case 1: _t->testdata(); break;
        case 2: _t->processSharedata(); break;
        case 3: _t->saveShowData((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 4: _t->setpal((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (solvedata::*_t)(vector<deque<int>> , int , vector<int> , vector<double> , vector<vector<int>> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&solvedata::sendSVdata)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject solvedata::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_solvedata.data,
      qt_meta_data_solvedata,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *solvedata::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *solvedata::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_solvedata.stringdata0))
        return static_cast<void*>(const_cast< solvedata*>(this));
    return QObject::qt_metacast(_clname);
}

int solvedata::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void solvedata::sendSVdata(vector<deque<int>> _t1, int _t2, vector<int> _t3, vector<double> _t4, vector<vector<int>> _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
