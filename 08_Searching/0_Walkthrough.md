# Walkthrough: Searching Algorithms

Searching is the process of finding the location of a given element within a collection.

## 1. Sequential (Linear) Search
* **Unordered Sequential Search:** Checks each element one by one from the beginning until the element is found. $O(N)$ time.
* **Ordered Sequential Search:** Same as unordered, but stops early if it encounters an element greater than the target (assuming the array is sorted). $O(N)$ worst case, but better average case for missing elements.

## 2. Binary Search
Requires the array to be **sorted**.
* Works by repeatedly dividing the search interval in half.
* If the target is less than the middle element, it narrows the interval to the lower half. Otherwise, to the upper half.
* **Time Complexity:** $O(\log N)$. Extremely fast for large datasets.

## 3. Interpolation Search
An improvement over Binary Search for instances where the values in a sorted array are **uniformly distributed**.
* Instead of always picking the middle element, it tries to estimate the position based on the value of the target.
* Example: If searching for a word starting with 'Z' in a dictionary, you don't start in the middle ('M'), you start near the end.
* **Time Complexity:** $O(\log (\log N))$ average case, but degrades to $O(N)$ if data is not uniformly distributed.
