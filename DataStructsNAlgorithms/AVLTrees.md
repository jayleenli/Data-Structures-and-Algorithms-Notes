# AVL Trees - self adjusting BST
* A bst, except that for every node in the tree, the height of the left and right subtree can differ by at most 1.  
  * Always looking for left height - right height.
* The height of an empty tree is -1.   
* The height information is kept at each node in the node structure. 
* All tree operations performed in O(logN) worst case. 
  * Insert
  * Delete
  * Find
  * Find Min, Find Max
  * Find Successor, Find Predecessor
  * It can report all keys in range [Low, High] in time O(log n + OutputSize)
* Height of a tree = 1 + max{height-left, height-right}

## Insert
https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
Insert can sometimes violate the AVL condition, so we will need to fix the violation from bottom up. There are four cases that could happen for the imbalance.
1. An insertion into the left subtree of the left child of α (left-left)
2. An insertion into the right subtree of the left child of α (right-left)
3. An insertion into the left subtree of the right child of α (left-right)
4. An insertion into the right subtree of the right child of α (right-right)

The "outer" cases only need a single rotation while the "inner" cases need double rotation. 

### Rotations
Diagrams from the geeksforgeeks website.
```
T1, T2 and T3 are subtrees of the tree 
rooted with y (on the left side) or x (on 
the right side)           
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3
Keys in both of the above trees follow the following order 
 keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
So BST property is not violated anywhere.
```
Code for Right and left rotation.   
```
struct Node *rightRotate(struct Node *y) 
{ 
    struct Node *x = y->left; 
    struct Node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Return new root 
    return x; 
} 
  
struct Node *leftRotate(struct Node *x) 
{ 
    struct Node *y = x->right; 
    struct Node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
} 
```




#### Left Left Case
```
T1, T2, T3 and T4 are subtrees.
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
```
#### Left Right Case 
```
     z                               z                           x
    / \                            /   \                        /  \ 
   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2
```
#### Right Left Case
```
   z                            z                            x
  / \                          / \                          /  \ 
T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
   x   T4                      T2   y                  T1  T2  T3  T4
  / \                              /  \
T2   T3                           T3   T4
```
#### Right Right Case
```
  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(z)       z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4
```

## Deletion
Complicated like BST deletion.  
* locate & delete the element
* adjust tree height
* perform up to O(log n) necessary rotations
