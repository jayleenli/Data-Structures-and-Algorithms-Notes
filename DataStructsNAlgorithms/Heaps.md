# Heap Notes

## Proofs

### Max key in a binary min heap with n nodes must be at one of the leaves
By the heap-ordering property, for all nodes x, we have key(parent(x)) < key(x).
So, the maximum cannot be at a non-leaf node because then the children of that
node must have keys larger than the max, which is a contraction of the max.

### Proving that a binary heap has at most ceil (n/2) leaves
https://cs.stackexchange.com/questions/841/proving-a-binary-heap-has-lceil-n-2-rceil-leaves

### Any algorithm to find the max will take thetha(n) time
Max algorithm must check all the nodes to find max.
Assume the algorithmn does not check a node, z. 
Say the maximum value in the heap is L. When the algorithm is run, it should return L.
Now if we change z to L+1, and run the algorithm again, the heap will return L, even though the maximum should be L+1 now. 
Therefore all nodes must be checked to find the max. 