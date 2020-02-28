#include "app.h"
#include "bbdd.h"
#include "../user.h"
#include "../photo.h"
#include "../style.h"
#include "../comments.h"
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

///Test de la clase user

TEST_CASE("Usuario")
{
    User usuario("nombre","email","password");
    CHECK(usuario.createUser() == true);

    /// Load: Buscar el usuario a partir de su email y contraseña
   //CHECK(usuario.load("email","password") == usuario);

    /// Load: Buscar el usuario a partir de su nombre
    //CHECK(usuario.loadN("name") == false);

}

///Test de la clase photo

TEST_CASE("Photo")
{

    Photo foto("foto",54,"50px",15,3);
    CHECK(foto.createPhoto() == true);

}

TEST_CASE("Style")
{
     Style estilo;
     CHECK(estilo.Load("roquero") == false);
}


TEST_CASE("Comments")
{
    Comments comentario("me gusta tu foto",15,2);
    CHECK(comentario.CreateComment() == true);
}


























