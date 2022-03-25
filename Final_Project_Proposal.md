# **Leading Question**
What is the real-world application of the algorithms that we’ve learned? For example, how should we map the data to the graph so that our implementation of the Dijkstra’s algorithm can help find out the shortest path of two airports? How do we optimize airline route given different goals? 

# **Dataset Acquisition and Processing**
Our group decided to use the OpenFlights datasets. We are referring to the suggestions from stackoverflow to map our data to graph. For instance, in our implementation, the airports should map to vertices on the graph, and the edges could be routes that are provided from one airport to another, and the edge also could be weighted with distance from the dataset. To simplify the data processing, we will remove the incomplete or missing data.

# **Graph Algorithms**
Given the OpenFlights datasets, we are interested in the BFS traversal. And our group will use the loaded graph from the dataset to implement the Dijkstra’s algorithm.

## **1.Betweenness Centrality**
Tyoe in here why we decided on this algo
Input: 
Output: 
Using unsorted array:
MST Runtime complexity: 
Fibonacci heap runtime complexity: 

## **2.Djikstra's Algorithm*
Djikstra's Algorithm uses the distance between points and return the best path. The cost will be the distance. 
Input: start airport, destination airport
Output: best path between the two airports
Runtime complexity: O(b^d).

## **3. BFS traversal**
We will implement the BFS traversal to determine the shortest path given a start vertex and detect cycles. 
Input: Graph G
Output: A labeling of the edges on G as discovery and cross edge.
Runtime complexity: total running time: O(n+m), where n is the size of the vertices and m is the size of the edges.

# **Timeline**
3/28 – 4/4: Data Processing, BFS, and Betweenness Centrality
------------------------------------------------------------
4/5 - 4/24: Djikstra's Algorithm, Fixing/Debugging, Testing
------------------------------------------------------------
4/25 - 5/5: Finishing Algorithms and Presentation.
------------------------------------------------------------
