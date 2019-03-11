# Shortest Path Algorithms

### Prim's Algorithm
Grows the tree in successive stages, and is similiar to Djisktra's algorithm.  
There is a set of vertices in tree of our shortest path, and there is a set that is not in the tree.  
- find new vertex to add to the tree by choosing the edge (u,v) such that the cost of (u,v) is smallest among all edges where u is in the tree and v is not in the tree.
- Each step will add a vertex to the tree.  
  

__Running time__   
O(N^2) without binary heap  
```
(n-1)n + |E|Sum(deg(v)) = 2|E| <------------also = deg(v) cuz take in account 
  ^				^							the undirected graph has 2 direction
  ^				^
  ^				^-------------------|E| decrese keys. deg(v) is the # of neighbors
  ^
Worst case each node is connected to everyone, n delete mins
```
O(|E|log|V|) with binary heap. Reasoning is below but basically because all operations using a binary heap gets absorbed into the log|V|  
https://stackoverflow.com/questions/20430740/time-complexity-of-prims-algorithm