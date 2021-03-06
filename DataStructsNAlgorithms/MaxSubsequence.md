# Notes on the four different ways to solve the Max Subsequence Problem. 

## Method 1: O(n^3)
 - Find all the subsequences, find each subsequence value, and then find the max value of all the possible values. 
```
 for i=1 to n
  for j=i to n
   thisSum = 0
 	for k = i to j
 	 thisSum+= ak //a of k
 	 if thisSum > maxSum
	  maxSum = thisSum
return maxSum
```
 This algorithm is correct, but it will add numbers over again when not really needed.
 For example, 3, -1, -1, 2
 This method would add the already added together numbers over again.

## Method 2: O(n^2)
 - Instead of recounting numbers, just add it to thisSum
```
 maxSum = 0; I = J = 0
 for i = 1 to n
 	thisSum = 0
 	for j = i to n
 	 thisSum += ak //a of k
 	 if thisSum > maxSum
 		maxSum = thisSum
 		I = i, J= j
 return maxSum, I, J
```
 Algorithm fixes a start index i then evaluates all subsequences that start at i and end at j = i, i+1...n and computes the sum without recounting numbers.

 Method 3: O (nlogn)
  - A divide and conquer based algorithm

  Basically, if the whole array is split in half, there are 3 possibilities of what can happen.
  	1. Max subsequence in left half
  	2. max subsequence in right half
  	3. the max subsequence includes the midpoint, or starts there

  For example, suppose S = (4, −3, 5, −2, −1, 2, 6, −2). Then, (4, −3, 5) is the max subseq in left half, (2, 6) is the max subseq in right half.

  But the straddling sequence (4, −3, . . . , 6) is the global max subsequence for S, with value 11.

  We find the max subsequences in left and right haves by recursion.
  The key observation is the following:
	1. The left half of the straddling sequence is the max subsequence ending with -2 (namely, an/2)..
	2. The right half is the max subsequence beginning with -1 (namely, an/2+1)..
	3. Call these anchored subsequences: one of their endpoints is fixed, and we just need to find the other endpoint.
	4. We can find the free (other) endpoint by a simple linear scan: starting at an/2, keep track of the left subsequence sum, and finally return the one with max value. Similarly, for the right anchored subseq.
	5. Thus, the straddling max subseq. can be found in O(n) time.

## Method 4: O(n)
```
 maxSum = 0; thisSum = 0; I=J=0;
 for j = 1 to n
 	thisSum += aj //a of j
 	if thisSum > maxSum
 		maxSum = thisSum; J = j;
 	else if thisSum < 0
 		thisSum = 0; I = j+1;
 return maxSum, I, J
```
 This only works because of special reasons of max subsequence.
 1. maxSum can never start with a negative number.
 	This is because you can just take the negative number out, and you will have a greater subsequence than the one before taking the negative number out.
 2. Similiarly, maxSum cannot end with a negative number.
 	This is for the same reason, if you take out the negative number from the max Subsequence, you will get a greater number. 
 3. There will never be another subsequence inside the current sequence between two negatives that will also be the max subsequence.
 	Assume a of i and a of j is the subsequence where the beginning and ending negative number have been cut off. 
 	There can never exist such a p between i and j that is the max subsequence.
 	This would cause a contradiction. This is why it is ok to set thisSum to 0 once a negative value is encountered.