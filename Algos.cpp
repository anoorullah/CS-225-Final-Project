// BFS Implementation:


// Djikstra Implementation:
// Sample from Ebaad
/*

 

#include "Route.h"

#include "Airport.h"

#include "Graph.h"

#include <cmath>

#include <iostream>

#include <limits>

#include <unordered_map>

#include <vector>

#include <string>

#include <iostream>

#include "Dijkstras.h" //work in progress

 

#define _USE_MATH_DEFINES

//#define INF 99999999999

 

using namespace std;

 

 

Dijkstra::Dijkstra(Graph input_graph)

   {

     graph = input_graph;

   }

 

Dijkstra::double getDistance(const Airport& a1, const Airport& a2)

{

  /* Haversine: a = sin^2(Delta Lat/2) + cos (Lat_1) * cos(Lat_2) * sin^2(Delta Long/2)

   * c = 2 atan2(SQRT(a), SQRT(1-a))

   * d = Radius of the Earth * c

 

  const int R = 6371000; // meters

 

  const double lat_1 = a1.getAirportLatitude() * M_PI/180; // latitude and longitude in radians

  const double lat_2 = a2.getAirportLatitude() * M_PI/180;

  const double delta_lat = (a2.getAirportLatitude()-a1.getAirportLatitude()) * M_PI/180;

  const double delta_long = (a2.getAirportLongitude() - a1.getAirportLongitude()) * M_PI/180;

 

  const double a = pow(sin(delta_lat/2), 2) + cos(lat_1) * cos(lat_2) * pow(sin(delta_long/2),2);

  const double c = 2 * atan2(sqrt(a), sqrt(1-a));

 

  return R * c; // in meters

 

}

 

/*test code

*

 *

  * double getDistance(double lat_1, double lat_2, double long_1, double long_2)

  *{

  /* Haversine: a = sin^2(Delta Lat/2) + cos (Lat_1) * cos(Lat_2) * sin^2(Delta Long/2)

  * c = 2 atan2(SQRT(a), SQRT(1-a))

  * d = Radius of the Earth * c

  *  

  * 

  *  const int R = 6371000; // meters

  * 

  * // const double lat_1 = a1.getAirportLatitude() * M_PI/180; // latitude and longitude in radians*

  * // const double lat_2 = a2.getAirportLatitude() * M_PI/180;

  *  const double rad_lat_1 = lat_1 * M_PI/180;

  *  const double rad_lat_2 = lat_2 * M_PI/180;

  *  const double delta_lat = (lat_2 - lat_1) * M_PI/180;

  *  const double delta_long = (long_2-long_1) * M_PI/180;

  * 

  *  const double a = pow(sin(delta_lat/2), 2) + cos(rad_lat_1) * cos(rad_lat_2) * pow(sin(delta_long/2),2);

  *  const double c = 2 * atan2(sqrt(a), sqrt(1-a));

  * 

  *  return R * c; // in metres

  * 

  *}

  *

 

 

Dijkstras::double distanceTravelled(int source, int destination)

{

  // Have to run SSSP first

  //DijkstraSSSP(source);

  return distance[destination];

}

 

Dijkstras::vector<Airport> shortestPath(int source, int destination)

{

  // Have to run SSSP first

  //DijkstraSSSP(source);

  int previous_ID = previous[destination];

  vector<Airport> shortestP;

  while (previous != 0)

  {

    shortestP.insert(getAirportByID(destination));

  }

  return shortestP;

}

 

Dijkstra::void DijkstraSSSP(int source)

{

  // vector to extract the shortest path

  set<pair<double, int>> path; //distance and current airport

 

  //Vector for distances

  vector<double> d(graph.numAirports(), INFINITY);

  distance = d;

 

  //Adjacency vector

  vector<double> p(graph.numAirports(), 0);

  previous = p;

 

  //Source Airport

  path.insert(0.0, source) //No distance, starting at source airport

  distance[source] = 0.0;

  previous[source] = 0;

 

  // Continue until all shortest distances are computed

  while(!path.empty())

  {

    pair<double, int> tmp = *(path.begin());

    path.erase(path.begin());

   

    int source_ID = tmp.second;

   

    //check for adjecency

    for (int i = 0; i < graph.numAirport(); i++)

      if (isAdjacent(graph.getAirportByID(source_ID), graph.getAirportByID(i))

      {

        int port = i;

        int dist = getDistance(getAirportByID(source_ID), getAirportByID(port)) // Need to work on getDistance formula using Haverine formula

          

        // SHorter path?

        if (distance[port] > distance[source_ID] + dist)

        {

          if(distance[port] != INFINITY)

          {

            path.erase(path.find(make_pair(distance[port], port)));

          }

         

          //update

          distance[port] = distance[source_ID] + dist;

          path.insert(make_pair(distance[port], port))

          previous[port] = source_ID;

        }

      }

  }

}
*/

// Betweenness Centrality Implementation:
