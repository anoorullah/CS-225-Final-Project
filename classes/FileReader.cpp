#include "FileReader.h"
#include "Edge.h"
#include <sstream>
#include "Routes.h"

FileReader::FileReader() {
    // Setting default values for private variables
    map<string, double> totalDistance;
    map<string, bool> airportsSeen;
    vector<string> takenRoutes;
}

void FileReader::readAirport(string airport) {
    // Read in file for airports
    ifstream airportFile;
    airportFile.open(airport); // Opening the file for airports
    string airportName;
    for(int i = 0; i <= 7697; ++i) { // Cycling through number of airports
        getline(airportFile, airportName); // Grabbing each line from airportFile
        stringstream stream(airportName); // Mkaes a stringstream our of each line grabbed
        int j = 0;
        vector<string> airportVector;
        while(!stream.bad()) { // While we do not encounted a bad stringstream
            string smallerStream;
            getline(stream, smallerStream, ','); // Separates each line based off commas
            airportVector.push_back(smallerStream); // Add each smallerStream to vector of strings we created
            ++j;
        }
        if(j <= 13) { // If we are within the bounds of the iteration
            continue; // continue
        }
        Route* current = new Route();
        if(airportVector.length() != 2) {
            current->setSrc(airportVector[4]);
        } else {
            current->setSrc(airportVector[5]);
        }
        
    }
}

void FileReader::readRoute(string route) {
    // Following same algo from airport parser for route parser
    ifstream routeFile; // Reading in route file
    routeFile.open(route); // Opens based off name of route file
    string routeFound; // Will represent each route in the route file
    int i = 0; // Variable used for iteration
    vector<string> routeVector; // Vector storing each route
    // getline(routeFile, routeFound); // If I included this, this would remove the first line of the file
    // We need the first line! Use a while loop to iterate through each line of the file
    while(getline(routeFile, routeFound)) {
        routeVector.push_back(routeFound); // Each route is added to the end of routeVector
        ++i; // Increase iterable variable
    }
    // Need to continue working to separate different parts of file
}

map<string, double> FileReader::getDistance() {
    return totalDistance;
}

map<string, bool> FileReader::isTraveled() {
    return airportsSeen;
}

vector<string> FileReader::routesTaken() {
    return takenRoutes;
}