# Graph-Data-Structure

This project is based on a simulation of how a GPS works. Suppose you have a map of N houses and you want to go from house A to house B, then your GPS should tell you the shortest path that you could take to reach your destination!
This is exactly what this program does.

Given a dataset of nodes and edges, this program organizes the data into a graph. The graph is implemented using an adjacency list; that is, it uses an array of 50,000 vectors of tuples of 2 integers. Each array entry corresponds to a vertex and each tuple entry is its adjacent vertex and the weight of the edge connecting them. 

The program implements Prim's algorithm to find the MST of the graph which uses a heap data structure.

