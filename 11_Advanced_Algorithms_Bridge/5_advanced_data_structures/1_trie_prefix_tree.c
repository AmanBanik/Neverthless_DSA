#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Advanced DS: Trie (Prefix Tree)
 * Extremely fast for string search and prefix matching (Autocomplete).
 * Time Complexity: O(L) for insert/search where L is the length of the word.
 */

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord; // 1 if this node marks the end of a valid word
} TrieNode;

TrieNode* createNode() {
    TrieNode* pNode = (TrieNode*)malloc(sizeof(TrieNode));
    pNode->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = NULL;
    }
    return pNode;
}

// Insert a word into the Trie
void insert(TrieNode* root, const char* key) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a'; // Assuming lowercase 'a'-'z'
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = createNode();
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = 1; // Mark the last node as leaf
}

// Search for an exact word in the Trie
int search(TrieNode* root, const char* key) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) {
            return 0; // Not found
        }
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// Check if a prefix exists in the Trie
int startsWith(TrieNode* root, const char* prefix) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < strlen(prefix); i++) {
        int index = prefix[i] - 'a';
        if (!pCrawl->children[index]) {
            return 0; // Prefix not found
        }
        pCrawl = pCrawl->children[index];
    }
    return 1; // Prefix found
}

int main() {
    printf("--- Trie (Prefix Tree) Test Cases ---\n\n");
    
    TrieNode* root = createNode();
    
    printf("Inserting: 'apple', 'app', 'banana', 'bat'\n\n");
    insert(root, "apple");
    insert(root, "app");
    insert(root, "banana");
    insert(root, "bat");
    
    printf("Search 'apple':   %s\n", search(root, "apple") ? "Found" : "Not Found");
    printf("Search 'app':     %s\n", search(root, "app") ? "Found" : "Not Found");
    printf("Search 'appl':    %s (It's a prefix, but not a full word)\n", search(root, "appl") ? "Found" : "Not Found");
    printf("Search 'batman':  %s\n\n", search(root, "batman") ? "Found" : "Not Found");
    
    printf("Prefix Check 'ban':  %s\n", startsWith(root, "ban") ? "Exists" : "Does Not Exist");
    printf("Prefix Check 'appl': %s\n", startsWith(root, "appl") ? "Exists" : "Does Not Exist");
    printf("Prefix Check 'cat':  %s\n", startsWith(root, "cat") ? "Exists" : "Does Not Exist");
    
    return 0;
}
