#include "app.h"
#include "bbdd.h"
#include "../user.h"
#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QSqlQuery>

App::App(QObject *parent) : QObject(parent)
{
    QTimer::singleShot(0, this, SLOT(run()));
}

void App::run()
{
    qDebug() << "running...";

    m_context.run(); // run
    if (m_context.shouldExit())
    {
        QCoreApplication::quit();
    } // end if

}

TEST_CASE("base datos #0")
{
    Bbdd db;
    int ok = db.init();

    if (ok)
    {
        qDebug() << "DB UP AND RUNNING";

        SUBCASE("Insertar #0")
        {
            CHECK( db.insert() == true );
        }

        SUBCASE("Insertar #0")
        {
            CHECK( db.insert() == true );
        }
    }
    else
    {
        qDebug() << db.lastError().text();

    } // end if

}

TEST_CASE("Usuario")
{
    User usuario("nombre","email","password");
    CHECK(usuario.createUser() == true);

}





















