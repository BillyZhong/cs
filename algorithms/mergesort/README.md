# Mergesort
## Algorithm
The mergesort is a bottom-up, recursive algorithm. It works by dividing
the array into subarrays of length `1` and then merging the subarrays
using a linear sorting function until it reforms the original array. The
linear sorting algorithm compares the first index of both arrays being
merged and places the lesser one first into the new array, moving the
sub-array up. The algorithm requires the copying back and forth between
the original array and a temporary array.
## Divide (Recursion)
## Merge (Sort)
## Time Complexity
The mergesort algorithm has asymptotic `O(nlgn)` time. It breaks down the
array into single element arrays in `O(lgn)` time because it breaks down in
the form of a binary tree, which has height `lgn`. Then, it builds back up,
merging two split arrays, which forms the same binary tree and thus still
has `lgn` height. At each step of this merging, a linear `O(n)` time sorting
function is run and thus the entire algorithm has linearithmic time.
![](https://github.com/BillyZhong/cs/raw/master/algorithms/mergesort/mergesort.png)
## Space Complexity
This algorithm has asymptotic `O(n)` space. It requires two arrays of `n`
length, one to store the original array, and one temporary array to substitute
for inserting into the original.
