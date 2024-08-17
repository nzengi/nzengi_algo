#ifndef LATTICE_H
#define LATTICE_H

#include <vector>

// Lattice vector operations
std::vector<int> generateRandomLatticeVector(int dimension);
std::vector<int> addLatticeVectors(const std::vector<int>& a, const std::vector<int>& b);
std::vector<int> subtractLatticeVectors(const std::vector<int>& a, const std::vector<int>& b);
int dotProduct(const std::vector<int>& a, const std::vector<int>& b);

#endif // LATTICE_H
