/****************************************************************************
** Meta object code from reading C++ file 'RatingScreen.h'
**
** Created: Mon Dec 8 21:22:01 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RatingScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RatingScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RatingScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   14,   13,   13, 0x08,
      41,   13,   13,   13, 0x08,
      48,   13,   13,   13, 0x08,
      55,   13,   13,   13, 0x08,
      64,   13,   13,   13, 0x08,
      72,   13,   13,   13, 0x08,
      80,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RatingScreen[] = {
    "RatingScreen\0\0x\0closeEvent(QCloseEvent*)\0"
    "oneS()\0twoS()\0threeS()\0fourS()\0fiveS()\0"
    "noRatingS()\0"
};

void RatingScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RatingScreen *_t = static_cast<RatingScreen *>(_o);
        switch (_id) {
        case 0: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 1: _t->oneS(); break;
        case 2: _t->twoS(); break;
        case 3: _t->threeS(); break;
        case 4: _t->fourS(); break;
        case 5: _t->fiveS(); break;
        case 6: _t->noRatingS(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RatingScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RatingScreen::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RatingScreen,
      qt_meta_data_RatingScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RatingScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RatingScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RatingScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RatingScreen))
        return static_cast<void*>(const_cast< RatingScreen*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RatingScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
