#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "modello.h"
#include "filtro.h"
int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    modello mioModello;
    //riempio il modello
    for(int i=0;i<10;i++){

        mioModello.addRicetta("Pane","red",5,false);
        mioModello.addRicetta("Ric Utente","orange",3,true);

    }


    Filtro filtroSuModello;
    filtroSuModello.setSourceModel(&mioModello);
    //filtroSuModello.setFilterRole(mioModello.NomeRicetta);


    engine.rootContext()->setContextProperty("myModelFiltrato",&filtroSuModello);
    engine.rootContext()->setContextProperty("myModel",&mioModello);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
