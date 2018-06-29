#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include <QQuickView>
#include <QtQml>

#include "weapon.h"
#include "WeaponList.h"
#include "weaponmodel.h"

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/WhereIsXur.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    QGuiApplication* app = SailfishApp::application(argc, argv);
    QQuickView *view  = SailfishApp::createView();

    // Check if overwriting bindings with static javascript assignement
    QLoggingCategory::setFilterRules(QStringLiteral("qt.qml.binding.removal.info=true"));

    qmlRegisterType<WeaponModel>("WeaponModel", 1, 0, "WeaponModel" );
    qmlRegisterUncreatableType<WeaponList>("WeaponModel", 1, 0, "WeaponList", QStringLiteral("Don't define WeaponList in QML!!") );
    qmlRegisterUncreatableType<Weapon>("WeaponModel", 1, 0, "Weapon", QStringLiteral("Don't define Weapon in QML!!") );


    WeaponList weapons(":/weapons.json");

    view->rootContext()->setContextProperty("weapons", &weapons);

    view->setSource(SailfishApp::pathTo("qml/WhereIsXur.qml"));
    view->show();

    return app->exec();
}
