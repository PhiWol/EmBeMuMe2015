#ifndef NETWORKCONTROL_H_
#define NETWORKCONTROL_H_

#include "Client.h"
#include "Server.h"

class NetworkControl : public QObject {
    Q_OBJECT

    public:
        NetworkControl();
        ~NetworkControl();

        Q_INVOKABLE void startServer();
        Q_INVOKABLE void join(QString address, QString name, QString password);
        Q_INVOKABLE void shutdown();
        Q_INVOKABLE void quit();

    public slots:
        //client slots
        void onHostFound() {
            emit hostFound();
        }
        void onConnected() {
            emit connectionSuccessfull();
        }
        void onLoggingIn() {
            emit loggingIn();
        }
        void onConnectionAccepted() {
            emit connectionAccepted();
        }
        void onPresentationRecieved() {
            emit presentationReady();
        }
        void onDisconnected() {
            emit disconnected();
        }
        //server slots
        void onStarted() {
            emit serverStarted();
        }
        void onClientConnected() {
            emit clientConnected();
        }
        void onClientVerified() {
            emit clientVerified();
        }
        void onClientLeft() {
            emit clientLeft();
        }
        void onClosed() {
            emit serverClosed();
        }

    signals:
        //client signals
        void hostFound();
        void connectionSuccessfull();
        void loggingIn();
        void connectionAccepted();
        void presentationReady();
        void disconnected();
        //server signals
        void serverStarted();
        void clientConnected();
        void clientVerified();
        void clientLeft();
        void serverClosed();

    private:
        Client* client;
        Server* server;
};

#endif /* NETWORKCONTROL_H_ */
