#include "crypto.h"
#include "lattice.h"
#include <iostream>

int main() {
    const int dimension = 10;

    // Generate a key pair
    KeyPair keys = generateKeyPair(dimension);

    // Create a random message vector
    std::vector<int> message = generateRandomLatticeVector(dimension);

    // Encrypt the message
    std::vector<int> encryptedMessage = encryptMessage(message, keys.publicKey);

    // Decrypt the message
    std::vector<int> decryptedMessage = decryptMessage(encryptedMessage, keys.secretKey);

    // Verify the message integrity
    if (verifyMessageIntegrity(message, decryptedMessage)) {
        std::cout << "Message integrity verified!" << std::endl;
    } else {
        std::cout << "Message integrity check failed!" << std::endl;
    }

    return 0;
}
