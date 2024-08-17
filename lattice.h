#ifndef LATTICE_H
#define LATTICE_H

#include <vector>

// Structure representing a lattice vector
struct LatticeVector {
    std::vector<int> coordinates;
};

// Lattice operations
LatticeVector generateRandomLatticeVector(int dimension);
LatticeVector addLatticeVectors(const LatticeVector &a, const LatticeVector &b);
LatticeVector subtractLatticeVectors(const LatticeVector &a, const LatticeVector &b);
int dotProduct(const LatticeVector &a, const LatticeVector &b);

#endif // LATTICE_H
