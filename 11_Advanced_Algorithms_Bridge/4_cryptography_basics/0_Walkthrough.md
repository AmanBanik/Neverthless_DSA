# Walkthrough: Cryptography & Hashing

While module 09 taught Hash Tables for data storage, cryptography uses hashing and algorithmic transformations to secure data.

## 1. Classical Ciphers (Historical)
Algorithms that operated on characters.
* **Caesar Cipher:** A simple substitution cipher where each letter is shifted by a fixed number of positions down the alphabet (e.g., shift of 3: A becomes D). Trivial to break using frequency analysis.
* **XOR Cipher:** Uses the bitwise XOR operator `^`. A highly powerful property: `(Message ^ Key) ^ Key = Message`. It forms the basis of many modern stream ciphers.

## 2. Cryptographic Hash Functions
Unlike `key % table_size`, cryptographic hashes (like SHA-256 or MD5) are:
1. **Deterministic:** Same input always yields the same hash.
2. **One-Way (Pre-image resistant):** Impossible to reverse the hash to find the original input.
3. **Collision Resistant:** Incredibly rare for two different inputs to produce the same hash.
Used in storing passwords securely (you store the hash, not the password itself).

## 3. Modern Encryption
* **Symmetric Encryption (AES):** Uses the same key to encrypt and decrypt. Extremely fast. Used for bulk data encryption.
* **Asymmetric Encryption (RSA):** Uses a Public Key to encrypt and a Private Key to decrypt. Based on the mathematical difficulty of factoring large prime numbers. Used for secure key exchange over the internet (HTTPS/TLS).
