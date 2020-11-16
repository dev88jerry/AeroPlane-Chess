#include <QApplication>
#include "principalwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PrincipalWindow mainWindow;

    mainWindow.show();

    return app.exec();
}
