/****************************************************************************
** Meta object code from reading C++ file 'student.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../orderSystem/student.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'student.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Student_t {
    QByteArrayData data[14];
    char stringdata0[348];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Student_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Student_t qt_meta_stringdata_Student = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Student"
QT_MOC_LITERAL(1, 8, 32), // "on_pushButton_applyOrder_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 36), // "on_pushButton_checkSelfOrder_..."
QT_MOC_LITERAL(4, 79, 35), // "on_pushButton_checkAllOrder_c..."
QT_MOC_LITERAL(5, 115, 33), // "on_pushButton_cancleOrder_cli..."
QT_MOC_LITERAL(6, 149, 41), // "on_comboBox_orderDate_current..."
QT_MOC_LITERAL(7, 191, 5), // "index"
QT_MOC_LITERAL(8, 197, 41), // "on_comboBox_orderTime_current..."
QT_MOC_LITERAL(9, 239, 41), // "on_comboBox_orderRoom_current..."
QT_MOC_LITERAL(10, 281, 11), // "getRoomInfo"
QT_MOC_LITERAL(11, 293, 44), // "on_pushButton_applyOrder_chec..."
QT_MOC_LITERAL(12, 338, 5), // "getID"
QT_MOC_LITERAL(13, 344, 3) // "str"

    },
    "Student\0on_pushButton_applyOrder_clicked\0"
    "\0on_pushButton_checkSelfOrder_clicked\0"
    "on_pushButton_checkAllOrder_clicked\0"
    "on_pushButton_cancleOrder_clicked\0"
    "on_comboBox_orderDate_currentIndexChanged\0"
    "index\0on_comboBox_orderTime_currentIndexChanged\0"
    "on_comboBox_orderRoom_currentIndexChanged\0"
    "getRoomInfo\0on_pushButton_applyOrder_checkMargin_clicked\0"
    "getID\0str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Student[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString,   13,

       0        // eod
};

void Student::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Student *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_applyOrder_clicked(); break;
        case 1: _t->on_pushButton_checkSelfOrder_clicked(); break;
        case 2: _t->on_pushButton_checkAllOrder_clicked(); break;
        case 3: _t->on_pushButton_cancleOrder_clicked(); break;
        case 4: _t->on_comboBox_orderDate_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_comboBox_orderTime_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_comboBox_orderRoom_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->getRoomInfo(); break;
        case 8: _t->on_pushButton_applyOrder_checkMargin_clicked(); break;
        case 9: { int _r = _t->getID((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Student::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Student.data,
    qt_meta_data_Student,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Student::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Student::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Student.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Student::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
