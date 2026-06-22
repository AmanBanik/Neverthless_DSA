# Walkthrough: String Algorithms

Strings are basically arrays of characters, but string manipulation introduces specific problems, heavily focused on **Pattern Matching** (finding a substring within a larger text).

## 1. Naive Pattern Matching
Compare the pattern with every single sliding window in the text.
* Time Complexity: $O(M \times (N-M+1))$ where N is text length, M is pattern length. Very slow for repetitive patterns like finding "AAAA" inside "AAAAAAAAA".

## 2. KMP (Knuth-Morris-Pratt) Algorithm
Optimizes pattern matching to $O(N)$.
It pre-processes the pattern to create an **LPS (Longest Proper Prefix which is also Suffix)** array. 
* When a mismatch occurs, instead of resetting the search entirely, KMP uses the LPS array to know exactly how far to skip ahead, guaranteeing the text pointer never moves backwards!

## 3. Rabin-Karp Algorithm
Also $O(N)$ average time. Instead of matching characters, it computes a **Rolling Hash** of the sliding window in the text.
* If the hash of the window matches the hash of the pattern, it does a character-by-character check.
* Highly useful for detecting plagiarism or searching for multiple patterns simultaneously.
