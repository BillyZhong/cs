# Mergesort
## Algorithm
The mergesort is a bottom-up, recursive algorithm. It works by dividing
the array into subarrays of length `1` and then merging the subarrays
using a linear sorting function until it reforms the original array. The
linear sorting algorithm compares the first index of both arrays being
merged and places the lesser one first into the new array, moving the
sub-array up. The algorithm requires the copying back and forth between
the original array and a temporary array
## Divide (Recursion)
The recursion function calls on itself, dividing the array or each subarray
into two arrays each time. It calculates the middle between the low and high
values and passes it as the high or low value to split the array into the first
half or the second half respectively. It will stop when the base case of the
lower bound being greater than or equal to the higher bound is satisfied
(or when the array length is `1`). After there are `n` subarrays of length
`1`, the merge function will be called for each pair of split subarrays.
```
void d(int* a, int* b, int l, int h, int n){
  if(l < h){
    int m = (l+h)/2;
    d(a, b, l, m, n);
    d(a, b, m+1, h, n);
    ms(a, b, l, m, h, n);
  }
}
```
The recursion function `d` requires five arguments. It takes arrays `a` (the
original array) and `b` (the temporary array) and the original array length
`n` to pass to the merge function. It also has parameters low `l` and high `h`
to be able to work on a specific run of the array.
## Merge (Sort)
The merge function starts by copying the temporary array `b` back onto array
`a` (`b` initially is the same value as `a`). Then, for each element in the
subarray of `a`, the function checks which is smaller and assigns it to the
corresponding position in a subarray of `b`. When one of the smaller subarrays
has no more elements, the remainder of the other subarray is assigned to their
positions in array `b`. This is why the algorithm uses a temporary array;
copying back and forth allows the algorithm to move level by level up the
tree. The merge function, being bottom-up runs on the assumption that all
subarrays being merged are sorted
```
void ms(int* a, int* b, int l, int m, int h, int n){
  copy(b, b+n, a);
  int i = l;
  int j = m+1;
  for(int k = l; k < h+1; k++){
    if(i > m){
      b[k] = a[j];
      j++;
    }
    else if(j > h){
      b[k] = a[i];
      i++;
    }
    else if(a[i] <= a[j]){
      b[k] = a[i];
      i++;
    }
    else if(a[j] < a[i]){
      b[k] = a[j];
      j++;
    }
  }
}
```
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
