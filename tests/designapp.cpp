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

    Bbdd bd;
    CHECK(bd.init() == true);

}
