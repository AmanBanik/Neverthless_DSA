#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7

/*
 * Hashing: Scatter Tables using Open Addressing (Linear Probing)
 */

typedef struct {
    int key;
    int isOccupied; // 0 if empty, 1 if occupied
} HashEntry;

HashEntry hashTable[TABLE_SIZE];

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].isOccupied = 0;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert using Linear Probing
void insert(int key) {
    int index = hash(key);
    int original_index = index;
    
    while (hashTable[index].isOccupied) {
        printf("Collision at index %d for key %d! Probing...\n", index, key);
        index = (index + 1) % TABLE_SIZE; // Linear Probe
        
        if (index == original_index) {
            printf("Hash Table is Full!\n");
            return;
        }
    }
    
    hashTable[index].key = key;
    hashTable[index].isOccupied = 1;
    printf("Inserted %d at index %d\n", key, index);
}

// Search using Linear Probing
int search(int key) {
    int index = hash(key);
    int original_index = index;
    
    while (hashTable[index].isOccupied) {
        if (hashTable[index].key == key) return index;
        
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index) break; // Traversed whole table
    }
    return -1;
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].isOccupied)
            printf("[%d]: %d\n", i, hashTable[i].key);
        else
            printf("[%d]: EMPTY\n", i);
    }
    printf("\n");
}

int main() {
    printf("--- Open Addressing (Linear Probing) Test Cases ---\n\n");
    
    initTable();
    
    // Insertions causing collisions
    insert(10); // 10 % 7 = 3
    insert(20); // 20 % 7 = 6
    insert(17); // 17 % 7 = 3 (COLLISION!) -> should go to 4
    insert(24); // 24 % 7 = 3 (COLLISION!) -> should go to 5
    
    display();
    
    printf("Search for 17: ");
    int res = search(17);
    if(res != -1) printf("Found at index %d\n", res);
    else printf("Not found\n");
    
    printf("Search for 100: ");
    res = search(100);
    if(res != -1) printf("Found at index %d\n", res);
    else printf("Not found\n");
    
    return 0;
}
