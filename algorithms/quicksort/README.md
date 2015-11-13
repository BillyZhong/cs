# Quicksort
## Algorithm
The quicksort is a recursive algorithm. The general algorithm is to
call a partition function (which splits the array into two arrays),
and then call the partition function for the two split arrays. This
process is repeated until the arrays are all sorted. Because the
algorithm sorts in-place, there is no need to recombine all the
split arrays
## Partition
The partition function begins by taking the full array and choosing
a pivot. Typically, the pivot will be the last element, but that
doesn't really matter because in every case, you still have to
iterate through the array completely. The task of the partition is
to end up with the pivot somewhere in the array with all elements
less than the pivot to the left of it and all elements greater than
the pivot to the right of it. This is usually achieved by passing
by the numbers greater and swapping the lesser numbers after, then
swapping the pivot with the element between the lesser and greater
numbers
```
int p(int* a, int l, int h){
  int t = 0;
	int v = a[h];
  int i = l;
	for(int j = l; j < h; j++){
		if(a[j] <= v){
			t = a[i];
			a[i] = a[j];
			a[j] = t;
      i++;
		}
	}
	t = a[i];
	a[i] = a[h];
	a[h] = t;
	return i;
}
```
The partition function `p` takes three arguments: the array `a`,
the lower bound of the subarray `l`, and the higher bound of the
subarray `h`. Because of the abstraction of bounds, the partition
array is allowed to work on any part of the array, which is necessary
for recursion. The partition function returns the final position of
the pivot `i`
## Recursion
The recursion function has a base case of low being greater than high
(Basically when subarray length is `1`). The recursion begins with
calling the partition function `p`, then finding the final pivot
index `v` returned from the partition function. Then, it calls itself
for low `l` to one before the pivot `v-1`, and for one after the pivot
`v+1` to high `h`
```
void q(int* a, int l, int h){
	if(l < h){
		int v = p(a, l, h);
		q(a, l, v - 1);
		q(a, v + 1, h);
	}
}
```
## Time Complexity
The time complexity of the quicksort algorithm is linearithmic and thus
has a asymptotic time of `O(nlgn)`. This is because the partition
function, at each level, traverses through the array completely; thus
it has linear `O(n)` time. The quicksort function, on each level, splits
the array into two parts, thus the tree constructed by the array is a
binary tree and has height `lgn`; thus it has time complexity of
logarithmic `O(lgn)` time. `lgn` levels of `n` operations yields `O(nlgn)`
## Space Complexity
The space complexity of the quicksort algorithm is linear and thus has
asymptotic space of `O(n)`. This is because quicksort is an in-place
sorting algorithm and only requires the space for the `n` elements of the
original array and an extra `O(1)` space for swapping.
