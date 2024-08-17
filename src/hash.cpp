#include "hash.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

std::string applyHash(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);

    std::ostringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

std::string createHashChain(const std::string& message, int iterations) {
    std::string currentHash = message;
    for (int i = 0; i < iterations; ++i) {
        currentHash = applyHash(currentHash);
    }
    return currentHash;
}
