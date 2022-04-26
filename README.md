# CS225 Final Project

## Team Members: kmajid2, adnann2, ebaadss2, ymohid2

## Introduction
For our final project, we used the [OpenFlights](https://openflights.org/data.html) dataset and routes data to make a graph that uses airports as vertices and routes as edges. We used Djikstra's to find the shortest path between two airports and PageRank to find the most important airports. 
* [Written Report](https://github-dev.cs.illinois.edu/cs225-sp22/adnann2-kmajid2-ebaadss2-ymohid2/blob/main/results.md)
* [Final Presentation Slides](https://github-dev.cs.illinois.edu/cs225-sp22/adnann2-kmajid2-ebaadss2-ymohid2/blob/main/presentation.pdf)
* [Final Presentation Video](https://drive.google.com/drive/folders/1hbNmRiDEHXUxzFHZvPjqraUjcEBjbdRp?usp=sharing)

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

The program will then prompt you to enter a number 0-4 to complete various operations: 

```
(0) Using BFS, traverse all of the graph from a given airport 
(1) Using BFS, traverse a given number of moves of the graph from a given airport
(2) Using BFS, traverse the graph until a destination airport from a given airport
(3) Use Djikstra's to calculate the shortest path between two airports
(4) Use PageRank to find the n most important airports
```
Now, you can simply follow the instructions corresponding to using each algorithm. Afterwards, the program will ask you whether you would like to choose another algorithm to run.

## Testing 
To run our tests, you can use: 

```
make test 
./test
```

These tests comprehensively check the functionality of creating an Airport, Graph, and the BFS traversal. As well as using Djikstra and PageRank on sample data from the dataset. 
