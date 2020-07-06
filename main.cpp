#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "myclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MyClass my;
    engine.rootContext()->setContextProperty("myClass",&my); //bind to C++ class for QML call

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QObject* rootObject;
    rootObject = engine.rootObjects().first();

    QObject::connect(&my, SIGNAL(sig_disp(QVariant)), rootObject, SLOT(disp(QVariant))); //bind to QML function for C++ call


    my.SendText();


    return app.exec();
}
