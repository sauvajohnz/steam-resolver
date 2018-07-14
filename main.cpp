#include "application_graphique.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Application steam_resolver;
    steam_resolver.show();


    return app.exec();
}
