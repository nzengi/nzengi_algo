#include "math_utils.h"

// Calculate the modular inverse of a with respect to mod
int modularInverse(int a, int mod) {
    int t = 0, newT = 1;
    int r = mod, newR = a;

    while (newR != 0) {
        int quotient = r / newR;
        int tempT = t - quotient * newT;
        t = newT;
        newT = tempT;

        int tempR = r - quotient * newR;
        r = newR;
        newR = tempR;
    }

    if (r > 1) {
        return -1; // No inverse exists
    }

    if (t < 0) {
        t += mod;
    }

    return t;
}

// Compute the greatest common divisor using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
