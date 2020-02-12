#include "designapp.h"
#include "doctest.h"
#include "basedatos.h"

DesignApp::DesignApp()
{

}
int DesignApp::suma()
{
    return  1;
}

TEST_CASE("basedatos") {

    BaseDatos bd;
    CHECK(bd.init() == true);

}
