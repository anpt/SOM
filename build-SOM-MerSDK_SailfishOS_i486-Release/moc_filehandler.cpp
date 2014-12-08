/****************************************************************************
** Meta object code from reading C++ file 'filehandler.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../filehandler.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filehandler.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_filehandler_t {
    QByteArrayData data[11];
    char stringdata[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_filehandler_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_filehandler_t qt_meta_stringdata_filehandler = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 7),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 4),
QT_MOC_LITERAL(4, 26, 4),
QT_MOC_LITERAL(5, 31, 4),
QT_MOC_LITERAL(6, 36, 7),
QT_MOC_LITERAL(7, 44, 6),
QT_MOC_LITERAL(8, 51, 8),
QT_MOC_LITERAL(9, 60, 8),
QT_MOC_LITERAL(10, 69, 11)
    },
    "filehandler\0newTodo\0\0text\0file\0date\0"
    "clockin\0header\0clockout\0fileName\0"
    "listHeaders\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_filehandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x02,
       6,    2,   41,    2, 0x02,
       8,    2,   46,    2, 0x02,
      10,    1,   51,    2, 0x02,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    9,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void filehandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        filehandler *_t = static_cast<filehandler *>(_o);
        switch (_id) {
        case 0: _t->newTodo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->clockin((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->clockout((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->listHeaders((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject filehandler::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_filehandler.data,
      qt_meta_data_filehandler,  qt_static_metacall, 0, 0}
};


const QMetaObject *filehandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *filehandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_filehandler.stringdata))
        return static_cast<void*>(const_cast< filehandler*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int filehandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
