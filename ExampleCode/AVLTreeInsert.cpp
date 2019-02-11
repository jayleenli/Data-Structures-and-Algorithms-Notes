/**
* Internal method to insert into a subtree.
* x is the item to insert.
* t is the node that roots the subtree.
* Set the new root of the subtree.
* From Weiss Data Structures book pg 155
*/
void insert( const Comparable & x, AvlNode *&t)
{
if( t == nullptr )
 t = new AvlNode{ x, nullptr, nullptr };
 else if( x < t->element )
 insert( x, t->left );
 else if( t->element < x )
 insert( x, t->right );

 balance( t );
 }

 static const int ALLOWED_IMBALANCE = 1;

 // Assume t is balanced or within one of being balanced
 void balance( AvlNode *&t)
 {
 if( t == nullptr )
 return;

 if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
 if( height( t->left->left ) >= height( t->left->right ) )
 rotateWithLeftChild( t );
 else
 doubleWithLeftChild( t );
 else
 if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
 if( height( t->right->right ) >= height( t->right->left ) )
 rotateWithRightChild( t );
 else
 doubleWithRightChild( t );

 t->height = max( height( t->left ), height( t->right ) ) + 1;
 }