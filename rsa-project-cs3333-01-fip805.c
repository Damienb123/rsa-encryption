#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate greatest common divisor (GCD) of two numbers
unsigned long gcd(unsigned long a, unsigned long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to calculate modulo inverse using extended Euclidean algorithm
unsigned long modInverse(unsigned long a, unsigned long m) {
    unsigned long m0 = m, t, q;
    unsigned long x0 = 0, x1 = 1;
    if (m == 1) return 0;
    
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

// Function to generate keys for RSA encryption
void generateKeys(unsigned long p, unsigned long q, unsigned long *n, unsigned long *e, unsigned long *d) {
    *n = p * q;
    unsigned long phi = (p - 1) * (q - 1);
    
    *e = 2;
    while (*e < phi) {
        if (gcd(*e, phi) == 1)
            break;
        else
            (*e)++;
    }
    
    *d = modInverse(*e, phi);
}

// Function to encrypt plaintext using RSA
unsigned long encrypt(unsigned long plaintext, unsigned long e, unsigned long n) {
    unsigned long result = 1;
    unsigned long base = plaintext % n;
    while (e > 0) {
        if (e % 2 == 1) result = (result * base) % n;
        base = (base * base) % n;
        e /= 2;
    }
    return result;
}

// Function to decrypt ciphertext using RSA
unsigned long decrypt(unsigned long ciphertext, unsigned long d, unsigned long n) {
    unsigned long result = 1;
    unsigned long base = ciphertext % n;
    while (d > 0) {
        if (d % 2 == 1) result = (result * base) % n;
        base = (base * base) % n;
        d /= 2;
    }
    return result;
}

int main() {
    unsigned long p, q, n, e, d;
    printf("Enter p and q: ");
    scanf("%lu %lu", &p, &q);

    // Generate RSA keys
    generateKeys(p, q, &n, &e, &d);
    printf("Public key (e, n): (%lu, %lu)\n", e, n);
    printf("Private key (d, n): (%lu, %lu)\n\n", d, n);

    // Encrypt and decrypt a sample plaintext
    unsigned long plaintext;
    printf("Enter an integer between 0 and n-1 as plain text to be encrypted: ");
    scanf("%lu", &plaintext);
    printf("Original plaintext: %lu\n", plaintext);

    unsigned long ciphertext = encrypt(plaintext, e, n);
    printf("Encrypted ciphertext: %lu\n", ciphertext);

    unsigned long decrypted = decrypt(ciphertext, d, n);
    printf("Decrypted plaintext: %lu\n\n", decrypted);

    return 0;
}
