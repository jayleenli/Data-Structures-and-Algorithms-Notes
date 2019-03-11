# Shortest Path Algorithms

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