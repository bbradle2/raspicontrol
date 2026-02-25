#ifndef UTILS_HEADER
#define UTILS_HEADER

#include <string>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <atomic>
#include <random>
#include <source_location>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/secblock.h>
#include <cryptopp/modes.h>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/base64.h>

const std::string CHIP_NAME = "gpiochip0";

const std::string GPIO23 = "GPIO23";
const std::string GPIO24 = "GPIO24";

const int PIN23 = 23;
const int PIN24 = 24;


#if defined(__linux__) || defined(__FreeBSD__)
#define ENDLINE "\n"
#elif defined(_WIN64) || defined(_M_ALPHA) || defined(_WIN32)
#define ENDLINE "\r\n"
#else
#define ENDLINE "\n"
#endif

enum LogType
{
    INFO = 1,
    WARNING = 2,
    ERROR = 3
};

class utils
{

private:
    static void logInfo(const std::string &message, const std::source_location &location)
    {
        std::cout << "\033[1;32m" << message << " [" << location.function_name() << "] " << "[" << location.file_name() << "] " << "(Line : " << location.line() << ") " << "\033[0m" << ENDLINE;
    }

    static void logWarning(const std::string &message, const std::source_location &location)
    {
        std::cout << "\033[1;33m" << message << " [" << location.function_name() << "] " << "[" << location.file_name() << "] " << "(Line : " << location.line() << ") " << "\033[0m" << ENDLINE;
    }

    static void logError(const std::string &message, const std::source_location &location)
    {
        std::cout << "\033[1;31m" << message << " [" << location.function_name() << "] " << "[" << location.file_name() << "] " << "(Line : " << location.line() << ") " << "\033[0m" << ENDLINE;
    }

public:
    static void log(const std::string &message, LogType logType = INFO, const std::source_location &location = std::source_location::current())
    {
        switch (logType)
        {
        case INFO:
            logInfo(message, location);
            break;
        case WARNING:
            logWarning(message, location);
            break;
        case ERROR:
            logError(message, location);
            break;
        default:
            logInfo(message, location);
            break;
        }
    }

    static std::string getDateTimeLocal()
    {
        std::time_t now = std::time(nullptr);
        std::tm *local_time = std::localtime(&now);
        std::string asc = std::asctime(local_time);
        asc.erase(std::remove_if(asc.begin(), asc.end(), [](char ch)
                                { return std::iscntrl(static_cast<unsigned char>(ch)); }),
                asc.end());

        return asc + " ";
    }

    static std::string encrypt(const std::string &input, const std::vector<uint8_t> &key, const std::vector<uint8_t> &iv)
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

    static std::string decrypt(const std::string &cipher_text, const std::vector<uint8_t> &key, const std::vector<uint8_t> &iv)
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
};

#endif