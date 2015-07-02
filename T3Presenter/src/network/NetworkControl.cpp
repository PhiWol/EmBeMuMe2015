/*
 * NetworkControl.cpp
 *
 *  Created on: 28.06.2015
 *      Author: Philip
 */
#include "NetworkControl.h"

NetworkControl::NetworkControl() {
    client = new Client();
    QObject::connect(client, SIGNAL(connected()), this, SLOT(onConnected()));
    QObject::connect(client, SIGNAL(hostFound()), this, SLOT(onHostFound()));
    QObject::connect(client, SIGNAL(loggingIn()), this, SLOT(onLoggingIn()));
    QObject::connect(client, SIGNAL(successfullJoin()), this, SLOT(onConnectionAccepted()));
    QObject::connect(client, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    QObject::connect(client, SIGNAL(presentationRecieved()), this, SLOT(onPresentationRecieved()));
    server = new Server();
    QObject::connect(server, SIGNAL(listening()), this, SLOT(onStarted()));
    QObject::connect(server, SIGNAL(connectionAccepted()), this, SLOT(onClientConnected()));
    QObject::connect(server, SIGNAL(clientVerified()), this, SLOT(onClientVerified()));
    QObject::connect(server, SIGNAL(clientLeft()), this, SLOT(onClientLeft()));
    QObject::connect(server, SIGNAL(closing()), this, SLOT(onClosed()));
}
NetworkControl::~NetworkControl() {
    server->stop();
}
void NetworkControl::startServer() {
    server->listen();
}
void NetworkControl::shutdown() {
    server->stop();
}
void NetworkControl::join(QString address, QString name, QString password) {
    client->setName(name);
    client->setPassword(password);
    client->connect(address, 8888);
}
void NetworkControl::quit() {
    client->getSocket()->close();
}


