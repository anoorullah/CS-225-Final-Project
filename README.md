# CS225 Final Project

## Team Members: kmajid2, adnann2, ebaadss2, ymohid2

## Introduction
For our final project, we used the [OpenFlights](https://openflights.org/data.html) dataset and routes data to make a graph that uses airports as vertices and routes as edges. We used Djikstra's to find the shortest path between two airports and PageRank to find the most important airports. 

## Description of the Files in this Repository
* Flight: this class is used to construct edges between two airports and configure weights to be the distance between them. 
* Airport: this class is used to define vertices in the graph. Airports have member names, IDs, cities, countries, longitudes, and latitudes. 
* Airport Graph: this class actually creates the graph by allowing for the insertion of vertices and edges. 
* BFS: this class implements a breadth-first graph traversal to determine possible paths from one airport to another. 
* Djikstras: implementation of Djikstra's algorithm to find the shortest path. 
* PageRank: use of the Page Rank algorithm to find the most important airports.

## Try it out for yourself: 
To easily run the program in terminal, use the following commands.
First, you will need to clone this repository and cd to its root: 

```
git clone [REPOSITORY URL]
cd [REPOSITORY NAME]
```
Then, you can simply compile the executable and run it using the following commands. The 'make' command will create object files that work specifically on your machine: 

```
make exec
./exec 
```

The program will then prompt you to enter a number 0-4 to complete various BFS operations: 

```
(0) Using BFS, traverse all of the graph from a given airport 
(1) Using BFS, traverse a given number of moves of the graph from a given airport
(2) Using BFS, traverse the graph until a destination airport from a given airport
(3) Use Djikstra's to calculate the shortest path between two airports
(4) Use PageRank to find the n most important airports
```
Now, you can simple enter airport codes (can be found online or in the airports dataset), and press enter to run the BFS traversal. Afterwards, the program will ask you whether you would like to do another traversal. 

## Testing 
To run our tests, you can use: 

```
make test 
./test
```

These tests comprehensively check the functionality of creating an Airport, Graph, and the BFS traversal. As well as using Djikstra and PageRank on sample data from the dataset. 
