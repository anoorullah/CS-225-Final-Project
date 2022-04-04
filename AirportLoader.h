#include "FileReader.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class FileReader; // Using FileReader in AirportLoader
class AirportLoader {
public:
    AirportLoader(); // Constructor to set default values for all private variables
    AirportLoader(string flight_, string start_, string end_); 
    // Constructor taking values of flight, starting airport, and ending airport
    string getFlight() const; // Gets flight
    void setFlight(string flight_); // Sets flight
    string getStart() const; // Gets starting airport
    void setStart(string start_point_); // Sets starting airport
    string getEnd() const; // Gets ending airport
    void setEnd(string end_point_); // Sets ending airport
    double getWeight(); // Gets the weight of the edge (not const because will change for each edge)
    double findDistance(double first_ns, double first_ew, double second_ns, double second_ew);
    // Finds spherical distance using Haversine formula
    void setWeight(double first_ns, double first_ew, double second_ns, double second_ew); 
    // Setting spherical weights as suggested by Amit
    // ns stands for north-south and ew stands for east-west
private:
    string flight;
    string start_point;
    string end_point;
    double weight_value; // Stores the weight of each edge
};