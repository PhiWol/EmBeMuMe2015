#include "ApplicationUI.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>

using namespace bb::cascades;

ApplicationUI::ApplicationUI() : QObject()
{
    // prepare the localization
    m_pTranslator = new QTranslator(this);
    m_pLocaleHandler = new LocaleHandler(this);

    // connecting the localization
    bool res = QObject::connect(m_pLocaleHandler, SIGNAL(systemLanguageChanged()), this, SLOT(onSystemLanguageChanged()));
    Q_ASSERT(res);

    // initial load
    onSystemLanguageChanged();

    // prepare the DialogSystem
    m_Dialog = new bb::system::SystemDialog();

    //INIT PRESENTATIONCONTROL///////////////////////////////////////////////////////////////////////////////////////
    m_PresentationControl = new PresentationControl();
    // connecting the presentation save function
    QObject::connect(m_PresentationControl, SIGNAL(saveSucessfull(QString)), this, SLOT(onSaveSucessfull(QString)));
    QObject::connect(m_PresentationControl, SIGNAL(saveFailed(void)), this, SLOT(onSaveFailed()));
    // connecting the presentation load function
    QObject::connect(m_PresentationControl, SIGNAL(loadSucessfull(QString)), this, SLOT(onLoadSucessfull(QString)));
    QObject::connect(m_PresentationControl, SIGNAL(loadFailed(void)), this, SLOT(onLoadFailed()));
    //connecting changed listener
    QObject::connect(m_PresentationControl, SIGNAL(presentationChanged()), this, SLOT(onPresentationChanged()));
    //END INIT PRESENTATIONCONTROL///////////////////////////////////////////////////////////////////////////////////////

    //INIT NETWORKCONTROL///////////////////////////////////////////////////////////////////////////////////////////////
    m_NetworkControl = new NetworkControl();
    //connecting server signals
    QObject::connect(m_NetworkControl, SIGNAL(serverStarted()), this, SLOT(onStarted()));
    QObject::connect(m_NetworkControl, SIGNAL(clientConnected()), this, SLOT(onClientConnected()));
    QObject::connect(m_NetworkControl, SIGNAL(clientVerified()), this, SLOT(onClientVerified()));
    QObject::connect(m_NetworkControl, SIGNAL(clientLeft()), this, SLOT(onClientLeft()));
    QObject::connect(m_NetworkControl, SIGNAL(serverClosed()), this, SLOT(onClosed()));
    //connecting client signals
    QObject::connect(m_NetworkControl, SIGNAL(hostFound()), this, SLOT(onHostFound()));
    QObject::connect(m_NetworkControl, SIGNAL(connectionSuccessfull()), this, SLOT(onConnectionSuccessfull()));
    QObject::connect(m_NetworkControl, SIGNAL(loggingIn()), this, SLOT(onLoggingIn()));
    QObject::connect(m_NetworkControl, SIGNAL(presentationReady()), this, SLOT(onPresentationReady()));
    QObject::connect(m_NetworkControl, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    //END INIT NETWORKCONTROL///////////////////////////////////////////////////////////////////////////////////////////

    //INIT QML///////////////////////////////////////////////////////////////////////////////////////////////////////////
    qmlRegisterType<PresentationControl>("my.library", 1, 0, "PresentationControl");
    qmlRegisterType<NetworkControl>("my.library", 1, 0, "NetworkControl");
    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create("asset:///MainMenuPage.qml").parent(this);
    // Create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();
    // Passing the Objects for access to c++ classes
    //!WORKAROUND! TODO pass the propertymap to qml
    qml->setContextProperty("_application", this);
    // Set created root object as the application scene
    Application::instance()->setScene(root);
    //END INIT QML///////////////////////////////////////////////////////////////////////////////////////////////////////////
}

PresentationControl* ApplicationUI::getPresentationControl() {
    return m_PresentationControl;
}

NetworkControl* ApplicationUI::getNetworkControl() {
    return m_NetworkControl;
}

void ApplicationUI::onPresentationChanged() {

}

//LANGUAGE//////////////////////////////////////////////////////////////////////////
void ApplicationUI::onSystemLanguageChanged()
{
    QCoreApplication::instance()->removeTranslator(m_pTranslator);
    // Initiate, load and install the application translation files.
    QString locale_string = QLocale().name();
    QString file_name = QString("T3Presenter_%1").arg(locale_string);
    if (m_pTranslator->load(file_name, "app/native/qm")) {
        QCoreApplication::instance()->installTranslator(m_pTranslator);
    }
}
//END LANGUAGE//////////////////////////////////////////////////////////////////////

//PRESENTATIONCONTROL-DIALOGS//////////////////////////////////////////////////////////////////////
void ApplicationUI::onSaveFailed() {
    m_Dialog = new bb::system::SystemDialog("OK");
    m_Dialog->setTitle("Failed!");
    m_Dialog->setBody("Your save request failed!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onSaveSucessfull(QString title) {
    m_Dialog = new bb::system::SystemDialog("OK");
    m_Dialog->setTitle("Sucessfull!");
    m_Dialog->setBody("Presentation "+title+" was sucessfully saved!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onLoadFailed() {
    m_Dialog = new bb::system::SystemDialog("OK");
    m_Dialog->setTitle("Failed!");
    m_Dialog->setBody("Your load request failed!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onLoadSucessfull(QString title) {
    m_Dialog = new bb::system::SystemDialog("OK");
    m_Dialog->setTitle("Sucessfull!");
    m_Dialog->setBody("Presentation "+title+" was sucessfully loaded!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
//END PRESENTATIONCONTROL-DIALOGS/////////////////////////////////////////////////////////////////////

//NETWORKCONTROL-DIALOGS//////////////////////////////////////////////////////////////////////////////
void ApplicationUI::onStarted() {
    m_Dialog = new bb::system::SystemDialog();
    m_Dialog->setTitle("Presentation started!");
    m_Dialog->setBody("Presentation was sucessfully started!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onClientConnected() {
    m_Dialog = new bb::system::SystemDialog();
    m_Dialog->setTitle("Client connected!");
    m_Dialog->setBody("A Client tries to join your presentation!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onClientVerified() {
    m_Dialog = new bb::system::SystemDialog();
    m_Dialog->setTitle("Client verified!");
    m_Dialog->setBody("A Client successfully joined your presentation!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onClientLeft() {
    m_Dialog = new bb::system::SystemDialog();
    m_Dialog->setTitle("Client left!");
    m_Dialog->setBody("A Client left your presentation!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onClosed() {
    m_Dialog = new bb::system::SystemDialog();
    m_Dialog->setTitle("Presentation aborted!");
    m_Dialog->setBody("Your presentation is now closed!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onHostFound() {
    m_Dialog = new bb::system::SystemDialog();
    m_Dialog->setTitle("Host found!");
    m_Dialog->setBody("The host you selected was found!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onConnectionSuccessfull() {
    m_Dialog = new bb::system::SystemDialog();
    m_Dialog->setTitle("Connection successfull!");
    m_Dialog->setBody("You successfully connected to a host!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onLoggingIn() {
    m_Dialog = new bb::system::SystemDialog();
    m_Dialog->setTitle("Logging in!");
    m_Dialog->setBody("The host is validating your identity!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onConnectionAccepted() {
    m_Dialog = new bb::system::SystemDialog();
    m_Dialog->setTitle("Accepted!");
    m_Dialog->setBody("You successfully logged in!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onPresentationReady() {
    m_Dialog = new bb::system::SystemDialog();
    m_Dialog->setTitle("Presentation ready!");
    m_Dialog->setBody("You successfully downloaded the presentation from the host!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
void ApplicationUI::onDisconnected() {
    m_Dialog = new bb::system::SystemDialog();
    m_Dialog->setTitle("Disconnected!");
    m_Dialog->setBody("You disconnected from the host!");
    m_Dialog->show();
    QObject::connect(m_Dialog, SIGNAL(finished(bb::system::SystemUiResult::Type)), this, SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
}
//END NETWORKCONTROL-DIALOGS//////////////////////////////////////////////////////////////////////////////

void ApplicationUI::onDialogFinished(bb::system::SystemUiResult::Type type) {
    m_Dialog->deleteLater();
}
