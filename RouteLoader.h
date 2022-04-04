#include "FileReader.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class AirportLoader; // Using AirportLoader in RouteLoader
class RouteLoader {
public:
    RouteLoader(); // Constructor to set default values for all private variables
    RouteLoader(string flight_, double ns, double ew);
    void addConnection(AirportLoader connect); // Adds connection (edge) between airports as a route
    void removeConnection(AirportLoader connect); // Removes connection (edge) between airports

private:
    
};