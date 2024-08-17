#ifndef CRYPTO_H
#define CRYPTO_H

#include <vector>
#include <string>

// Key pair structure
struct KeyPair {
    std::vector<int> secretKey;
    std::vector<int> publicKey;
};

// Cryptographic functions
KeyPair generateKeyPair(int dimension);
std::vector<int> encryptMessage(const std::vector<int>& message, const std::vector<int>& publicKey);
std::vector<int> decryptMessage(const std::vector<int>& encryptedMessage, const std::vector<int>& secretKey);
bool verifyMessageIntegrity(const std::vector<int>& original, const std::vector<int>& decrypted);

#endif // CRYPTO_H
