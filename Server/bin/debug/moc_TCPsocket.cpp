/****************************************************************************
** Meta object code from reading C++ file 'TCPsocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TCPsocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TCPsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TCPsocket_t {
    QByteArrayData data[13];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCPsocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCPsocket_t qt_meta_stringdata_TCPsocket = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TCPsocket"
QT_MOC_LITERAL(1, 10, 22), // "string_to_server_ready"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "str"
QT_MOC_LITERAL(4, 38, 22), // "string_to_socket_ready"
QT_MOC_LITERAL(5, 61, 6), // "method"
QT_MOC_LITERAL(6, 68, 11), // "socket_init"
QT_MOC_LITERAL(7, 80, 7), // "qintptr"
QT_MOC_LITERAL(8, 88, 16), // "socketDescriptor"
QT_MOC_LITERAL(9, 105, 24), // "tell_server_disconnected"
QT_MOC_LITERAL(10, 130, 15), // "user_disconnect"
QT_MOC_LITERAL(11, 146, 8), // "send_str"
QT_MOC_LITERAL(12, 155, 6) // "choice"

    },
    "TCPsocket\0string_to_server_ready\0\0str\0"
    "string_to_socket_ready\0method\0socket_init\0"
    "qintptr\0socketDescriptor\0"
    "tell_server_disconnected\0user_disconnect\0"
    "send_str\0choice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPsocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    2,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   52,    2, 0x0a /* Public */,
       9,    0,   55,    2, 0x0a /* Public */,
      10,    0,   56,    2, 0x0a /* Public */,
      11,    2,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,   12,

       0        // eod
};

void TCPsocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TCPsocket *_t = static_cast<TCPsocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->string_to_server_ready((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->string_to_socket_ready((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->socket_init((*reinterpret_cast< const qintptr(*)>(_a[1]))); break;
        case 3: _t->tell_server_disconnected(); break;
        case 4: _t->user_disconnect(); break;
        case 5: _t->send_str((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TCPsocket::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPsocket::string_to_server_ready)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TCPsocket::*_t)(const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPsocket::string_to_socket_ready)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TCPsocket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TCPsocket.data,
      qt_meta_data_TCPsocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TCPsocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPsocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TCPsocket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TCPsocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TCPsocket::string_to_server_ready(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TCPsocket::string_to_socket_ready(const QString & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
