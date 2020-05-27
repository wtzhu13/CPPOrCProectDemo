/****************************************************************************
** Meta object code from reading C++ file 'teacher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../orderSystem/teacher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teacher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Teacher_t {
    QByteArrayData data[16];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Teacher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Teacher_t qt_meta_stringdata_Teacher = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Teacher"
QT_MOC_LITERAL(1, 8, 34), // "on_pushButton_lookAllOrder_cl..."
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 32), // "on_pushButton_checkOrder_clicked"
QT_MOC_LITERAL(4, 77, 13), // "showOrderInfo"
QT_MOC_LITERAL(5, 91, 8), // "lookFlag"
QT_MOC_LITERAL(6, 100, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 122, 16), // "updateOrderState"
QT_MOC_LITERAL(8, 139, 8), // "order_id"
QT_MOC_LITERAL(9, 148, 7), // "stateID"
QT_MOC_LITERAL(10, 156, 20), // "updateRoomMarginInfo"
QT_MOC_LITERAL(11, 177, 7), // "date_id"
QT_MOC_LITERAL(12, 185, 7), // "time_id"
QT_MOC_LITERAL(13, 193, 7), // "room_id"
QT_MOC_LITERAL(14, 201, 5), // "getID"
QT_MOC_LITERAL(15, 207, 3) // "str"

    },
    "Teacher\0on_pushButton_lookAllOrder_clicked\0"
    "\0on_pushButton_checkOrder_clicked\0"
    "showOrderInfo\0lookFlag\0on_pushButton_clicked\0"
    "updateOrderState\0order_id\0stateID\0"
    "updateRoomMarginInfo\0date_id\0time_id\0"
    "room_id\0getID\0str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Teacher[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    2,   55,    2, 0x08 /* Private */,
      10,    3,   60,    2, 0x08 /* Private */,
      14,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   12,   13,
    QMetaType::Int, QMetaType::QString,   15,

       0        // eod
};

void Teacher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Teacher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_lookAllOrder_clicked(); break;
        case 1: _t->on_pushButton_checkOrder_clicked(); break;
        case 2: _t->showOrderInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->updateOrderState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->updateRoomMarginInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: { int _r = _t->getID((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Teacher::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Teacher.data,
    qt_meta_data_Teacher,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Teacher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Teacher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Teacher.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Teacher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
