#include "crypto.h"
#include "lattice.h"
#include "hash.h"
#include <random>
#include <iostream>

KeyPair generateKeyPair(int dimension) {
    KeyPair keyPair;
    keyPair.secretKey = generateRandomLatticeVector(dimension);
    keyPair.publicKey = addLatticeVectors(keyPair.secretKey, keyPair.secretKey); // Example operation
    return keyPair;
}

std::vector<int> encryptMessage(const std::vector<int>& message, const std::vector<int>& publicKey) {
    std::vector<int> encryptedMessage = message;
    for (size_t i = 0; i < encryptedMessage.size(); ++i) {
        encryptedMessage[i] += publicKey[i]; // Basic encryption
    }
    return encryptedMessage;
}

std::vector<int> decryptMessage(const std::vector<int>& encryptedMessage, const std::vector<int>& secretKey) {
    std::vector<int> decryptedMessage = encryptedMessage;
    for (size_t i = 0; i < decryptedMessage.size(); ++i) {
        decryptedMessage[i] -= secretKey[i]; // Basic decryption
    }
    return decryptedMessage;
}

bool verifyMessageIntegrity(const std::vector<int>& original, const std::vector<int>& decrypted) {
    return original == decrypted;
}
