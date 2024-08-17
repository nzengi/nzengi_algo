#include "lattice.h"
#include <random>

std::vector<int> generateRandomLatticeVector(int dimension) {
    std::vector<int> vec(dimension);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-100, 100);

    for (int& coord : vec) {
        coord = dist(gen);
    }

    return vec;
}

std::vector<int> addLatticeVectors(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] + b[i];
    }
    return result;
}

std::vector<int> subtractLatticeVectors(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] - b[i];
    }
    return result;
}

int dotProduct(const std::vector<int>& a, const std::vector<int>& b) {
    int result = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }
    return result;
}
