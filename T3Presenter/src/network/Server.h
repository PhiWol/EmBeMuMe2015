/*
 * Server.h
 *
 *  Created on: 07.06.2015
 *      Author: Philip
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <QtNetwork> // Server.h
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "src/source/Presentation.hpp"
#include "Client.h"



class Server: public QObject {
    Q_OBJECT

    public:
        Server();
        ~Server();
        void listen();
        void stop();

        void setPassword(QString password);
        QString getPassword();

        void processMessage(QString message);
        void verifyClient(qint32 id, QString name, QString password);
        void writePresentation(Client* client);

    public slots:
        void acceptConnection();
        void recieveMessage();

    signals:
        //UI signals
        void listening();
        void connectionAccepted();
        void clientVerified();
        void clientLeft();
        void closing();

    private:
        QTcpServer* server;
        QList<Client*> clientList;
        qint32 idCounter;
        QString password;
};


#endif /* SERVER_H_ */
