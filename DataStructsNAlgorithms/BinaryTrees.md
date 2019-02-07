# Binary Tree Notes



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