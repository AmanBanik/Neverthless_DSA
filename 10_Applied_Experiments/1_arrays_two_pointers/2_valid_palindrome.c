#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * Applied: Two Pointers - Valid Palindrome
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters 
 * and removing all non-alphanumeric characters, it reads the same forward and backward.
 *
 * Approach: Two Pointers starting from ends, skipping non-alphanumeric chars.
 * Time: O(N), Space: O(1)
 */

int isPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters from left
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        // Skip non-alphanumeric characters from right
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        // Compare case-insensitively
        if (tolower(s[left]) != tolower(s[right])) {
            return 0; // False
        }
        
        left++;
        right--;
    }
    return 1; // True
}

int main() {
    printf("--- Valid Palindrome Test Cases ---\n\n");
    
    char str1[] = "A man, a plan, a canal: Panama";
    printf("String: \"%s\"\n", str1);
    if (isPalindrome(str1)) printf("Result: Is a Palindrome!\n\n");
    else printf("Result: Not a Palindrome.\n\n");
    
    char str2[] = "race a car";
    printf("String: \"%s\"\n", str2);
    if (isPalindrome(str2)) printf("Result: Is a Palindrome!\n\n");
    else printf("Result: Not a Palindrome.\n\n");
    
    return 0;
}
