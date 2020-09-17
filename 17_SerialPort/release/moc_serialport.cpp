/****************************************************************************
** Meta object code from reading C++ file 'serialport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../17_SerialPort/serialport.h"
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
struct qt_meta_stringdata_SerialPort_t {
    QByteArrayData data[14];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPort_t qt_meta_stringdata_SerialPort = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SerialPort"
QT_MOC_LITERAL(1, 11, 15), // "openbtn_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "savebtn_clicked"
QT_MOC_LITERAL(4, 44, 16), // "clrrxbtn_clicked"
QT_MOC_LITERAL(5, 61, 15), // "sendbtn_clicked"
QT_MOC_LITERAL(6, 77, 16), // "clrtxbtn_clicked"
QT_MOC_LITERAL(7, 94, 19), // "stopsendbtn_clicked"
QT_MOC_LITERAL(8, 114, 19), // "openfilebtn_clicked"
QT_MOC_LITERAL(9, 134, 19), // "sendfilebtn_clicked"
QT_MOC_LITERAL(10, 154, 17), // "delayedcB_changed"
QT_MOC_LITERAL(11, 172, 17), // "hexsendcB_changed"
QT_MOC_LITERAL(12, 190, 11), // "serial_read"
QT_MOC_LITERAL(13, 202, 12) // "serial_write"

    },
    "SerialPort\0openbtn_clicked\0\0savebtn_clicked\0"
    "clrrxbtn_clicked\0sendbtn_clicked\0"
    "clrtxbtn_clicked\0stopsendbtn_clicked\0"
    "openfilebtn_clicked\0sendfilebtn_clicked\0"
    "delayedcB_changed\0hexsendcB_changed\0"
    "serial_read\0serial_write"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPort[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

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

       0        // eod
};

void SerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPort *_t = static_cast<SerialPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openbtn_clicked(); break;
        case 1: _t->savebtn_clicked(); break;
        case 2: _t->clrrxbtn_clicked(); break;
        case 3: _t->sendbtn_clicked(); break;
        case 4: _t->clrtxbtn_clicked(); break;
        case 5: _t->stopsendbtn_clicked(); break;
        case 6: _t->openfilebtn_clicked(); break;
        case 7: _t->sendfilebtn_clicked(); break;
        case 8: _t->delayedcB_changed(); break;
        case 9: _t->hexsendcB_changed(); break;
        case 10: _t->serial_read(); break;
        case 11: _t->serial_write(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SerialPort::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SerialPort.data,
      qt_meta_data_SerialPort,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPort.stringdata0))
        return static_cast<void*>(const_cast< SerialPort*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
