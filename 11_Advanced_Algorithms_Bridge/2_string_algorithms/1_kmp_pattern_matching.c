#include <stdio.h>
#include <string.h>

/*
 * Advanced: String Algorithms - KMP Pattern Matching
 * Knuth-Morris-Pratt uses an LPS array to avoid redundant comparisons.
 */

// Fills the LPS (Longest Proper Prefix which is also Suffix) array
void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Fallback
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search
void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++; i++;
        }
        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1]; // Look for next match
        } 
        else if (i < N && pat[j] != txt[i]) {
            // Mismatch after j matches
            if (j != 0) j = lps[j - 1]; // Do not match lps[0..lps[j-1]] characters, they will match anyway
            else i = i + 1;
        }
    }
}

int main() {
    printf("--- KMP Pattern Matching Test Cases ---\n\n");
    
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    
    printf("Text:    %s\n", txt);
    printf("Pattern: %s\n\n", pat);
    
    KMPSearch(pat, txt);
    // Expected output: Found pattern at index 10
    
    return 0;
}
