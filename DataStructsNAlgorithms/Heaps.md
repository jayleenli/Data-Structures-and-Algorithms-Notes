# Heap Notes

## Proofs

### Max key in a binary min heap with n nodes must be at one of the leaves
By the heap-ordering property, for all nodes x, we have key(parent(x)) < key(x).
So, the maximum cannot be at a non-leaf node because then the children of that
node must have keys larger than the max.

### Proving that a binary heap has at most ceil (n/2) leaves
https://cs.stackexchange.com/questions/841/proving-a-binary-heap-has-lceil-n-2-rceil-leaves

Proving recursively:
We observe that every two nodes added to the heap will increase the number of leaves by 1. 
So, we are trying to show that Ceil(n/2)+1.
Let's say that L(n) defines the number of leaves in a heap, where n is the number of nodes.
Now we are trying to prove inductively 
```
L(n+2) = L(n) + 1
ceil((n+2)/2) = ceil(n/2 + 1)
ceil((n+2)/2) = ceil(n/2) + 1, since the ceil of 1 is 1
L(n+2) = L(n) + 1
Proof is complete. 
```

### Any algorithm to find the max will take the O(n) time
Max algorithm must check all the nodes to find max.
Assume the algorithmn does not check a node, z. 
Say the maximum value in the heap is L. When the algorithm is run, it should return L.
Now if we change z to L+1, and run the algorithm again, the heap will return L, even though the maximum should be L+1 now. 
Therefore all nodes must be checked to find the max. 

### D heaps
Why are they useful? Well it makes the height of the tree shorter, so you have a faster percolate up but a more expensive percolate down
percolateUp = O(logdN)
percolateDown = O(dlogdN)