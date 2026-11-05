// /cd/ Provides the application entry point and pre-loaded route data.
#include "BusRoute.h"
#include "Menu.h"
#include "Stop.h"

int main()
{
    BusRoute route;

    // Pre-loaded route. Stops 204 and 203 are in the wrong order.
    route.AddAtEnd(new Stop(201, "Central Terminal"));
    route.AddAtEnd(new Stop(202, "City Hospital"));
    route.AddAtEnd(new Stop(204, "University Gate"));
    route.AddAtEnd(new Stop(203, "Railway Station"));
    route.AddAtEnd(new Stop(205, "Airport"));

    RunMenu(route);

    return 0;
}