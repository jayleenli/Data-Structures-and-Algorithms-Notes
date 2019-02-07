# Hashing Notes

## Example Problems
We use a random hash function to map n keys into a table of size m, where m is
an even integer. What is the probability that no key hashes into an odd-numbered
location?

By universal hashing theorem, we know that the probability that a key will hash to the same slot of another is 1/m. Where m is the table size. Since we are looking for no keys hashing to odd numbers keys, we only want collisions at even keys. The probability then of a key hasing to a even slot is (m/2)/m = 1/2. 
Applying this probability to n keys, we get the probability that all keys has to odd numbered slots is (1/2)^n.