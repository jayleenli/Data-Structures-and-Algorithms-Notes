# Splay Trees
Why Use vs AVL trees?   
AVL trees have too many cases and also needs extra memory to store the height data in each node.   
Also using Splay tree gives rise to these functions, insert, delete, find, split, join.  
In addition, splay tree guarantee better performance over a long sequence of operations. this is why it guantees for O(nlogn). But a single operation could take O(n). The reason for the better performance over time is because of the splay heuristic that relies on the idea of caching- things that were accessed recently are likely to be accessed again.   
AVL trees guarentee that the shape is always logn, but advantage for splay is faster look up time.  

###### Properties
* splay at node of depth d takes O(d) time.
* splaying at x moves c to the root and (roughly) halves teh depth of every node on the access path. 
  * this can be represented with a worst case bst then applying splay on the last node.

###### The basic idea behind splay trees
* self balancing BST without explicit balance condition
* uses a restriction heuristic to balance
* Based on caching behavior. If you looked for something recently, you will most likely search for it again.
* The heuristic is to splay after every access for a node. 
  * splay is to make the current splay(x) to become the new root based on rotation.
* "Simple and elegant"

## Splay at a Node
https://www.geeksforgeeks.org/splay-tree-set-1-insert/
#### Case 1 Node is root
Just return the tree, no need to do anything
#### Case 2 Zig: Node is child of root (no grandparent)
These case we just need one rotation  
"Terminating move" since it doesn't repeat afterward.    
```
                y                                     x
               / \     Zig (Right Rotation)          /  \
              x   T3   – - – - – - – - - ->         T1   y 
             / \       < - - - - - - - - -              / \
            T1  T2     Zag (Left Rotation)            T2   T3
```
#### Case 3: Zig-Zig/Zag-Zag Node has a parent and grandparent on the same side [double rotation]
If p(x) is not root & x and p(x) are either both left children or both right children.  
Fix by doing two right rotation or two left rotations.  
```
Zig-Zig (Left Left Case):
       G                        P                           X       
      / \                     /   \                        / \      
     P  T4   rightRotate(G)  X     G     rightRotate(P)  T1   P     
    / \      ============>  / \   / \    ============>       / \    
   X  T3                   T1 T2 T3 T4                      T2  G
  / \                                                          / \ 
 T1 T2                                                        T3  T4 

Zag-Zag (Right Right Case):
  G                          P                           X       
 /  \                      /   \                        / \      
T1   P     leftRotate(G)  G     X     leftRotate(P)    P   T4
    / \    ============> / \   / \    ============>   / \   
   T2   X               T1 T2 T3 T4                  G   T3
       / \                                          / \ 
      T3 T4                                        T1  T2
```
#### Case 4: Zig-Zag/Zag-Zig [Double rotation]
Similiar to AVL tree left-right and right-left cases.  
if p(x) not root & x is left child and p(x) is right child (or the symmetric case)  
```
Zag-Zig (Left Right Case):
       G                        G                            X       
      / \                     /   \                        /   \      
     P   T4  leftRotate(P)   X     T4    rightRotate(G)   P     G     
   /  \      ============>  / \          ============>   / \   /  \    
  T1   X                   P  T3                       T1  T2 T3  T4 
      / \                 / \                                       
    T2  T3              T1   T2                                     

Zig-Zag (Right Left Case):
  G                          G                           X       
 /  \                      /  \                        /   \      
T1   P    rightRotate(P)  T1   X     leftRotate(P)    G     P
    / \   =============>      / \    ============>   / \   / \   
   X  T4                    T2   P                 T1  T2 T3  T4
  / \                           / \                
 T2  T3                        T3  T4  
```

## Splay Tree Operations
#### Access(i) O(logN)
* Search down the tree looking for key i
* Splay at node x containing i or if not found, x = last non null node on the access path.

#### Join(t1, t2)
* join two subtrees together t1 and t2, but t1 keys < t2 keys for all keys!
* find the max of t1, and then call a splay on it, making it the root
* since the max will not have a right child, just attach t2 as the right child.

#### Split (i, t)
* split the tree into two, one tree is < i and the rest > i
* first access(i). this calls splay. 
 * this could return < i or > i if access isnt there, and return the next closest one. This will create two cases.
 * if new root > i
  * break left child link, and return the two subtrees
 * otherwise break the right child link. this also takes into account the equals case. you can alter this to split other way but it is up to you.

#### Insert(x) O(logN)
* just insert normally as bst. then splay that key back to the root. 
* Other way that is done (done in class) is split(x,t) and replace t with new tree of new root node with i in it. Whose left and right subtree are t1 and t2 from split.  
  
#### Delete (x,t) O(logN)
* call access (x,t) first, if its not found, the tree just gets restructed. 
* if it is found, it splayed with x as the root
* delete the root, join the two remaining left and right subtrees.


##  BFS (Breadth-First Search) order
```
      tree
      ----
       j         <-- level 0
     /   \
    f      k     <-- level 1
  /   \      \
 a     h      z  <-- level 2
  \
   d             <-- level 3
```
[j, f, k, a, h, z, d]  
Basically as if you were going through the tree line by line.