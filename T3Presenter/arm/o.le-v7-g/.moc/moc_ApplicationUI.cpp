/****************************************************************************
** Meta object code from reading C++ file 'ApplicationUI.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ApplicationUI.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ApplicationUI.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ApplicationUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      39,   14,   14,   14, 0x0a,
      65,   14,   14,   14, 0x0a,
      86,   80,   14,   14, 0x0a,
     112,   14,   14,   14, 0x0a,
     127,   80,   14,   14, 0x0a,
     158,  153,   14,   14, 0x0a,
     209,   14,   14,   14, 0x0a,
     223,   14,   14,   14, 0x0a,
     249,   14,   14,   14, 0x0a,
     263,   14,   14,   14, 0x0a,
     286,   14,   14,   14, 0x0a,
     308,   14,   14,   14, 0x0a,
     325,   14,   14,   14, 0x0a,
     337,   14,   14,   14, 0x0a,
     357,   14,   14,   14, 0x0a,
     376,   14,   14,   14, 0x0a,
     391,   14,   14,   14, 0x0a,

 // methods: signature, parameters, type, tag, flags
     423,   14,  402,   14, 0x02,
     464,   14,  448,   14, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_ApplicationUI[] = {
    "ApplicationUI\0\0onPresentationChanged()\0"
    "onSystemLanguageChanged()\0onSaveFailed()\0"
    "title\0onSaveSucessfull(QString)\0"
    "onLoadFailed()\0onLoadSucessfull(QString)\0"
    "type\0onDialogFinished(bb::system::SystemUiResult::Type)\0"
    "onHostFound()\0onConnectionSuccessfull()\0"
    "onLoggingIn()\0onConnectionAccepted()\0"
    "onPresentationReady()\0onDisconnected()\0"
    "onStarted()\0onClientConnected()\0"
    "onClientVerified()\0onClientLeft()\0"
    "onClosed()\0PresentationControl*\0"
    "getPresentationControl()\0NetworkControl*\0"
    "getNetworkControl()\0"
};

void ApplicationUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApplicationUI *_t = static_cast<ApplicationUI *>(_o);
        switch (_id) {
        case 0: _t->onPresentationChanged(); break;
        case 1: _t->onSystemLanguageChanged(); break;
        case 2: _t->onSaveFailed(); break;
        case 3: _t->onSaveSucessfull((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onLoadFailed(); break;
        case 5: _t->onLoadSucessfull((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->onDialogFinished((*reinterpret_cast< bb::system::SystemUiResult::Type(*)>(_a[1]))); break;
        case 7: _t->onHostFound(); break;
        case 8: _t->onConnectionSuccessfull(); break;
        case 9: _t->onLoggingIn(); break;
        case 10: _t->onConnectionAccepted(); break;
        case 11: _t->onPresentationReady(); break;
        case 12: _t->onDisconnected(); break;
        case 13: _t->onStarted(); break;
        case 14: _t->onClientConnected(); break;
        case 15: _t->onClientVerified(); break;
        case 16: _t->onClientLeft(); break;
        case 17: _t->onClosed(); break;
        case 18: { PresentationControl* _r = _t->getPresentationControl();
            if (_a[0]) *reinterpret_cast< PresentationControl**>(_a[0]) = _r; }  break;
        case 19: { NetworkControl* _r = _t->getNetworkControl();
            if (_a[0]) *reinterpret_cast< NetworkControl**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ApplicationUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ApplicationUI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ApplicationUI,
      qt_meta_data_ApplicationUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ApplicationUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ApplicationUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ApplicationUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApplicationUI))
        return static_cast<void*>(const_cast< ApplicationUI*>(this));
    return QObject::qt_metacast(_clname);
}

int ApplicationUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
