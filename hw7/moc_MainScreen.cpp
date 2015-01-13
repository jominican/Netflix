/****************************************************************************
** Meta object code from reading C++ file 'MainScreen.h'
**
** Created: Mon Dec 8 21:21:56 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainScreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      26,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     113,   11,   11,   11, 0x08,
     129,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,
     147,   11,   11,   11, 0x08,
     158,  156,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainScreen[] = {
    "MainScreen\0\0returnMovie()\0rentMovie()\0"
    "deleteFromQueue()\0moveToBack()\0refresh()\0"
    "searchByTitle()\0searchByKeyword()\0"
    "searchByActor()\0view()\0changing()\0"
    "logout()\0x\0closeEvent(QCloseEvent*)\0"
};

void MainScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainScreen *_t = static_cast<MainScreen *>(_o);
        switch (_id) {
        case 0: _t->returnMovie(); break;
        case 1: _t->rentMovie(); break;
        case 2: _t->deleteFromQueue(); break;
        case 3: _t->moveToBack(); break;
        case 4: _t->refresh(); break;
        case 5: _t->searchByTitle(); break;
        case 6: _t->searchByKeyword(); break;
        case 7: _t->searchByActor(); break;
        case 8: _t->view(); break;
        case 9: _t->changing(); break;
        case 10: _t->logout(); break;
        case 11: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainScreen::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainScreen,
      qt_meta_data_MainScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainScreen))
        return static_cast<void*>(const_cast< MainScreen*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
