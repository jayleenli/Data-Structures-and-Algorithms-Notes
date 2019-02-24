# Graphs
## Representations of Graphs
* Adjacency Matrix - 2 dim array V x V. Each edge (u,v) set A(u,v) = 1.
  * Pro: Easy to check if (u,v) is an edge in G
  * Con: Takes V^2 space even if graph has very few edges. INfeasible space when V is millions of nodes.
* Adjacency List - array of adjacency lists. ith cell is a linked list of all vertices adjacent to vertex vi.
  * Space is O(E). Each directed edge is stored just once. So if G is undirected, it appears in lists of both u and v. 
  * Pro: Linear Space. Ez to list the vertices adjacent to u
  * Cons: Checking if (u,v) is an edge can take O(n) time. 

## Traversing a Graph
An undirected graph is connected if there is a path between any two vertices. A directed graph with this property is strongly connected. A weakly connected graph—underlying graph connected but the directed graph may not have directed path between all pairs.  

Trees: an undirected graph is a tree if it is connected and does not contain a cycle.

## Graph Connectivity
To solve the traverrsal problem, we need a way to find the connectivity of the graph in some way. This is also known as the maze problem. But usually with these approaches if there is no exit, we will be in an infinite loop.
  
#### Breath First Search
Simple algorithm for st-connectivity. Start at s and explore outward in all possible directions. To make sure we don't get stuck in a loop. use markers to keep track of nodes that have been visited.   
Each Node will get a level/layer number. Initially is level 0.   
This creates a tree-like structure. This is the BFS tree.  
To check if it is connected, there should be a path from s to t if s is t exists in some layer after s BFS. 
  
Let T be a BFS tree, and let x and y be nodes in T belonging to different layers Li and Lj. If (x,y) is an edge of G, then |i-j| <=1.
  
Proof by Contradiction: assume i < j-1. When x is scanned in layer i, the edge (x,y) will add y to the layer Li+1, ensuring j <= i + 1. 
  
#### Depth First Search
Starting at s, we take hte first edge out of s, and continue recursively until we reach a dead end. a node for which all neighbors have already been explored. Then backtrack until get a node with at least one explored neighbor.  
Called DFS because it explores G by going as deeply as possible and then retreating when necessary.  
Similiar to maze finding. 
  
BOTH TAKE O(N + m) time because they ahve to check all edges and all nodes! 