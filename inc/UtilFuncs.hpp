#pragma once

#include <string>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <atomic>
#include <random>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/secblock.h>
#include <cryptopp/modes.h>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/base64.h>

class UtilFuncs
{
    // function declarations
    public:
        static std::string getDateTimeLocal();
        static std::string encrypt(const std::string &input, const std::vector<uint8_t> &key, const std::vector<uint8_t> &iv);
        static std::string decrypt(const std::string &cipher_text, const std::vector<uint8_t> &key, const std::vector<uint8_t> &iv);

};