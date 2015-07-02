/*
 * Client.h
 *
 *  Created on: 07.06.2015
 *      Author: Philip
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <QtNetwork> // Client.h
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include "src/source/Presentation.hpp"

class Client : public QObject {
    Q_OBJECT

    public:
    Client();
    ~Client();

    void connect(QString address, quint16 port);
    void processMessage(QString message);

    void setName(QString name);
    QString getName();
    void setPassword(QString password);
    QString getPassword();
    void setSocket(QTcpSocket* socket);
    QTcpSocket* getSocket();
    void setID(qint32 id);
    qint32 getID();

    public slots:
        //
        void login(qint32 id, QString name, QString password);
        void recievePresentation();
        void recieveMessage();

        //UI tunnel slots
        void onDisconnected();
        void onHostFound();
        void onConnected();
        void onError(QAbstractSocket::SocketError);

    signals:
        //UI signals
        void hostFound();
        void connected();
        void loggingIn();
        void successfullJoin();
        void disconnected();
        void presentationRecieved();

    private:
        QTcpSocket* socket;
        qint32 id;
        QString name;
        QString password;
};

#endif /* CLIENT_H_ */
