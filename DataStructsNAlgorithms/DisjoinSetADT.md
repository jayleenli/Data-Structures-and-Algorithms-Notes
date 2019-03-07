# Disjoin set ADT (Union Find)
Its a collection of set of elements, all the sets are disjoint, and each has a name.

## Functions
Setname(find) - misleading naming convention, but it just remanes the unique set with the given element.  
Union (setname1, setname2) - replaces both sets with a new set.
   
### Implementation 1 Quick Find
find O(1), union O(n).
```
Union (int i, int j)
for (int k = 1, k <= N, k++)
	if (setName[k] == j)
		setName[k]=i;

Find(int e)
	return setName[e]
```
### Implementation 2 Quick Union
find O(n), union O(1)  
How is it like this??? Trees! this is why union is fast but find is harder because you have to go up the tree, using parent pointers.   
Find(i) is recursive calls using the parent pointer until the root, and it returns that.   
Union on the other hand, just takes one set and joins it to the other.  
Don't change the name, name is just root node.  
```
int Find(int e)
while parent(e) != 0 
	e = parent[e]
return e

Union(int i, int j)
	parent[j] = i
```
### Smart Union (Union by Size)
Union - makes the smaller tree part of the bigger one. the bigger one is new root. This simple change guarentees the height is at most LogN.  
```
Find (int e)
while parent[e] != 0
	e = parent[e];
return e;

Union (int i, int j)
if setszie[i] > setsize[j]
	setsize[j] += setsize[i]
	parent[i]=j
else
	setsize[i]+= setsize[j];
	parent[j] = i;
```
Analysis! Why is that true  
If u depth is h, its tree has at least 2^n nodes.  
Say we have two trees u and v. when Union(u,v) performed, depth of u only incrases iff v tree > u is true.  
If u depth grow by 1, its new tree size is > 2x old tree size, because v had to be bigger than u.  
So this why depth at most logn  
Any set of n find + union takes O(nlogn) . First n is # of finds, and logn is the time for each find. Find is costly, but union is O(1).   

### THE ULTIMATE UNION (Smart Union + Path Compression)
Path compression is when you do a find, all the nodes you need to traverse to do it become children of the root. This makes the nodes that were traversed become shorter. so we spend a little more to make our other finds shorter.   
Amortized Analysis is almost constant. 
  
  
This is a good idea if unions aren't done frequently, cuz there would be a lot of deep nodes, which are brought to the root from compressions.  
Works with union by size, but not completely with union by height, because then the height would get changed.  
  
Any sequence of n finds and unions takes O(n a(n)) time. a(n) represents an inverse Ackerman function