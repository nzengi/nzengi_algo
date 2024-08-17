#include "isogeny.h"

// Example of applying an isogeny transformation
LatticeVector applyIsogenyTransformation(LatticeVector vec) {
    for (int &coord : vec.coordinates) {
        coord = coord * 2 + 1; // Simple example transformation
    }
    return vec;
}

// Example of reversing an isogeny transformation
LatticeVector reverseIsogenyTransformation(LatticeVector vec) {
    for (int &coord : vec.coordinates) {
        coord = (coord - 1) / 2; // Reverses the previous transformation
    }
    return vec;
}
