/*
 * Client.cpp
 *
 *  Created on: 07.06.2015
 *      Author: Philip
 */

// Client.cpp – class definition
#include "client.h"
#include <QHostAddress>

Client::Client(): QObject() {
    id = 0;
    socket = new QTcpSocket();
}

Client::~Client() {
    socket->close();
}

void Client::setSocket(QTcpSocket* socket) {
    Client::socket = socket;
}

QTcpSocket* Client::getSocket() {
    return socket;
}
void Client::setName(QString name) {
    Client::name = name;
}

QString Client::getName() {
    return name;
}

void Client::setPassword(QString password) {
    Client::password = password;
}

QString Client::getPassword() {
    return password;
}

void Client::setID(qint32 id) {
    Client::id = id;
}

qint32 Client::getID() {
    return id;
}

void Client::connect(QString address, quint16 port) {
    //connecting signals for UI
    QObject::connect(socket, SIGNAL(connected()), this, SLOT(onConnected()));
    //QObject::connect(socket, SIGNAL(hostFound()), this, SLOT(onHostFound()));
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    QObject::connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
    // connecting read function to new data signal
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(recieveMessage()));
    // and the socket to host
    QHostAddress addr(address);
    socket->connectToHost(addr, port);
    qDebug() << "connecting to Server" << endl;
}

void Client::recieveMessage() {
    //recieve message from socket
    QString line = socket->readAll();
    //precess message;
    processMessage(line);
}

void Client::processMessage(QString message) {
    qDebug() << "processing message from Server : "+message << endl;
    QStringList list = message.split("/", QString::SkipEmptyParts);
    QString command = list.at(0);
    if(command == "@id") {
            QString idString = list.at(1);
            bool* ok;
            qint32 idInt = idString.toInt(ok, 10);
            Client::setID(idInt);
            socket->flush();
            login(id, name, password);
        }else if(command =="@presentation") {
            socket->flush();
            emit successfullJoin();
        }
}

void Client::login(qint32 id, QString name, QString password) {
    QByteArray data;
    data.append("@login/");
    data.append(id+"/");
    data.append(name+"/");
    data.append(password);
    socket->write(data);
    emit loggingIn();
    qDebug() << "logging in" << endl;
}

void Client::onConnected() {
   emit connected();
}

void Client::onHostFound() {
    emit hostFound();
}

void Client::recievePresentation() {
    emit presentationRecieved();
}

void Client::onDisconnected() {
    emit disconnected();
}

void Client::onError(QAbstractSocket::SocketError) {

}






