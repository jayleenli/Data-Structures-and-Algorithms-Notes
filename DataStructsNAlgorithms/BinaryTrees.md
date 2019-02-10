# Binary Tree Notes
Definition: A binary tree is a tree in which no node can have more than two children.  
Average depth value is O(logN), worst casei N-1 (straight line)  

## Binary SEARCH TREE
A binary SEARCH tree has additional property:  
All itmes in the right subtree of X are > X. Every thing in the left subtree is < X.   
Very useful for searching!!! Thats why its called search :). 
  
Path length = number of links/branches to go back to root.
Internal Path Length = sum of path lengths of tree internal nodes (not leaves)
External Path Length = sum of path lengths of tree external nodes (leaves).
https://web.cs.wpi.edu/~cs504/s00m/classes/class12/Class12.html
  
The famous recurrance D(n) = internal path length of tree T with n nodes.
Basis: D(1) = 0  
There are i nodes in the left subtree and N-i-1 nodes in the right usbtree then
D(n) = D(i) + D(n-i-1) + (n-1)
Summation...  
proves D(N) = O(NlogN)! 

But this does not mean that all the operations are O(logN), cuz in deletion, there is favortism in making left subtree deeper than the right, since we are always replacing a deleted node with a node from the right subtree.  
So we need some balancing! AVL trees ;) wink wonk

### Methods for BST
Contains
```
if (t = null) return null
	elseif (x < t.key) return find(x, t.left)
	elseif (x > t.key) return find(x, t.right)
	else return t;
```
findMin = just the leftmost node  
```
if( t == nullptr )
 return nullptr;
 if( t->left == nullptr )
  return t;
 return findMin( t->left );

 //iteratively 
 if (t != null)
	while (t.left != null)
		t = t.left
 return t;
```
findMax = just the rightmost node  
```
if( t != nullptr )
 while( t->right != nullptr )
  t = t->right;
 return t;


 //iteratively 
 if (t != null)
	while (t.right != null)
		t = t.right
 return t;
```
insert
```
if (t = null)
 t = new node x; 	// insert x here //
 elseif (x < t.key)  Insert(x, t.left)
 elseif (x > t.key)  Insert(x, t.right)
 else;  
```
delete  
Case #1: leaf, easy delte
Case #2: 1 child, delete and reroute the node pointers
Case #3: 2 children - replace the smallest node in the right subtree of X, recursively delete that node (either case 1 or case 2).  

## Proofs (Induction)
4. Use induction to prove that the number of leaves in a binary tree of
height H is at most 2^H.

Base Case:  H = 0.  A binary tree of height 0 is just a single node with
no children, and therefore has 1 leaf.  1 = 2^0, so the base case
satisfies the induction hypothesis (see below).

Induction Hypothesis:  Suppose that for some k >= 0, all binary trees of
height <= k have at most 2^k leaves.

Induction Step:  Let T be a binary tree of height k+1.  Then T's left and
right subtrees are each binary trees of height <= k, and thus by the I.H.
have at most 2^k leaves.  The number of leaves in T is equal to the sum of
the number of leaves in T's subtrees, which must be less than or equal to
2^k + 2^k = 2^(k+1).  Hence the hypothesis holds for k+1, and so the
theorem is proved.

5. Use #4 to prove that a binary tree of height H has at most 2^(H+1) - 1
nodes.

Proof by induction (although other methods were accepted for this
problem):

Base Case:  H = 0.  As above, a tree of height 0 has exactly one node, and
2^(0+1) - 1 = 2^1 - 1 = 2 - 1 = 1, so the base case satisfies the I.H.

Induction Hypothesis:  Spose that the result holds for some k >= 0; i.e.,
a binary search tree of height k has at most 2^(k+1) - 1 nodes.

Induction Step:  Let T be a binary tree of height k+1.  By definition of
leaf, all the nodes at depth k+1 are leaf nodes.  By problem 4, we know
there are at most 2^(k+1) leaves.  If we remove all the leaves, we are
left with a tree of height k.  Thus the total number of nodes in T is at
most 2^(k+1) [for the leaves] + 2^(k+1) - 1 [for the remaining tree
of height k, by the I.H.] = 2*(2^(k+1)) - 1 = 2^(k+1+1) - 1.  Hence the
hypothesis holds for k+1, and so the theorem is proved.