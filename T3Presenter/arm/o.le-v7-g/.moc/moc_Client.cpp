/****************************************************************************
** Meta object code from reading C++ file 'Client.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/network/Client.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Client[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      20,    7,    7,    7, 0x05,
      32,    7,    7,    7, 0x05,
      44,    7,    7,    7, 0x05,
      62,    7,    7,    7, 0x05,
      77,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     117,  100,    7,    7, 0x0a,
     147,    7,    7,    7, 0x0a,
     169,    7,    7,    7, 0x0a,
     186,    7,    7,    7, 0x0a,
     203,    7,    7,    7, 0x0a,
     217,    7,    7,    7, 0x0a,
     231,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Client[] = {
    "Client\0\0hostFound()\0connected()\0"
    "loggingIn()\0successfullJoin()\0"
    "disconnected()\0presentationRecieved()\0"
    "id,name,password\0login(qint32,QString,QString)\0"
    "recievePresentation()\0recieveMessage()\0"
    "onDisconnected()\0onHostFound()\0"
    "onConnected()\0onError(QAbstractSocket::SocketError)\0"
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Client *_t = static_cast<Client *>(_o);
        switch (_id) {
        case 0: _t->hostFound(); break;
        case 1: _t->connected(); break;
        case 2: _t->loggingIn(); break;
        case 3: _t->successfullJoin(); break;
        case 4: _t->disconnected(); break;
        case 5: _t->presentationRecieved(); break;
        case 6: _t->login((*reinterpret_cast< qint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->recievePresentation(); break;
        case 8: _t->recieveMessage(); break;
        case 9: _t->onDisconnected(); break;
        case 10: _t->onHostFound(); break;
        case 11: _t->onConnected(); break;
        case 12: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Client::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Client,
      qt_meta_data_Client, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Client::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Client))
        return static_cast<void*>(const_cast< Client*>(this));
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Client::hostFound()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Client::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Client::loggingIn()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Client::successfullJoin()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Client::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Client::presentationRecieved()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
