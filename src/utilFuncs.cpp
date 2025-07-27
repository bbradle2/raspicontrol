#include <utilFuncs.hpp>

std::string utilFuncs::getDateTimeLocal()
{
    std::time_t now = std::time(nullptr);
    std::tm *local_time = std::localtime(&now);
    std::string asc = std::asctime(local_time);
    asc.erase(std::remove_if(asc.begin(), asc.end(), [](char ch)
                                                     { 
                                                        return std::iscntrl(static_cast<unsigned char>(ch)); 
                                                     }),
             asc.end()
             );

    return asc + " ";
}

std::string utilFuncs::encrypt(const std::string &input, const std::vector<uint8_t> &key, const std::vector<uint8_t> &iv)
{
    std::string cipher;

    auto aes = CryptoPP::AES::Encryption(key.data(), key.size());
    auto aes_cbc = CryptoPP::CBC_Mode_ExternalCipher::Encryption(aes, iv.data());

    CryptoPP::StringSource ss(
        input,
        true,
        new CryptoPP::StreamTransformationFilter(
            aes_cbc,
            new CryptoPP::Base64Encoder(
                new CryptoPP::StringSink(cipher))));

    return cipher;
}

std::string utilFuncs::decrypt(const std::string &cipher_text, const std::vector<uint8_t> &key, const std::vector<uint8_t> &iv)
{
    std::string plain_text;

    auto aes = CryptoPP::AES::Decryption(key.data(), key.size());
    auto aes_cbc = CryptoPP::CBC_Mode_ExternalCipher::Decryption(aes, iv.data());

    CryptoPP::StringSource ss(
        cipher_text,
        true,
        new CryptoPP::Base64Decoder(
            new CryptoPP::StreamTransformationFilter(
                aes_cbc,
                new CryptoPP::StringSink(plain_text))));

    return plain_text;
}

