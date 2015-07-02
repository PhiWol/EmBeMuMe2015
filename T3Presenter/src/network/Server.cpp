/*
 * Server.cpp
 *
 *  Created on: 07.06.2015
 *      Author: Philip
 */

#include "server.h"
#include <iostream>
#include <QDebug>
using namespace std;

Server::Server(): QObject() {
    server = new QTcpServer();
    idCounter = 0;
    password = "";
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

Server::~Server() {
    server->close();
}

void Server::listen() {
    server->listen(QHostAddress::Any, 8888);
    emit listening();
    qDebug() << "Server starts listening ..." << endl;
}

void Server::stop() {
    server->close();
    emit closing();
}

void Server::setPassword(QString password) {
    Server::password = password;
}

QString Server::getPassword() {
    return password;
}

void Server::acceptConnection() {
    qDebug() << ">>server accepts connection ..." << endl;
    // getting socket
    QTcpSocket* socket = server->nextPendingConnection();
    //connecting the new data signal to read function
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(recieveMessage()));
    qDebug() << ">>server connects signals" << endl;
    // init new client
    Client* client = new Client();
    client->setSocket(socket);
    client->setID(idCounter++);
    clientList.append(client);
    qDebug() << ">>server creates client" << endl;

    // sending id to client
    QByteArray data;
    data.append("@id/"+client->getID());
    client->getSocket()->write(data);
    qDebug() << ">>server writes id" << endl;

    emit connectionAccepted();
    qDebug() << "server accepts connection ..." << endl;
}

void Server::recieveMessage() {
    for(int i = 0; i < clientList.size(); i++) {
        Client* client = clientList.at(i);
        QTcpSocket* socket = client->getSocket();
        QString line;
        line = socket->readAll();
        processMessage(line);
    }
}

void Server::processMessage(QString message) {
    QStringList list = message.split("/", QString::SkipEmptyParts);
    QString command = list.at(0);
    if(command == "@login") {
        QString idString = list.at(1);
        QString name = list.at(2);
        QString password = list.at(3);
        bool* ok = false;
        qint32 id = idString.toInt(ok, 10);
        verifyClient(id, name, password);
    }
}

void Server::verifyClient(qint32 id, QString name, QString password) {
    //search for client
    for(int i = 0; i < clientList.size(); i++) {
        Client* client = clientList.at(i);
        if(client->getID() == id) {
            //setting name and password
            client->setName(name);
            client->setPassword(password);
            client->getSocket()->flush();
            //checking password
            if(Server::password == password) {
                //sending presentation data
                writePresentation(client);
                emit clientVerified();
                qDebug() << "verified" << endl;
            }else {
                client->getSocket()->disconnectFromHost();
                clientList.removeOne(client);
            }
        }
    }
}

void Server::writePresentation(Client* client) {
    QByteArray p;
    p.append("@presentation/");
    p.append("TestPresentationString");
    client->getSocket()->write(p);
}




