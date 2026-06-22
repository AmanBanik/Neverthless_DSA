#include <stdio.h>
#include <string.h>

/*
 * Applied: Stacks - Valid Parentheses
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 *
 * Approach: Stack
 * Push opening brackets. When encountering a closing bracket, pop the stack 
 * and check if it matches the corresponding opening bracket.
 * Time: O(N), Space: O(N)
 */

int isValid(char *s) {
    int len = strlen(s);
    char stack[1000]; // Simplification for C
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } 
        else {
            if (top == -1) return 0; // Stack empty, invalid
            
            char popped = stack[top--];
            if (c == ')' && popped != '(') return 0;
            if (c == '}' && popped != '{') return 0;
            if (c == ']' && popped != '[') return 0;
        }
    }
    
    return top == -1; // Valid if stack is completely empty at the end
}

int main() {
    printf("--- Valid Parentheses Test Cases ---\n\n");
    
    char s1[] = "()[]{}";
    printf("String: \"%s\"\n", s1);
    printf("Result: %s\n\n", isValid(s1) ? "Valid" : "Invalid");
    
    char s2[] = "(]";
    printf("String: \"%s\"\n", s2);
    printf("Result: %s\n\n", isValid(s2) ? "Valid" : "Invalid");
    
    char s3[] = "{[()]}";
    printf("String: \"%s\"\n", s3);
    printf("Result: %s\n\n", isValid(s3) ? "Valid" : "Invalid");
    
    return 0;
}
