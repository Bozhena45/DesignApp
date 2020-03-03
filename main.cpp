#include <iostream>
#include "server.h"


int main(int argc, char *argv[])
{

    ///Traducciones:
    QCoreApplication a(argc,argv);
    QTranslator myAppTranslator;
    if ( myAppTranslator.load("ServidorDesignApp_es_ES"))
    {
        a.installTranslator(&myAppTranslator);
    }

    Server server;

    return server.StartServer(9990);

}
