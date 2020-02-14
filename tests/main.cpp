#define DOCTEST_CONFIG_IMPLEMENT
#include <QCoreApplication>
#include <iostream>
#include "doctest.h"
#include "bbdd.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Bbdd app;

    return a.exec();
}
