/****************************************************************************
** Meta object code from reading C++ file 'cannonfield.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../helloWidget/cannonfield.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cannonfield.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CannonField_t {
    const uint offsetsAndSize[38];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CannonField_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CannonField_t qt_meta_stringdata_CannonField = {
    {
QT_MOC_LITERAL(0, 11), // "CannonField"
QT_MOC_LITERAL(12, 3), // "hit"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 6), // "missed"
QT_MOC_LITERAL(24, 12), // "angleChanged"
QT_MOC_LITERAL(37, 8), // "newAngle"
QT_MOC_LITERAL(46, 12), // "forceChanged"
QT_MOC_LITERAL(59, 8), // "newForce"
QT_MOC_LITERAL(68, 8), // "canShoot"
QT_MOC_LITERAL(77, 3), // "can"
QT_MOC_LITERAL(81, 8), // "setAngle"
QT_MOC_LITERAL(90, 5), // "angle"
QT_MOC_LITERAL(96, 8), // "setForce"
QT_MOC_LITERAL(105, 5), // "force"
QT_MOC_LITERAL(111, 5), // "shoot"
QT_MOC_LITERAL(117, 9), // "newTarget"
QT_MOC_LITERAL(127, 11), // "setGameOver"
QT_MOC_LITERAL(139, 11), // "restartGame"
QT_MOC_LITERAL(151, 8) // "moveShot"

    },
    "CannonField\0hit\0\0missed\0angleChanged\0"
    "newAngle\0forceChanged\0newForce\0canShoot\0"
    "can\0setAngle\0angle\0setForce\0force\0"
    "shoot\0newTarget\0setGameOver\0restartGame\0"
    "moveShot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CannonField[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    0 /* Public */,
       3,    0,   87,    2, 0x06,    1 /* Public */,
       4,    1,   88,    2, 0x06,    2 /* Public */,
       6,    1,   91,    2, 0x06,    4 /* Public */,
       8,    1,   94,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,   97,    2, 0x0a,    8 /* Public */,
      12,    1,  100,    2, 0x0a,   10 /* Public */,
      14,    0,  103,    2, 0x0a,   12 /* Public */,
      15,    0,  104,    2, 0x0a,   13 /* Public */,
      16,    0,  105,    2, 0x0a,   14 /* Public */,
      17,    0,  106,    2, 0x0a,   15 /* Public */,
      18,    0,  107,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CannonField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CannonField *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->hit(); break;
        case 1: _t->missed(); break;
        case 2: _t->angleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->forceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->canShoot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setForce((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->shoot(); break;
        case 8: _t->newTarget(); break;
        case 9: _t->setGameOver(); break;
        case 10: _t->restartGame(); break;
        case 11: _t->moveShot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CannonField::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CannonField::hit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CannonField::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CannonField::missed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CannonField::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CannonField::angleChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CannonField::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CannonField::forceChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CannonField::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CannonField::canShoot)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject CannonField::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CannonField.offsetsAndSize,
    qt_meta_data_CannonField,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CannonField_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CannonField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CannonField::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CannonField.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CannonField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CannonField::hit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CannonField::missed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CannonField::angleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CannonField::forceChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CannonField::canShoot(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
