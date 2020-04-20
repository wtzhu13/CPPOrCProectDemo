/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CPPOrCProectDemo/IDE/IDE/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[14];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_actionUTF_8_triggered"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 22), // "on_actionGBK_triggered"
QT_MOC_LITERAL(4, 60, 23), // "on_actionOPEN_triggered"
QT_MOC_LITERAL(5, 84, 26), // "on_actionSAVE_AS_triggered"
QT_MOC_LITERAL(6, 111, 24), // "on_actionQUITE_triggered"
QT_MOC_LITERAL(7, 136, 22), // "on_actionNEW_triggered"
QT_MOC_LITERAL(8, 159, 23), // "on_actionSAVE_triggered"
QT_MOC_LITERAL(9, 183, 23), // "on_actioncopy_triggered"
QT_MOC_LITERAL(10, 207, 24), // "on_actionpaste_triggered"
QT_MOC_LITERAL(11, 232, 22), // "on_actioncut_triggered"
QT_MOC_LITERAL(12, 255, 23), // "on_actionundo_triggered"
QT_MOC_LITERAL(13, 279, 26) // "on_actioncomplie_triggered"

    },
    "MainWindow\0on_actionUTF_8_triggered\0"
    "\0on_actionGBK_triggered\0on_actionOPEN_triggered\0"
    "on_actionSAVE_AS_triggered\0"
    "on_actionQUITE_triggered\0"
    "on_actionNEW_triggered\0on_actionSAVE_triggered\0"
    "on_actioncopy_triggered\0"
    "on_actionpaste_triggered\0"
    "on_actioncut_triggered\0on_actionundo_triggered\0"
    "on_actioncomplie_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionUTF_8_triggered(); break;
        case 1: _t->on_actionGBK_triggered(); break;
        case 2: _t->on_actionOPEN_triggered(); break;
        case 3: _t->on_actionSAVE_AS_triggered(); break;
        case 4: _t->on_actionQUITE_triggered(); break;
        case 5: _t->on_actionNEW_triggered(); break;
        case 6: _t->on_actionSAVE_triggered(); break;
        case 7: _t->on_actioncopy_triggered(); break;
        case 8: _t->on_actionpaste_triggered(); break;
        case 9: _t->on_actioncut_triggered(); break;
        case 10: _t->on_actionundo_triggered(); break;
        case 11: _t->on_actioncomplie_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
