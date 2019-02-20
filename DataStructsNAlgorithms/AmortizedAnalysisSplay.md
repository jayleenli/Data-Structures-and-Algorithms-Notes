# Amortized Analysis

Amortized analysis is a worst-case analysis of a a sequence of operations — to obtain a tighter bound on the overall or average cost per operation in the sequence than is obtained by separately analyzing each operation in the sequence. 

Amortized Analysis is used for algorithms where an occasional operation is very slow, but most of the other operations are faster. In Amortized Analysis, we analyze a sequence of operations and guarantee a worst case average time which is lower than the worst case time of a particular expensive operation.

## The Three Method
* The aggregate method, where the total running time for a sequence of operations is analyzed.
* The accounting (or banker's) method, where we impose an extra charge on inexpensive operations and use it to pay for expensive operations later on.
* The potential (or physicist's) method, in which we derive a potential function characterizing the amount of extra work we can do in each step. This potential either increases or decreases with each successive operation, but cannot be negative.