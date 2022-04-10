#pragma once
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

class FileReader {
public:
    FileReader();
    void readAirport(string airport);
    void readRoute(string route);
    map<string, double> getDistance();
    map<string, bool> isTraveled();
    vector<string> routesTaken();
    // Need to continue adding functions as algorithms are added

private:
    map<string, double> totalDistance;
    map<string, bool> airportsSeen;
    vector<string> takenRoutes;
};