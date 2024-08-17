#include "error_correction.h"

// Simple error correction method
LatticeVector errorCorrection(LatticeVector vec) {
    for (int &coord : vec.coordinates) {
        if (coord % 2 != 0) {
            coord -= 1; // Example: adjust odd numbers to even
        }
    }
    return vec;
}

// Check if there are any errors in the vector
bool checkForErrors(LatticeVector vec) {
    for (const int &coord : vec.coordinates) {
        if (coord % 2 != 0) {
            return true; // Found an error
        }
    }
    return false; // No errors found
}
