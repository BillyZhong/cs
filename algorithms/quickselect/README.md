# Quickselect
## Algorithm
The quickselect algorithm is a modified quicksort algorithm.
It is also a top-down, recursive algorithm and selects the
k-th smallest integer in linear time. Much like quicksort,
it uses a partition function to ensure all less than elements
and greater than elements are on the left and right side
(respectively) of the pivot. Then, it only calls the partition
function again on the side with the `k` index in its bound. It
recursively calls itself until the `k` index is the pivot index
## Partition
This partition function is the exact same function used in the
quicksort algorithm. It selects a pivot (typically the last
last element) and swaps the lesser and greater elements and
finally the pivot in between the correctly positioned lesser
and greater elements. Finally, it returns the final position
of the pivot `i`
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
## Recursion
The recursion function works similar to that of the quicksort
recursion function. The partition is called and the final index
of the pivot is returned as `v`. Then, if `k` is less than `v`,
the k-th smallest element will be found in the left subarray. If
`k` is greater than `v` then the k-th smallest element will be found
in the right subarray. Lastly, the base case, if `k` is equal to the
pivot index, that means that the pivot is the k-th smallest element
because then there are `k-1` elements less than it.
```
void q(int* a, int k, int l, int h){
  int v = p(a, l, h);
  if(k < v){
    q(a, k, l, v-1);
  }
  else if(k == v){
    cout << a[v] << endl;
  }
  else{
    q(a, k, v+1, h);
  }
}
```
## Time Complexity
The quickselect runs in linear `O(n)` time. This is because
the algorithm has a number of total operations similar to that
of a geometric series with a ratio of `0 < r < 1`. Taking the upper
bound, the number of operations can be represented by the infinite
sum

![](https://github.com/BillyZhong/cs/raw/master/algorithms/quickselect/proof.png)

For any constant ratio `r`, we can see that the infinite geometric sum
will always be bounded by some constant `c`, and thus the number of
operations will always be `n` times a constant or `O(n)`
![](https://github.com/BillyZhong/cs/raw/master/algorithms/quickselect/quickselect.png)
## Space Complexity
The quicksort requires `O(n)` space. It only needs space for the `n`
elements of the input array and a single constant space for the input
`k`
