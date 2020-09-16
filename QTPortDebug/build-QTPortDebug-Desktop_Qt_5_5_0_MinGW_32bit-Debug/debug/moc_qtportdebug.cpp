/****************************************************************************
** Meta object code from reading C++ file 'qtportdebug.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTPortDebug/qtportdebug.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtportdebug.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QTPortDebug_t {
    QByteArrayData data[14];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTPortDebug_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTPortDebug_t qt_meta_stringdata_QTPortDebug = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QTPortDebug"
QT_MOC_LITERAL(1, 12, 22), // "on_startbutton_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "on_sendbutton_clicked"
QT_MOC_LITERAL(4, 58, 10), // "SerialRead"
QT_MOC_LITERAL(5, 69, 11), // "SerialWrite"
QT_MOC_LITERAL(6, 81, 12), // "CheckAutoRun"
QT_MOC_LITERAL(7, 94, 10), // "sendupdata"
QT_MOC_LITERAL(8, 105, 16), // "on_Clear_clicked"
QT_MOC_LITERAL(9, 122, 10), // "fillrecord"
QT_MOC_LITERAL(10, 133, 24), // "on_sendtime_valueChanged"
QT_MOC_LITERAL(11, 158, 4), // "arg1"
QT_MOC_LITERAL(12, 163, 27), // "on_displaytime_stateChanged"
QT_MOC_LITERAL(13, 191, 16) // "on_pause_clicked"

    },
    "QTPortDebug\0on_startbutton_clicked\0\0"
    "on_sendbutton_clicked\0SerialRead\0"
    "SerialWrite\0CheckAutoRun\0sendupdata\0"
    "on_Clear_clicked\0fillrecord\0"
    "on_sendtime_valueChanged\0arg1\0"
    "on_displaytime_stateChanged\0"
    "on_pause_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTPortDebug[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      12,    1,   80,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

void QTPortDebug::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QTPortDebug *_t = static_cast<QTPortDebug *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_startbutton_clicked(); break;
        case 1: _t->on_sendbutton_clicked(); break;
        case 2: _t->SerialRead(); break;
        case 3: _t->SerialWrite(); break;
        case 4: _t->CheckAutoRun(); break;
        case 5: _t->sendupdata(); break;
        case 6: _t->on_Clear_clicked(); break;
        case 7: _t->fillrecord(); break;
        case 8: _t->on_sendtime_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_displaytime_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_pause_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject QTPortDebug::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QTPortDebug.data,
      qt_meta_data_QTPortDebug,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QTPortDebug::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTPortDebug::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QTPortDebug.stringdata0))
        return static_cast<void*>(const_cast< QTPortDebug*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QTPortDebug::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
