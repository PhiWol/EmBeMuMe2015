#ifndef PRESENTERUI_HPP_
#define PRESENTERUI_HPP_

#include <QObject>
#include <QStringList>
#include <bb/cascades/AbstractPane>

#include "source/PresentationControl.hpp"
#include "network/NetworkControl.h"


namespace bb
{
    namespace cascades
    {
        class LocaleHandler;
    }
}

class QTranslator;

/*!
 * @brief Application UI object
 *
 * Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class ApplicationUI : public QObject
{
    Q_OBJECT
    public:
        ApplicationUI();
        virtual ~ApplicationUI() {}

        Q_INVOKABLE PresentationControl* getPresentationControl();
        Q_INVOKABLE NetworkControl* getNetworkControl();

    public slots:
        void onPresentationChanged();
        void onSystemLanguageChanged();
        //PresentationControl dialog slots
        void onSaveFailed();
        void onSaveSucessfull(QString title);
        void onLoadFailed();
        void onLoadSucessfull(QString title);
        void onDialogFinished(bb::system::SystemUiResult::Type type);
        //NetworkControl dialog slots
        void onHostFound();
        void onConnectionSuccessfull();
        void onLoggingIn();
        void onConnectionAccepted();
        void onPresentationReady();
        void onDisconnected();
        void onStarted();
        void onClientConnected();
        void onClientVerified();
        void onClientLeft();
        void onClosed();

    private:
        QTranslator* m_pTranslator;
        bb::cascades::LocaleHandler* m_pLocaleHandler;
        PresentationControl* m_PresentationControl;
        NetworkControl* m_NetworkControl;
        bb::system::SystemDialog* m_Dialog;
};

#endif
