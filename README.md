# Graph-Data-Structure

This project is based on a simulation of how a GPS works. Suppose you have a map of N houses and you want to go from house A to house B, then your GPS should tell you the shortest path that you could take to reach your destination!
This is exactly what this program does.

Given a dataset of nodes and edges, this program organizes the data into a graph. The graph is implemented using an adjacency list; that is, it uses an array of 50,000 vectors of tuples of 2 integers. Each array entry corresponds to a vertex and each tuple entry is its adjacent vertex and the weight of the edge connecting them. 

The program implements Prim's algorithm to find the MST of the graph which uses a heap data structure.

<img width="884" alt="Screenshot 2023-10-02 103531" src="https://github.com/Dania003/Graph-Data-Structure/assets/69827478/c9ffe07d-bcae-4870-a279-f00fb6a28afe">


Program UML
![P4 UML](https://github.com/Dania003/Graph-Data-Structure/assets/69827478/e4d00c90-83d3-41f7-8d35-d274c0c73ad2)
