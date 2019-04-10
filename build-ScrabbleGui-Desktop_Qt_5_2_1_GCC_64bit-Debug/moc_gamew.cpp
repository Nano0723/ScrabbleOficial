/****************************************************************************
** Meta object code from reading C++ file 'gamew.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ScrabbleGui/gamew.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamew.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_gameW_t {
    QByteArrayData data[25];
    char stringdata[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_gameW_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_gameW_t qt_meta_stringdata_gameW = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 7),
QT_MOC_LITERAL(2, 14, 0),
QT_MOC_LITERAL(3, 15, 7),
QT_MOC_LITERAL(4, 23, 4),
QT_MOC_LITERAL(5, 28, 11),
QT_MOC_LITERAL(6, 40, 6),
QT_MOC_LITERAL(7, 47, 4),
QT_MOC_LITERAL(8, 52, 15),
QT_MOC_LITERAL(9, 68, 12),
QT_MOC_LITERAL(10, 81, 5),
QT_MOC_LITERAL(11, 87, 9),
QT_MOC_LITERAL(12, 97, 11),
QT_MOC_LITERAL(13, 109, 14),
QT_MOC_LITERAL(14, 124, 16),
QT_MOC_LITERAL(15, 141, 11),
QT_MOC_LITERAL(16, 153, 10),
QT_MOC_LITERAL(17, 164, 8),
QT_MOC_LITERAL(18, 173, 12),
QT_MOC_LITERAL(19, 186, 14),
QT_MOC_LITERAL(20, 201, 14),
QT_MOC_LITERAL(21, 216, 8),
QT_MOC_LITERAL(22, 225, 12),
QT_MOC_LITERAL(23, 238, 14),
QT_MOC_LITERAL(24, 253, 7)
    },
    "gameW\0llenarX\0\0llenarY\0comp\0changeLabel\0"
    "string\0name\0mousePressEvent\0QMouseEvent*\0"
    "event\0dropEvent\0QDropEvent*\0dragEnterEvent\0"
    "QDragEnterEvent*\0selectFicha\0QMimeData*\0"
    "mimeData\0cambiaFichas\0rellenarFichas\0"
    "generarPalabra\0scrabble\0rellenarMano\0"
    "vector<string>\0dibujar\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameW[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a,
       3,    0,   85,    2, 0x0a,
       4,    2,   86,    2, 0x0a,
       5,    1,   91,    2, 0x0a,
       8,    1,   94,    2, 0x0a,
      11,    1,   97,    2, 0x0a,
      13,    1,  100,    2, 0x0a,
      15,    2,  103,    2, 0x0a,
      18,    0,  108,    2, 0x0a,
      19,    2,  109,    2, 0x0a,
      20,    0,  114,    2, 0x0a,
      21,    0,  115,    2, 0x0a,
      22,    1,  116,    2, 0x0a,
      24,    5,  119,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   10,
    QMetaType::Void, 0x80000000 | 14,   10,
    QMetaType::Bool, 0x80000000 | 9, 0x80000000 | 16,   10,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 6,    2,    2,    2,    2,    2,

       0        // eod
};

void gameW::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gameW *_t = static_cast<gameW *>(_o);
        switch (_id) {
        case 0: _t->llenarX(); break;
        case 1: _t->llenarY(); break;
        case 2: { bool _r = _t->comp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->changeLabel((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 4: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->dropEvent((*reinterpret_cast< QDropEvent*(*)>(_a[1]))); break;
        case 6: _t->dragEnterEvent((*reinterpret_cast< QDragEnterEvent*(*)>(_a[1]))); break;
        case 7: { bool _r = _t->selectFicha((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< QMimeData*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->cambiaFichas(); break;
        case 9: _t->rellenarFichas((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->generarPalabra(); break;
        case 11: _t->scrabble(); break;
        case 12: _t->rellenarMano((*reinterpret_cast< vector<string>(*)>(_a[1]))); break;
        case 13: _t->dibujar((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< string(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMimeData* >(); break;
            }
            break;
        }
    }
}

const QMetaObject gameW::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gameW.data,
      qt_meta_data_gameW,  qt_static_metacall, 0, 0}
};


const QMetaObject *gameW::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gameW::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gameW.stringdata))
        return static_cast<void*>(const_cast< gameW*>(this));
    return QWidget::qt_metacast(_clname);
}

int gameW::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
