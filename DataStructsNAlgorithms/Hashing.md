# Hashing Notes
## Concepts
- Hash has to be randomly selected, because we don't want to have strong and unrealistic assumptions about the input data. Most data is not random and has depedence, creating data clumping. 

### No Hash function is good function!
Theorem: Suppose hash table of size m is used to store a set S of n keys drawn from universe U, where |U| >nm. Then, no matter which hash functino h: U->{0,1,...m} is chosen, there will always exist a set S in U of n keys that all map to the same location.   
Proof:  
	1. Assume a hash function h.  
	2. map all the keys of U using h to table size m.  
	3. By pigeon hole principle, at least one table slot gets n keys since |U| > nm    
		Ex of pigeon hole is 10 pigeons, 9 boxes, then one box is going to have at least two pigeons.  
	4. Choose those n keys as input set S.  
	5. H will map S to a single location.  
Avoid this issue by making the hash function random.  

### Why we can't just have randomly generated hash functions
Basically, can't guarantee that we will hash back to the same location when we try to access it. Ex. Rolling a new m-sided die for each x to determine the hash value h(x).  

### Universal Hashing
- Prob [h(x) = h(y)] < 1/m for any x,y in U and any h in family of hash function H
- Expected collisions AT ANY HASH LOCATION is <= (n-1)/m. If m=n, then the expected # of collisions is 1. This is O(n/m).

### Resolving Collisions
* Separate Chaining
	* Resolves collisions by maintaining a separate linked list for each hash location, which stores all the keys hashed to that location.
	* Insert, Delete, and find for key x search the linked list at location h(x).
	* Each hash operation takes time O(1+L(x)) where 1 is for accessing the hash table location h(x), and L(x) is for the size of the linked list.
	* By the universal hashing, the expected size of L(x) is O(1), assuming m>=n.
* Open Addressing
	* search the table for open slot (probing)
	* Linear h(x)+i, Quadratic h(x) + i^2, Double h1(x) + ih2(x) probing
	* Issue with deleting.
		* remove will create empty slot, may invalidate search path. Instead mark something as deleted.  


## Example Problems/Proofs
https://math.dartmouth.edu/archive/m19w03/public_html/Section6-5.pdf

1. We use a random hash function to map n keys into a table of size m, where m is
an even integer. What is the probability that no key hashes into an odd-numbered
location?

By universal hashing theorem, we know that the probability that a key will hash to the same slot of another is 1/m. Where m is the table size. Since we are looking for no keys hashing to odd numbers keys, we only want collisions at even keys. The probability then of a key hasing to a even slot is (m/2)/m = 1/2. 
Applying this probability to n keys, we get the probability that all keys has to odd numbered slots is (1/2)^n.