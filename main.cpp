#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "GoogleClient.hpp"
#include "Stubs.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // first
    Screenshot s;
    WindowCapture w;
    s.save();
    w.save();

    //second
    GoogleClient c;
    c.helloGoogle();

    //third
    QQmlApplicationEngine engine(QUrl(u"qrc:/main.qml"_qs));
    engine.addImportPath("qrc:/");
    return app.exec();
}
