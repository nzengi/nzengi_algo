#include "lattice.h"
#include "math_utils.h"

// Simple LLL lattice reduction algorithm
void lllReduction(std::vector<LatticeVector> &basis, int dimension) {
    bool reduced = false;
    while (!reduced) {
        reduced = true;
        for (size_t i = 1; i < basis.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                int scalar = dotProduct(basis[i], basis[j]) / dotProduct(basis[j], basis[j]);
                for (int k = 0; k < dimension; ++k) {
                    basis[i].coordinates[k] -= scalar * basis[j].coordinates[k];
                }
            }
            if (dotProduct(basis[i], basis[i]) < dotProduct(basis[i-1], basis[i-1])) {
                std::swap(basis[i], basis[i-1]);
                reduced = false;
            }
        }
    }
}
