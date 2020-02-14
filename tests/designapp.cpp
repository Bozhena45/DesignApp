#include "designapp.h"
#include "doctest.h"
#include "bbdd.h"

DesignApp::DesignApp()
{

}
int DesignApp::suma()
{
    return  1;
}

TEST_CASE("basedatos") {

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
