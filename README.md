# Graph Algorithms 
## Advance Data Structures


### Implementation of the Directed Graph
* we can implement a graph by two methods:--
1. **Adjacency matrix**
2. **Adjacency list**
### Adjacency matrix
* Auxiliary Space complexity ``` O(N^2)``` 
* Time complexity ``` O(E)``` to implement a graph.
### Adjacency list
* Auxiliary Space complexity ``` O(N+E)``` 
* Time complexity ``` O(E)``` to implement a graph.
* I am using here **Adjacency list** for the implementation.

E denotes the number of connections or edges.

N denotes the number of vertices.
## Unweighted Graph Algorithm
## Breadth first search (BFS)
* Using **Queue* Data structure to run the bfs via iteration.
* I have implemented both the BFS function ``` void BFSvisit()``` for the connected graph and ```void NotconnBFS()``` for the not connected graph.
### Syntax
* ```red[]``` will keep track of visited and not visited vertix till now during BFS and DFS run.
* ```predecessor[]``` will keep track of the current visiting vertix parent in the BFS and DFS tree (will help to determine the shortest path location) 
* ```pathlength[]``` will keep track of the shortest disytance from the root vertix in the BFS tree.
* ```vertices[]``` Original graph
* ```transposevertices[]``` Transpose graph
* ```runvertix``` the vertix from where i want to start

### Implemented Applications
* To find the shortest distance and determine the shortest path between the **Two vertices**
* To compute the **Diameter**(Longest path among the shortest paths of any two vertices) of the BFS Tree.
* To check whether the graph is connected or not  (Using a  **Transpose Graph**)
### Time complexity of above implementations ```O(N + E)```

### Depth First Search (DFS)
* Using recursion to run the DFS over the graph ```void DFSvisit()```
### syntax
* ```start[]``` to store the entry time of any vertix in the dfs tree
* ```finish[]``` to store the recursion back tracking time for a node after deadend.
* ```heightvertix[]``` to store the height or distance of a vertix from the root vertix

### Implemented Applications
* To check whether the graph has a cycle or not and determine all the cycles present in the Graph ```void DFScyclevisit()``` (Using the concept of backedge by computeing start and finish time of a vertix )

* To compute all the strongly connected components in the Graph ``` void DFSforstronglyconnected()```
### Time complexity of above implementations ```Average case O(N + E)```

## Weighted Graph Algorithm
## Prim's Algorithm (minimum spanning Tree)
* Implemented a **Undirected Graph** with the weighted Edges.
* Using Greedy Approach to compute the edge every time with the minimum weight.
### syntax 
```minspantree[][3]``` will store all the edges and weights of the edges in my minimum spanning tree so that i can approach to all the  vertices in my graph with the minimum total weight.







