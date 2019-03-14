# Shortest Path Algorithms
  
## Minimum Spanning Tree (MST)
Used to find the smallest cost of graph traversal. its the subset of edges that forms a spanning tree of min total cost.  
  
Spanning - contains all the nodes. minimum because you wan't to be "greedy" and be cheap, take the least cost for yourself.   
__Cayley's proof__ - There are n^(n-2) spanning trees that can be made of n nodes.  
  
The # of edges of min spanning tree is vertices - 1. 
  
## Kruskal's Algorithm
First must assume all edge costs are distinct. Sort all the edges in ascending order of cost. Processing edges in that order. Then add next cheapest edge to a tree T that starts at 0 as long as it doesn't create a cycle.  
```
for i = 1 to n-1
 add the cheapest edge that doesn’t create a cycle

```
Once all the nodes are connected, we can disregard everything else. Cuz its not gonna add it anyway.  
  
This algorithm is not nesscarily good, because being greedy may force later more expensive choices. That might mess up our MST. 
  

Proof why this works. Detecting a cycle is actually a union find problem. Suppose there is a cycle in input. Say one edge in cycle is most expensive. Then this edge does not belong to the tree.  
  
Cost O(ElogV), because union find is O(m a(n)) and other heap operations are O(logN), and the operations get absorbed into it. Since |E| = O(|V|^2), this makes the running time O(|E|log|V|). E = edge, v = vertices.  
  
## Prim's Algorithm
Grows the tree in successive stages, and is similiar to Djisktra's algorithm.  
There is a set of vertices in tree of our shortest path, and there is a set that is not in the tree.  
- find new vertex to add to the tree by choosing the edge (u,v) such that the cost of (u,v) is smallest among all edges where u is in the tree and v is not in the tree.
- Each step will add a vertex to the tree.  
  
__Running time__   
O(N^2) without binary heap  
```
(n-1)n + |E|Sum(deg(v)) = 2|E| <------------also = deg(v) cuz take in account 
  ^				^					the undirected graph has 2 direction
  ^				^
  ^				^-------------------|E| decrese keys. deg(v) is the # of neighbors
  ^
Worst case each node is connected to everyone, n delete mins
```
O(|E|log|V|) with binary heap. Reasoning is below but basically because all operations using a binary heap gets absorbed into the log|V|  
https://stackoverflow.com/questions/20430740/time-complexity-of-prims-algorithm

## Dijkstra's Algorithm
Prime example of a greedy algorithm! Greedy means solve problem in stages by doing what appears to be best in each stage.  
  
###### Proof of Complexity
Sequentially scan vertices to find min distance, each phase will take O(|V|) time to find min, and thus O(|V|^2) time spent finding the min over course of algorithm.  
Time for updating distance at each node is constant. at most update per edge for a total of O(|E|).  
  
Total Running Time: O(|E| + |V|^2) = O(|V|^2)  
This can be improved with a priority queue/heap  
Selection of vertex v is deleteMin operations since once the unknown min vertex found it is no longer unknown and must be removed.  
  
Update the distance using decreaseKey operation (just reduce the prioity and fix the heap with the new key if needed, when key < parent) which is O(log|V|)  
  
Total Running time is O(|E|log|V| + |V|log|V|)= O(|E|log|V|)  
  
###### Why it doesn't work on negative edges
https://stackoverflow.com/questions/13159337/why-doesnt-dijkstras-algorithm-work-for-negative-weight-edges
```
       A
      / \
     /   \
    /     \
   5       2
  /         \
  B--(-10)-->C
  ```
Dijkstra from A will first develop C, and will later fail to find A->B->C  
algorithm assumes the "cost" to the "closed" nodes is indeed minimal, and thus the node that will next be selected is also minimal.
  
##### Pseudocode
```
void Graph::dijkstra( Vertex s )
{
	for each Vertex v
	{
	   v.dist = INFINITY;
	   v.known = false;
	}
	s.dist = 0;
	while( there is an unknown distance vertex )
	{
	  Vertex v = smallest unknown distance vertex;
	  v.known = true;
	  for each Vertex w adjacent to v
	  if( !w.known )
	  {
	    DistType cvw = cost of edge from v to w;
		if( v.dist + cvw < w.dist )
		{
		  // Update w
		  decrease( w.dist to v.dist + cvw );
		  w.path = v;
		}
	  }
	}
}
```

#### Pseudocode for unweighted graph (just a BFS)
```
void Graph::unweighted( Vertex s )
{
  Queue<Vertex> q;
  for each Vertex v
   v.dist = INFINITY;
   s.dist = 0;
   q.enqueue( s );
  while( !q.isEmpty( ) )
  {
    Vertex v = q.dequeue( );
    for each Vertex w adjacent to v
    if( w.dist == INFINITY )
    {
      w.dist = v.dist + 1;
      w.path = v;
      q.enqueue( w );
    }
  }
}
```