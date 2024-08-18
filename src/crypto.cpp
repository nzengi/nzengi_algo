#include <vector>
#include <random>
#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>

struct KeyPair {
    std::vector<int> secretKey;
    std::vector<int> publicKey;
};

// RSA Anahtar Çifti Üretimi
KeyPair generateKeyPair(int bits) {
    KeyPair keyPair;
    
    // RSA anahtar çifti oluşturulması
    RSA *rsa = RSA_new();
    BIGNUM *bn = BN_new();
    BN_set_word(bn, RSA_F4);

    if (RSA_generate_key_ex(rsa, bits, bn, nullptr) != 1) {
        std::cerr << "RSA key generation failed\n";
        return keyPair;
    }

    // Public Key'yi ve Private Key'yi PEM formatında al
    BIO *pub = BIO_new(BIO_s_mem());
    BIO *priv = BIO_new(BIO_s_mem());

    PEM_write_bio_RSAPublicKey(pub, rsa);
    PEM_write_bio_RSAPrivateKey(priv, rsa, nullptr, nullptr, 0, nullptr, nullptr);

    // Public ve Private Key'leri okuma
    char *pub_key = nullptr;
    char *priv_key = nullptr;
    long pub_len = BIO_get_mem_data(pub, &pub_key);
    long priv_len = BIO_get_mem_data(priv, &priv_key);

    // Anahtarları vektörlere dönüştür
    keyPair.publicKey = std::vector<int>(pub_key, pub_key + pub_len);
    keyPair.secretKey = std::vector<int>(priv_key, priv_key + priv_len);

    // Belleği serbest bırakma
    BIO_free_all(pub);
    BIO_free_all(priv);
    RSA_free(rsa);
    BN_free(bn);

    return keyPair;
}

std::vector<int> encryptMessage(const std::vector<int>& message, const std::vector<int>& publicKey) {
    // RSA ile şifreleme
    // ...
    return message;
}

std::vector<int> decryptMessage(const std::vector<int>& encryptedMessage, const std::vector<int>& secretKey) {
    // RSA ile şifre çözme
    // ...
    return encryptedMessage;
}

bool verifyMessageIntegrity(const std::vector<int>& original, const std::vector<int>& decrypted) {
    return original == decrypted;
}

int main() {
    int bits = 2048; // RSA anahtar uzunluğu
    KeyPair keys = generateKeyPair(bits);

    std::vector<int> message = {1, 2, 3, 4, 5};
    std::vector<int> encryptedMessage = encryptMessage(message, keys.publicKey);
    std::vector<int> decryptedMessage = decryptMessage(encryptedMessage, keys.secretKey);

    if (verifyMessageIntegrity(message, decryptedMessage)) {
        std::cout << "Message integrity verified!\n";
    } else {
        std::cout << "Message integrity check failed.\n";
    }

    return 0;
}
