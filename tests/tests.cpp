#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>


#include "../Airport.h"
#include "../airport_graph.h"
#include "../BFS.h"
#include "../Djikstras.h"

#include "../catch/catch.hpp"


using namespace std;



TEST_CASE("Testing Airport constructor with vector") { 

    unordered_map<string, Airport> vertices;
    cout<<"Testing vector constructor with London Heathrow airport"<<endl;
    vector<string> airport_data = {"507","London Heathrow Airport","London","United Kingdom", "", "", "51.4706", "-0.461941"};
    vertices["London Heathrow Airport"] = Airport(airport_data);
    int ID = vertices["London Heathrow Airport"].getAirportID();
    string Name = vertices["London Heathrow Airport"].getAirportName();
    string City = vertices["London Heathrow Airport"].getAirportCity();
    string Country = vertices["London Heathrow Airport"].getAirportCountry();
    int Latitude = (int)vertices["London Heathrow Airport"].getAirportLatitude();
    int Longitude = (int)vertices["London Heathrow Airport"].getAirportLongitude();

    REQUIRE(507 == ID);
    REQUIRE("London Heathrow Airport" == Name);
    REQUIRE("London" == City);
    REQUIRE("United Kingdom" == Country);
    REQUIRE(51 == Latitude);
    REQUIRE(0 == Longitude);


}


TEST_CASE("Testing Airport constructor with string") { 

    cout<<"Testing string constructor with goroka airport"<<endl;
    unordered_map<string, Airport> vertices;
    string goroka = "1,\"Goroka Airport\",\"Goroka\",\"Papua New Guinea\",\"GKA\",\"AYGA\",-6.081689834590001,145.391998291,5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"";
    vertices["Goroka Airport"] = Airport(goroka);
    int ID = (vertices["Goroka Airport"].getAirportID());
    string Name = (vertices["Goroka Airport"].getAirportName());
    string City = (vertices["Goroka Airport"].getAirportCity());
    string Country = (vertices["Goroka Airport"].getAirportCountry());
    int Latitude = (int)vertices["Goroka Airport"].getAirportLatitude();
    int Longitude = (int)vertices["Goroka Airport"].getAirportLongitude();
    
    REQUIRE(1 == ID);
    REQUIRE("Goroka Airport" == Name);
    REQUIRE("Goroka" == City);
    REQUIRE("Papua New Guinea" == Country);
    REQUIRE(-6 == Latitude);
    REQUIRE(145 == Longitude);
}

TEST_CASE("Testing constructing whole graph") {
    string airportFile = "airports.dat";
    string routesFile = "routes.dat";
    Graph airportGraph(airportFile, routesFile);
    unordered_map<int, Airport> airportMap = airportGraph.getVertices();
    cout << "Number of airports: " << airportMap.size() <<endl;

    //printing out all flights departing from O'Hare, Newark and Beijing airport
    for(auto it = airportMap.begin(); it != airportMap.end(); ++it){
        //cout << "Airport ID: " << it->first <<endl;
        if(it->first == 3830 || it->first == 3494 || it->first ==3364){
            cout << "Airport ID: " <<it->second.getAirportID() << " ";
            cout << "Airport Name: " <<it->second.getAirportName() << endl;

            unordered_map<int, Flight> adjList = it->second.destAPs;
            for(auto it = adjList.begin(); it != adjList.end(); ++it){
                cout << "Source ID: " << it->second.getSourceId() << " ";
                cout << "Destination ID: " << it->second.getDestId() << " ";
                cout << "Flight weight: " << it->second.getWeight() << endl;
            }
        }
    }
    REQUIRE(7000 <= airportMap.size());
}


TEST_CASE("Testing BFS_moves") {
    
    cout << "testing BFS_moves" << endl;
    string airportFile = "airports.dat";
    string routesFile = "routes.dat";    
    BFS myBFS(airportFile, routesFile);
    vector<string> result_moves = myBFS.BFS_moves(3830, 50);
    cout << "Printing out first 50 moves from O'Hare airport" << endl;
    for(unsigned i = 0; i < result_moves.size(); i++){
        cout << result_moves[i] ;
        if(i != result_moves.size()-1)
            cout << " --> ";
        if(i%5 == 0 && i != 0)
            cout << endl;
    }
    cout << endl;

    REQUIRE(51 == result_moves.size());
    REQUIRE("Chicago O'Hare International Airport" == result_moves[0]);
}

TEST_CASE("Testing BFS_dest") {
    cout << "testing BFS_dest" << endl;
    string airportFile = "airports.dat";
    string routesFile = "routes.dat";    
    BFS myBFS(airportFile, routesFile);
    vector<string> result_dest = myBFS.BFS_dest(3830, 3494);
    cout << "Printing out traversal from O'Hare to Newark" << endl;
    for(unsigned i = 0; i < result_dest.size(); i++){
        cout << result_dest[i] ;
        if(i != result_dest.size()-1)
            cout << " --> ";
        if(i%5 == 0 && i != 0)
            cout << endl;
    }
    cout << endl;

    
    REQUIRE("Chicago O'Hare International Airport" == result_dest[0]);
}

 TEST_CASE("Testing Djikstra with nearby airports")
 {
      cout << "testing how well Djikstra's algorithm works for two airports near each other" << endl;
     string airportFile = "airports.dat";
     string routesFile = "routes.dat";
     Graph airportGraph(airportFile, routesFile);
  
     Djikstras chicagoToNewYork(airportGraph, "Chicago O'Hare International Airport", "John F Kennedy International Airport"); 
     double cToNYDistance = chicagoToNewYork.getShortestDistance();
     vector<string> cToNYPath = chicagoToNewYork.getPathVertices();

     cout << "Printing shortest path from O'Hare to JFK" << endl;
     for(unsigned i = 0; i < cToNYPath.size(); i++){
         cout << cToNYPath[i];
         if(i != cToNYPath.size()-1)
             cout << " --> ";
         if(i%5 == 0 && i != 0)
             cout << endl;
     }
     cout << endl;
     cout << "Printing out shortest travel distance from O'Hare to JFK: " << cToNYDistance << endl;

    REQUIRE(0.0 < cToNYDistance);

     REQUIRE("Chicago O'Hare International Airport" == cToNYPath[0]);
     REQUIRE("John F Kennedy International Airport" == cToNYPath[cToNYPath.size() - 1]);
 }

 TEST_CASE("Testing Djiktra with distant airports")
 {
     cout << "testing how well Djikstra's algorithm works for two airports far from each other and fairly remote (few flights in and out of the source and the destination airports)" << endl;
     string airportFile = "airports.dat";
     string routesFile = "routes.dat";
     Graph airportGraph(airportFile, routesFile);
    
     Djikstras kashgarToArusha(airportGraph, "Kashgar Airport", "Arusha Airport");
     double kToADistance = kashgarToArusha.getShortestDistance();
     vector<string> kToAPath = kashgarToArusha.getPathVertices();

     cout << "Printing shortest path from Kashgar to Arusha" << endl;
     for(unsigned i = 0; i < kToAPath.size(); i++){
         cout << kToAPath[i];
         if(i != kToAPath.size()-1)
             cout << " --> ";
         if(i%5 == 0 && i != 0)
             cout << endl;
     }
     cout << endl;

     cout << "Printing out shortest travel distance from Kashgar to Arusha: " << kToADistance << endl;


     REQUIRE(0.0 < kToADistance);

     REQUIRE("Kashgar Airport" == kToAPath[0]);
     REQUIRE("Arusha Airport" == kToAPath[kToAPath.size() - 1]);
 }
