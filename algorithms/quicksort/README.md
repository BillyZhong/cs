# Quicksort
## Algorithm
The quicksort is a recursive algorithm. The general algorithm is to
call a partition function (which splits the array into two arrays),
and then call the partition function for the two split arrays. This
process is repeated until the arrays are all sorted.
The quicksort begins by taking the full array and choosing a pivot.
Typically, the pivot will be the last element, but that doesn't really
matter because in every case, you still have to iterate through the array
completely.
