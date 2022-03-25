# **Leading Question**
What is the real-world application of the algorithms that we’ve learned? For example, how should we map the data to the graph so that our implementation of the Dijkstra’s algorithm can help find out the shortest path of two airports? How do we optimize airline route given different goals? 

# **Dataset Acquisition and Processing**
Our group decided to use the OpenFlights datasets. We are referring to the suggestions from stackoverflow to map our data to graph. For instance, in our implementation, the airports should map to vertices on the graph, and the edges could be routes that are provided from one airport to another, and the edge also could be weighted with distance from the dataset. To simplify the data processing, we will remove the incomplete or missing data.

# **Graph Algorithms**
Given the OpenFlights datasets, we are interested in the BFS traversal. And our group will use the loaded graph from the dataset to implement the Dijkstra’s algorithm.

## **1.Shortest path**
We decided to work on the shortest path algorithm. Since the datasets provide historical records of distances between each airport. By implementing this algorithm, we can check the real-world application of the theoretical algorithm.
Input: two airports (start point, destination)
Output: shortest path between the given two airports in terms of distance.
Using unsorted array: O(n^2)
MST Runtime complexity: O(nlog(n)+mlog(n))
Fibonacci heap runtime complexity: O(nlog(n)+m)

## **2.A* search**
A* search, as an extension of the Dijkstra’s path, will also have the input of a start point and destination, and return the best path. The cost here will also be the distance. 
Input: start airport, destination airport
Output: best path between the two airports
Runtime complexity: O(b^d).
According to Wikipedia: In the worst case of an unbounded search space, the number of nodes expanded is exponential in the depth of the solution (the shortest path) d: O(b^d), where b is the branching factor (the average number of successors per state).


## **3. BFS traversal**
We will implement the BFS traversal to determine the shortest path given a start vertex and detect cycles. 
Input: Graph G
Output: A labeling of the edges on G as discovery and cross edge.
Runtime complexity: total running time: O(n+m), where n is the size of the vertices and m is the size of the edges.

# **Timeline**
12.1 – 12.5 data processing, BFS, and shortest path
12.6 -12.9 A* search, testing, presentation
12.10 - 12.13 finishing algorithms and testing.


