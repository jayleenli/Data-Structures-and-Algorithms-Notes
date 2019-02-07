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


## Example Problems
We use a random hash function to map n keys into a table of size m, where m is
an even integer. What is the probability that no key hashes into an odd-numbered
location?

By universal hashing theorem, we know that the probability that a key will hash to the same slot of another is 1/m. Where m is the table size. Since we are looking for no keys hashing to odd numbers keys, we only want collisions at even keys. The probability then of a key hasing to a even slot is (m/2)/m = 1/2. 
Applying this probability to n keys, we get the probability that all keys has to odd numbered slots is (1/2)^n.