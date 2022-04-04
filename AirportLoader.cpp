#include "AirportLoader.h"
#include <cmath>

AirportLoader::AirportLoader() {
    flight = "";
    start_point = "";
    end_point = "";
    weight_value = 0.0;
}

AirportLoader::AirportLoader(string flight_, string start_, string end_) {
    flight = flight_;
    start_point = start_;
    end_point = end_;
    weight_value = 0.0;
}

string AirportLoader::getFlight() const {
    string return_value = flight;
    return return_value;
}

void AirportLoader::setFlight(string flight_) {
    flight = flight_;
}

string AirportLoader::getStart() const {
    string return_value = start_point;
    return return_value;
}

void AirportLoader::setStart(string start_point_) {
    start_point = start_point_;
}

string AirportLoader::getEnd() const {
    string return_value = end_point;
    return return_value;
}

void AirportLoader::setEnd(string end_point_) {
    end_point = end_point_;
}

double AirportLoader::getWeight() {
    double return_value = weight_value;
    return return_value;
}

double AirportLoader::findDistance(double first_ns, double first_ew, double second_ns, double second_ew) {
    // Using Haversine formula --> https://en.wikipedia.org/wiki/Haversine_formula
    // Finding distance using formula provided in link above
    // first_ns and second_ns represent latitude
    // first_ew and second_ew represent longitude
    double distance = 0.0; // Return value
    double radius = 3963.0; // Radius of Earth in miles -> https://www.space.com/17638-how-big-is-earth.html#:~:text=The%20radius%20of%20Earth%20at,13%20miles%20(22%20km)
    double radius_2 = 2 * radius;
    double diff_ns = (first_ns - second_ns) / 2;
    double sin_diff_ns = pow((sin(diff_ns)), 2);
    double diff_ew = (first_ew - second_ew) / 2;
    double sin_diff_ew = pow((sin(diff_ew)), 2);
    double cos_ns_1 = cos(first_ns);
    double cos_ns_2 = cos(second_ns);
    double sqrt_val = sqrt(sin_diff_ns + (cos_ns_1 * cos_ns_2) + sin_diff_ew);
    double asin_val = asin(sqrt_val);
    distance = radius_2 * asin_val;
    return distance;
}

void AirportLoader::setWeight(double first_ns, double first_ew, double second_ns, double second_ew) {
    // This function, along with findDistance, can be used for Djikstra and perhaps between connectedness
    weight_value = findDistance(first_ns, first_ew, second_ns, second_ew);
}