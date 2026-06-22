#include <stdio.h>
#include <string.h>

/*
 * Advanced: Cryptography - Basic Ciphers
 * Demonstrating the Caesar Shift Cipher and the XOR Cipher.
 */

// --- 1. Caesar Cipher ---
void caesarEncrypt(char *msg, int shift) {
    for (int i = 0; msg[i] != '\0'; i++) {
        char c = msg[i];
        if (c >= 'A' && c <= 'Z') {
            msg[i] = (char)((c - 'A' + shift) % 26 + 'A');
        } else if (c >= 'a' && c <= 'z') {
            msg[i] = (char)((c - 'a' + shift) % 26 + 'a');
        }
    }
}

void caesarDecrypt(char *msg, int shift) {
    // Decrypting is just shifting backwards (adding 26 - shift)
    caesarEncrypt(msg, 26 - (shift % 26)); 
}

// --- 2. XOR Cipher ---
// XOR is its own inverse! msg ^ key = ciphertext -> ciphertext ^ key = msg
void xorCipher(char *msg, char key) {
    for (int i = 0; msg[i] != '\0'; i++) {
        msg[i] = msg[i] ^ key;
    }
}

int main() {
    printf("--- Basic Cryptography Test Cases ---\n\n");
    
    char msg1[] = "Hello World";
    int shift = 3;
    
    printf("[ Caesar Cipher ]\n");
    printf("Original:  %s\n", msg1);
    caesarEncrypt(msg1, shift);
    printf("Encrypted: %s (Shift %d)\n", msg1, shift);
    caesarDecrypt(msg1, shift);
    printf("Decrypted: %s\n\n", msg1);
    
    
    char msg2[] = "SecretData";
    char xorKey = 'K'; // Simple 1-byte key
    
    printf("[ XOR Cipher ]\n");
    printf("Original:  %s\n", msg2);
    xorCipher(msg2, xorKey);
    printf("Encrypted: %s (Key '%c')\n", msg2, xorKey);
    xorCipher(msg2, xorKey);
    printf("Decrypted: %s\n", msg2);
    
    return 0;
}
