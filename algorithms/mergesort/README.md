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
```
void s(int* a, int* b, int l, int h, int n){
  if(l < h){
    int m = (l+h)/2;
    s(a, b, l, m, n);
    s(a, b, m+1, h, n);
    ms(a, b, l, m, h, n);
  }
}
```
## Merge (Sort)
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
