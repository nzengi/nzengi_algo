#ifndef HASH_H
#define HASH_H

#include <string>

// Hashing functions
std::string applyHash(const std::string& input);
std::string createHashChain(const std::string& message, int iterations);

#endif // HASH_H
