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
To solve the traversal problem, we need a way to find the connectivity of the graph in some way. This is also known as the maze problem because you are looking for an exist given some start node. But usually with these approaches if there is no exit, we will be in an infinite loop.
  
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
  
• Fact 1. For a recursive call DFS(u), all nodes that are marked explored between the invocation and the end of the recursive call are descendants of u in T.  
• Fact 2. Let T be a DFS tree, let x, y be two nodes in T that have an edge between them in G, but (x, y) is not an edge of T. Then, one of x or y is an ancestor of the other.  
• Suppose not, and assume that x is reached first in DFS. When the edge (x, y) is examined during the execution of DF S(x), it is not added to T because y is marked Explored. Since y was not marked Explored when DF S(x) was first invoked, it must have been discovered during the recursive call. Thus, by Fact 1, y must be a descendant
of x.   
Connected Components Fact. For any two nodes s and t in G, their conencted components are either identical or disjoint.  
  
BOTH TAKE O(N + m) time because they ahve to check all edges and all nodes! 

https://visualgo.net/en/dfsbfs  
Good Link for visualization for DFS and BFS.   
  
# Applications of BFS
## Bipartititeness 
A graph G is bipartite if vertex set can be partitioned into sets X and Y (two different colors) so every edge of G has one end in X and another end in Y.  
* A triangle is not bipartite. Bipartite iff there is no ODD cycle (like triangle). if there is an odd cycle, not bipartite.
  
##### Algorithm
Take any node i, mark it colored 0, then check all the neightbors and they must be colored 1. then alternate betweeen colors. Do need to check if marked correctly so it runs
O(m+n) time so checks all nodes and edges!  

## Biconnectivity
Tree is minimally connected graph. and can be disconnected with just one node removed.  

A graph is biconnected if you must delete two nodes and edges to disconnect G. There is no single node whose removal disconnects G. 
  
__Articulation point__ - a node whose removal disconnects G. Thus, G is biconnected iff there is no articulation point. 
  
Originally this algorithm is O(n* (n+m)), but there is algorithm to be O(n+m). The naive alogirhtm is to remove each vertex v in turn, check if C(v) is connected. Like testing eveything
  
Better alogrithm- keep track of   
Num(v) = visit order number of v in graph.  
low(v) = is the lowest/smallest num vertex reachable from v by taking zero or more DFS edges plus at most one back edge.
```
low(v) = min (num(v), 
lowest num(v) of all back edges (v,w)
smallest low (w) of all children of v
```
  
Do a BFS now and label all points with those special values. Then check that tree. a node is an articulation point if  
- v is the root and the root has more than one child
- v is not the root but has a child such that low(w) >= num(v).
  - If there is a child unable to reach a node higher than v. 

The sharing points of connected components are articulation points.  

## Toplogical Sorting
If graph is undirected without cycles, it is a tree.  

A undirected graph with no cycle is a tree.  

A directed graph, no directed cycled it can have max choose 2 edges.   

__Directed Acyclic Graph (DAG)__  - has no cycle, directed.  

Toplogical ordering is order G such that every edge is pointing from smaller index to a larger index.  
  
If G is topological ordering then G is a DAG. vice versa. (toplogical ordering iff G is DAG).  
```
Proof. By contradiction. Suppose G has a topo ordering v1, v2, . . . , vn, but also a cycle
Let vi be the lowest-indexed node in C, and let vj be the node just before vi, so (vj, vi) is an edge of G. But by our choice of i, we have that j > i, which contradicts
the assumption that v1, v2, . . . , vn is a topological ordering.
```
A cycle cannot be a DAG because it will look for smallest number (property of DAG), but there will always be something pointing to the smallest number if it is a cycle.
  
##### Algorithm
```
Find vertex w/ zero incoming edges (must exist! Proof why below)
print v, delete vm and its outgoing edges
repeat
```
Every DAG has a vertex with no incoming edge. If a graph doesnt start with a node of zero incoming edges, it is not a DAG.   
``` 
Proof for that^:
Claim: If G has a topo ordering, then G is a DAG
Contradiction: Say G has a topological ordering v1, v2...vn but also a cycle C
Say vi is the lowest index node in cycle C. vj is node just before, so (vj,vi) is an edge
but now j>i, which contradicts our topoloical ordering
```
Need to keep track of the number of incoming edges for each node in the graph. then start with one of zero incoming edges, and reduce the incoming edge count by one for all surrounding nodes. continue until no more nodes, and every new node you encounter should have zero incoming nodes after the next iteration. 

## Strongly Connected Component (SCC)
1. Do the DFS algorithm on it.
2. Number the vertices in the post-order, namely, the order in which their recursive
calls finish.
	* The reverse order is from the last to finish recursive calls to the first to finish recursive calls. 
3. Construct the reverse graph R, in which each edge has the opposite orientation
than G.
4. Perform a second DFS on R, always starting at the highest numbered vertex in
our reverse ordering, and output each subtree found by this DFS as a SCC, and remove
it from the graph. They will return groups if not everything is SCC. For example, if there is no out edges at the node being checked, that means it is the end of that SCC. so group that one and continue groups based on the reverse order. 
  
##### Proof of Correctness why this works
To show that each tree found during the second DFS (on R) is a strongly connected component, we will demonstrate the following:   
Suppose T is a tree, with root node x, found by the DFS in R, and v is a node in T. Then, the original graph G contains both a directed path from x to v, and a directed path from v
to x.
  
If v and w are two nodes in T, then we can reach w from v by
following the path v to the root x plus path from x to w, and vice versa.
  
To prove the first path that G contains a path from v to x, we note the following. The
node v is a descendant of x in T, which means there is a directed path from x to v in
R. Since each edge of R is the reverse of its copy in G, this path corresponds to a
v to x path in G.
  
We now prove the converse that G also contains a path from x to v.
- Since x is the root of T, it means that x finished after v in the
first DFS.
- Therefore, during that DFS in G, the recursive call at v finished before the recursive call at x finished.
- Since we have already shown a v to x path in G, it must be that v is a descendant
of x in the DFS of G—otherwise, v would finish after x.  

Therefore, there is a path from x to v, and the proof is complete.
   
__This is the way the book says to do it__
To prove that this algorithm works, we must show that if two vertices v and w are
in the same depth-first spanning tree of R, there must be paths from v to w and from w
to v. Equivalently, we can show that if x is the root of the depth-first spanning tree of Gr
containing v, then there is a path from x to v and from v to x. Applying the same logic to w
would then give a path from x to w and from w to x. These paths would imply paths from
v to w and w to v (going through x).  

Since v is a descendant of x in R’s depth-first spanning tree, there is a path from x to
v in R and thus a path from v to x in G. Furthermore, since x is the root, x has the higher
postorder number from the first depth-first search. Therefore, during the first depth-first
search, all the work processing v was completed before the work at x was completed. Since
there is a path from v to x, it follows that v must be a descendant of x in the spanning tree
for G—otherwise v would finish after x. This implies a path from x to v in G and completes
the proof.
