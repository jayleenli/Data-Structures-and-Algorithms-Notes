# Leftist Heaps
These are different than normal heaps. Important because they suppose merge of two heaps in O(logN) time. They use NPL (null path length) as their "height." 

NPL(x) - length of the shortest path from X to a null pointer  
  
Leftist properties:   
* NPL(leftchild(X)) >=  NPL(rightchild(X))  
* NPL(root) <= log(N+1)  
* proof:  show by induction that NPL(root) = r implies tree has at least 2^r - 1 nodes


## Functions
All operations takes O(log n) because of the root's NPL bound. 
 * Insert
  * Creates a single node heap, and then merges
 * deleteMin
  * deletes the root, and then merges the children subtrees

## Merge
```
Merge(t1, t2)

	if t1.empty() then return t2;
	if t2.empty() then return t1;
	if (t1.key > t2.key) then swap(t1, t2);

	t1.right = Merge(t1.right, t2);
	if npl(t1.right) > npl(t1.left) then     
		swap(t1.left, t1.right);
	npl(t1) = npl(t1.right) + 1;

	return t1

```