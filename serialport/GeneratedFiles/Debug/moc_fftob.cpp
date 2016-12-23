/****************************************************************************
** Meta object code from reading C++ file 'fftob.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../fftob.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fftob.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fftob_t {
    QByteArrayData data[6];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fftob_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fftob_t qt_meta_stringdata_fftob = {
    {
QT_MOC_LITERAL(0, 0, 5), // "fftob"
QT_MOC_LITERAL(1, 6, 10), // "sendFFTres"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 12), // "deque<float>"
QT_MOC_LITERAL(4, 31, 3), // "fft"
QT_MOC_LITERAL(5, 35, 10) // "deque<int>"

    },
    "fftob\0sendFFTres\0\0deque<float>\0fft\0"
    "deque<int>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fftob[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void fftob::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fftob *_t = static_cast<fftob *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFFTres((*reinterpret_cast< deque<float>(*)>(_a[1]))); break;
        case 1: _t->fft((*reinterpret_cast< deque<int>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (fftob::*_t)(deque<float> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fftob::sendFFTres)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject fftob::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_fftob.data,
      qt_meta_data_fftob,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fftob::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fftob::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fftob.stringdata0))
        return static_cast<void*>(const_cast< fftob*>(this));
    return QObject::qt_metacast(_clname);
}

int fftob::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void fftob::sendFFTres(deque<float> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
