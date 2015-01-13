/****************************************************************************
** Meta object code from reading C++ file 'QueueDisp1.h'
**
** Created: Mon Dec 8 21:22:00 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QueueDisp1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QueueDisp1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QueueDisp1[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      19,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      55,   53,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QueueDisp1[] = {
    "QueueDisp1\0\0next()\0addToMyQueue()\0"
    "returnToMainMenu()\0x\0closeEvent(QCloseEvent*)\0"
};

void QueueDisp1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QueueDisp1 *_t = static_cast<QueueDisp1 *>(_o);
        switch (_id) {
        case 0: _t->next(); break;
        case 1: _t->addToMyQueue(); break;
        case 2: _t->returnToMainMenu(); break;
        case 3: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QueueDisp1::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QueueDisp1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QueueDisp1,
      qt_meta_data_QueueDisp1, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QueueDisp1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QueueDisp1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QueueDisp1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QueueDisp1))
        return static_cast<void*>(const_cast< QueueDisp1*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QueueDisp1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
