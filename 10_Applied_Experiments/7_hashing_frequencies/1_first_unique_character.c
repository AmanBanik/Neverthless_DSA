#include <stdio.h>
#include <string.h>

/*
 * Applied: Hashing/Frequencies - First Unique Character in a String
 * Given a string s, find the first non-repeating character in it and return its index. 
 * If it does not exist, return -1.
 *
 * Approach: Array as a Hash Map
 * Since characters have ASCII values (0-255), we can use a fixed size array of 256
 * to count frequencies in O(N) time.
 * Time: O(N), Space: O(1) (Since array is fixed size of 256)
 */

int firstUniqChar(char *s) {
    int count[256] = {0}; // Hash map for character frequencies
    int len = strlen(s);
    
    // First pass: Build the frequency hash map
    for (int i = 0; i < len; i++) {
        count[(int)s[i]]++;
    }
    
    // Second pass: Find the first character with frequency 1
    for (int i = 0; i < len; i++) {
        if (count[(int)s[i]] == 1) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    printf("--- First Unique Character Test Cases ---\n\n");
    
    char s1[] = "leetcode";
    printf("String: \"%s\"\n", s1);
    printf("First Unique Index: %d (Expected: 0, which is 'l')\n\n", firstUniqChar(s1));
    
    char s2[] = "loveleetcode";
    printf("String: \"%s\"\n", s2);
    printf("First Unique Index: %d (Expected: 2, which is 'v')\n\n", firstUniqChar(s2));
    
    char s3[] = "aabb";
    printf("String: \"%s\"\n", s3);
    printf("First Unique Index: %d (Expected: -1)\n", firstUniqChar(s3));
    
    return 0;
}
