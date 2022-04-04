#include "FileReader.h"

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
        } // Otherwise, end the function
    }
}

void FileReader::readRoute(string route) {

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