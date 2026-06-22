# Walkthrough: Sorting Algorithms

Sorting arranges data in a specific order (ascending or descending). 

## 1. Insertion Sorts
* **Straight Insertion Sort:** Builds the sorted array one element at a time by picking the next element and inserting it into its correct position in the sorted part. $O(N^2)$ time.
* **Binary Insertion Sort:** Uses Binary Search to find the correct insertion position, reducing comparisons, but shifting still takes $O(N^2)$.
* **Shell Sort:** An optimization of Insertion Sort that compares elements far apart (using a "gap" sequence) and gradually reduces the gap. Time complexity depends on the gap sequence, usually $O(N \log N)$ to $O(N^{3/2})$.

## 2. Exchange Sorts
* **Bubble Sort:** Repeatedly swaps adjacent elements if they are in the wrong order. Heaviest elements "bubble" to the end. $O(N^2)$ time.
* **Quick Sort:** Divide and conquer. Picks a "pivot", places smaller elements to the left, larger to the right, and recursively sorts sub-arrays. $O(N \log N)$ average, $O(N^2)$ worst case.

## 3. Selection Sorts
* **Straight Selection Sort:** Repeatedly finds the minimum element from the unsorted part and puts it at the beginning. $O(N^2)$ time.
* **Heap Sort:** Builds a Max Heap from the array, then repeatedly extracts the max element to the end of the array. $O(N \log N)$ time guaranteed.

## 4. Merge Sort
Divide and conquer. Divides the array into halves until each has 1 element, then merges them back in sorted order. $O(N \log N)$ guaranteed time, but requires $O(N)$ extra space.

## 5. Distribution Sorts
* **Bucket Sort:** Distributes elements into "buckets", sorts each bucket individually, and concatenates them. Good for uniformly distributed floating-point numbers.
* **Radix Sort:** Sorts elements digit by digit, from least significant digit (LSD) to most significant digit (MSD), using counting sort as a subroutine. $O(d \cdot N)$ time.
