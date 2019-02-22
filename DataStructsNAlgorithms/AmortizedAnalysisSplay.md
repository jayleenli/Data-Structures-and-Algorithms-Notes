# Amortized Analysis

Amortized analysis is a worst-case analysis of a a sequence of operations — to obtain a tighter bound on the overall or average cost per operation in the sequence than is obtained by separately analyzing each operation in the sequence. 

Amortized Analysis is used for algorithms where an occasional operation is very slow, but most of the other operations are faster. In Amortized Analysis, we analyze a sequence of operations and guarantee a worst case average time which is lower than the worst case time of a particular expensive operation.

In my own words, basically the point of amortized analysis is to get a estimate of the running time that isnt as pessmistic as the big O time. This will make things that cost a lot but are not really performed as much to be counted less. So the worst case is not the worst it could be.

## The Three Methods
* The aggregate method, where the total running time for a sequence of operations is analyzed.
* The accounting (or banker's) method, where we impose an extra charge on inexpensive operations and use it to pay for expensive operations later on.
* The potential (or physicist's) method, in which we derive a potential function characterizing the amount of extra work we can do in each step. This potential either increases or decreases with each successive operation, but cannot be negative.

### Aggregate Method examples with stack and binary counter
say that we have 3 operations. push, pop, and multipop. (s,k).
  
Theorem: that aany sequence of operrations on stack takes O(n) time. 
  
So the amortized cost of M stack is O(N)/n = O(1)  
Why?
  

Claim that any element on the stack can be popped once.   
num push <= num push and any element can only be popped once
  
For the binary counter example, the number of implements is the # of bits flipped. (each 1 to 0, 0 to 1).  
Worst case is k swaps for an array of k. and if there is n implementations then it will take O(nk) time.   
  
BUT!  
  
We can claim now that any set of n increments takes O(n) time.  
Cuz for every position from 
```
k-1                  0
----------------------
      ...  n/4  n/2  n
```
  
Each subsequent takes n/2^i flips. So the actual cost is all positions summed together.  
n* sum 1/2^i for all i = 0 to k-1.  
sum 1/s^i is actually a geometric series that will be <2n. so its O(n)!  
  
### Accounting Method
Basically come up with artifical cost for operations (amortized cost). if cost < actual, use as saving, if cost > actual, then owed for next operation.  
Just gotta make sure the sum of Ci hat is enough to cover the actual cost!  
  
For Stack  
```
		Actual    Amortized
Push |     1    |   2
Pop  |     1    |   0
Multipop|  K    |   0
```
Similiar for counter  

### Potential Method
Amortized cost = Ci + change in PE of each state in data structure. (total drop in potential).

Also you must assume that the potential at any stage is at least as big as the beginning state.

So what is a good function to make the starting potential?
New amortized = Ci - potential at previous operation + potential at current operations.  
Potential at any point has to be postive! and always bigger than the initial potential! 
  
### So how this relate to the splay tree?
Invariant - each node of the splay tree holds log(size of subtree) coins.   
lss - log of subtree size (coins).