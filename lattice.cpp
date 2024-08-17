#include "lattice.h"
#include <random>

LatticeVector generateRandomLatticeVector(int dimension) {
    LatticeVector vec;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-100, 100);

    for (int i = 0; i < dimension; ++i) {
        vec.coordinates.push_back(dist(gen));
    }

    return vec;
}

LatticeVector addLatticeVectors(const LatticeVector &a, const LatticeVector &b) {
    LatticeVector result;
    for (size_t i = 0; i < a.coordinates.size(); ++i) {
        result.coordinates.push_back(a.coordinates[i] + b.coordinates[i]);
    }
    return result;
}

LatticeVector subtractLatticeVectors(const LatticeVector &a, const LatticeVector &b) {
    LatticeVector result;
    for (size_t i = 0; i < a.coordinates.size(); ++i) {
        result.coordinates.push_back(a.coordinates[i] - b.coordinates[i]);
    }
    return result;
}

int dotProduct(const LatticeVector &a, const LatticeVector &b) {
    int result = 0;
    for (size_t i = 0; i < a.coordinates.size(); ++i) {
        result += a.coordinates[i] * b.coordinates[i];
    }
    return result;
}
