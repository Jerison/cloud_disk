/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[20];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 16), // "read_from_socket"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "set_hidden"
QT_MOC_LITERAL(4, 36, 5), // "index"
QT_MOC_LITERAL(5, 42, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(6, 66, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(7, 90, 24), // "on_Button_logout_clicked"
QT_MOC_LITERAL(8, 115, 17), // "on_upload_clicked"
QT_MOC_LITERAL(9, 133, 19), // "on_download_clicked"
QT_MOC_LITERAL(10, 153, 16), // "on_fresh_clicked"
QT_MOC_LITERAL(11, 170, 16), // "on_share_clicked"
QT_MOC_LITERAL(12, 187, 18), // "on_session_clicked"
QT_MOC_LITERAL(13, 206, 22), // "on_shareCancel_clicked"
QT_MOC_LITERAL(14, 229, 23), // "on_shareConfirm_clicked"
QT_MOC_LITERAL(15, 253, 20), // "on_StartChat_clicked"
QT_MOC_LITERAL(16, 274, 21), // "on_AddFriends_clicked"
QT_MOC_LITERAL(17, 296, 17), // "on_GoBack_clicked"
QT_MOC_LITERAL(18, 314, 18), // "on_PassReq_clicked"
QT_MOC_LITERAL(19, 333, 17) // "on_RejReq_clicked"

    },
    "Widget\0read_from_socket\0\0set_hidden\0"
    "index\0on_pushButton_6_clicked\0"
    "on_pushButton_5_clicked\0"
    "on_Button_logout_clicked\0on_upload_clicked\0"
    "on_download_clicked\0on_fresh_clicked\0"
    "on_share_clicked\0on_session_clicked\0"
    "on_shareCancel_clicked\0on_shareConfirm_clicked\0"
    "on_StartChat_clicked\0on_AddFriends_clicked\0"
    "on_GoBack_clicked\0on_PassReq_clicked\0"
    "on_RejReq_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    1,  100,    2, 0x0a /* Public */,
       5,    0,  103,    2, 0x08 /* Private */,
       6,    0,  104,    2, 0x08 /* Private */,
       7,    0,  105,    2, 0x08 /* Private */,
       8,    0,  106,    2, 0x08 /* Private */,
       9,    0,  107,    2, 0x08 /* Private */,
      10,    0,  108,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    0,  112,    2, 0x08 /* Private */,
      15,    0,  113,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    0,  116,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
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
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->read_from_socket(); break;
        case 1: _t->set_hidden((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_6_clicked(); break;
        case 3: _t->on_pushButton_5_clicked(); break;
        case 4: _t->on_Button_logout_clicked(); break;
        case 5: _t->on_upload_clicked(); break;
        case 6: _t->on_download_clicked(); break;
        case 7: _t->on_fresh_clicked(); break;
        case 8: _t->on_share_clicked(); break;
        case 9: _t->on_session_clicked(); break;
        case 10: _t->on_shareCancel_clicked(); break;
        case 11: _t->on_shareConfirm_clicked(); break;
        case 12: _t->on_StartChat_clicked(); break;
        case 13: _t->on_AddFriends_clicked(); break;
        case 14: _t->on_GoBack_clicked(); break;
        case 15: _t->on_PassReq_clicked(); break;
        case 16: _t->on_RejReq_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
