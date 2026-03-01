#ifndef RASPH_CONFIG_H
#define RASPH_CONFIG_H

#define PROJECT_DESCRIPTION "Raspberrypi GPIO control"
#define PROJECT_NAME "raspicontrol"
#define PROJECT_VERSION "1.5.5"
#define BRIAN_CUSTOM "Custom variable test"

#include <string>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <atomic>
#include <random>
#include <source_location>
#include <thread>
#include <map>

// #include <cryptopp/cryptlib.h>
// #include <cryptopp/hex.h>
// #include <cryptopp/secblock.h>
// #include <cryptopp/modes.h>
// #include <cryptopp/aes.h>
// #include <cryptopp/modes.h>
// #include <cryptopp/osrng.h>
// #include <cryptopp/base64.h>

using namespace std::literals;
using namespace std;

#if defined(__linux__) || defined(__FreeBSD__)
#define ENDLINE "\n"
#elif defined(_WIN64) || defined(_M_ALPHA) || defined(_WIN32)
#define ENDLINE "\r\n"
#else
#define ENDLINE "\n"
#endif

namespace rasp
{
    const std::string CHIP_NAME = "gpiochip0";

    const std::string GPIO23 = "GPIO23";
    const std::string GPIO24 = "GPIO24";

    const int PIN23 = 23;
    const int PIN24 = 24;

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
            std::cout << "\033[1;32m" << dateTimeLocal() << message << " [" << location.function_name() << "] " << "[" << location.file_name() << "] " << "(Line : " << location.line() << ") " << "\033[0m" << ENDLINE;
        }

        static void logWarning(const std::string &message, const std::source_location &location)
        {
            std::cout << "\033[1;33m" << dateTimeLocal() << message << " [" << location.function_name() << "] " << "[" << location.file_name() << "] " << "(Line : " << location.line() << ") " << "\033[0m" << ENDLINE;
        }

        static void logError(const std::string &message, const std::source_location &location)
        {
            std::cout << "\033[1;31m" << dateTimeLocal() << message << " [" << location.function_name() << "] " << "[" << location.file_name() << "] " << "(Line : " << location.line() << ") " << "\033[0m" << ENDLINE;
        }

    public:
        static std::string dateTimeLocal()
        {
            std::time_t now = std::time(nullptr);
            std::tm *local_time = std::localtime(&now);
            std::string asc = std::asctime(local_time);
            asc.erase(std::remove_if(asc.begin(), asc.end(), [](char ch)
                                     { return std::iscntrl(static_cast<unsigned char>(ch)); }),
                      asc.end());

            return asc + " ";
        }

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

        static void printInfo(const std::string &message, const std::source_location &location = std::source_location::current())
        {
            std::cout << "\033[1;32m" << dateTimeLocal() << message << "\033[0m" << ENDLINE;
        }
    };

    // class utils
    // {

    
    //     // static std::string encrypt(const std::string &input, const std::vector<uint8_t> &key, const std::vector<uint8_t> &iv)
    //     // {
    //     //     std::string cipher;

    //     //     auto aes = CryptoPP::AES::Encryption(key.data(), key.size());
    //     //     auto aes_cbc = CryptoPP::CBC_Mode_ExternalCipher::Encryption(aes, iv.data());

    //     //     CryptoPP::StringSource ss(
    //     //         input,
    //     //         true,
    //     //         new CryptoPP::StreamTransformationFilter(
    //     //             aes_cbc,
    //     //             new CryptoPP::Base64Encoder(
    //     //                 new CryptoPP::StringSink(cipher))));

    //     //     return cipher;
    //     // }

    //     // static std::string decrypt(const std::string &cipher_text, const std::vector<uint8_t> &key, const std::vector<uint8_t> &iv)
    //     // {
    //     //     std::string plain_text;

    //     //     auto aes = CryptoPP::AES::Decryption(key.data(), key.size());
    //     //     auto aes_cbc = CryptoPP::CBC_Mode_ExternalCipher::Decryption(aes, iv.data());

    //     //     CryptoPP::StringSource ss(
    //     //         cipher_text,
    //     //         true,
    //     //         new CryptoPP::Base64Decoder(
    //     //             new CryptoPP::StreamTransformationFilter(
    //     //                 aes_cbc,
    //     //                 new CryptoPP::StringSink(plain_text))));

    //     //     return plain_text;
    //     // }
    // };
}

using namespace rasp;

#include <gpioObject.hpp>
#include <gpioController.hpp>

// #include <boost/json/src.hpp>
//  #include <boost/json.hpp>

// #include <string>
// #include <iostream>
// #include <chrono>
// #include <source_location>
//  #include <thread>
//  #include <cstdlib>
//  #include <filesystem>
//  #include <iomanip>
//  #include <random>
//  #include <stdlib.h>
//  #include <stdio.h>
//  #include <uuid/uuid.h>
//  #include <cstring>
//  #include <mutex>
//  #include <ostream>
//  #include <unistd.h> // For sleep
//  #include <condition_variable>
//  #include <syncstream>
//  #include <future>
//  #include <exception>
//  #include <system_error> // for std::error_code
//  #include <cstdio>       // for std::printf
//  #include <cassert>
//  #include <algorithm>
//  #include <fstream>
//  #include <future>
//  #include <complex>
//  #include <cmath>
//  #include <iomanip>
// #include <fmt/core.h>

// #include <Poco/Crypto/CipherFactory.h>
//  #include "Poco/Delegate.h"
//  #include "Poco/Exception.h"
//  #include "Poco/StreamCopier.h"
//  #include "Poco/Timestamp.h"
//  #include "Poco/DateTimeFormatter.h"
//  #include "Poco/DateTimeFormat.h"
//  #include "Poco/Data/RecordSet.h"
//  #include "Poco/Exception.h"
//  #include "Poco/ThreadPool.h"
//  #include "Poco/URI.h"
//  #include "Poco/URIStreamOpener.h"
//  #include "Poco/NullStream.h"

// #include "Poco/Net/HTTPStreamFactory.h"
// #include "Poco/Net/HTTPSStreamFactory.h"
// #include "Poco/Net/AcceptCertificateHandler.h"
// #include "Poco/Net/HTTPRequest.h"
// #include "Poco/Net/HTTPResponse.h"
// #include "Poco/Net/InvalidCertificateHandler.h"
// #include "Poco/Net/Context.h"
// #include "Poco/Net/SSLManager.h"
// #include "Poco/Net/HTTPServer.h"
// #include "Poco/Net/HTTPRequestHandler.h"
// #include "Poco/Net/HTTPRequestHandlerFactory.h"
// #include "Poco/Net/HTTPServerParams.h"
// #include "Poco/Net/HTTPServerRequest.h"
// #include "Poco/Net/HTTPServerResponse.h"
// #include "Poco/Net/HTTPServerParams.h"
// #include "Poco/Net/ServerSocket.h"
// #include "Poco/Net/HTTPClientSession.h"
// #include "Poco/Net/HTTPSClientSession.h"
// #include "Poco/Net/HTTPCredentials.h"
// #include "Poco/Net/WebSocket.h"

// #include "Poco/Util/ServerApplication.h"
// #include "Poco/Util/Option.h"
// #include "Poco/Util/OptionSet.h"
// #include "Poco/Util/HelpFormatter.h"
// #include "Poco/Util/AbstractConfiguration.h"
// #include "Poco/Util/Application.h"

// #include "Poco/JSON/Object.h"
// #include "Poco/JSON/JSON.h"
// #include "Poco/JSON/Parser.h"

// #include "Poco/Dynamic/Var.h"

// #include "Poco/Data/Session.h"
// #include "Poco/Data/SQLite/Connector.h"
// #include "Poco/Data/SQLite/Notifier.h"
// //#include "Poco/Data/MySQL/Connector.h"
// #include "Poco/Data/PostgreSQL/Connector.h"
// #include "Poco/Net/NetException.h"
// #include "Poco/Util/ServerApplication.h"

// #include <boost/lockfree/queue.hpp>
// #include <boost/exception/all.hpp>
// #include <boost/exception/errinfo_errno.hpp>     // For errno information
// #include <boost/exception/errinfo_file_name.hpp> // For file name information
// #include <boost/algorithm/string.hpp>
// #include <boost/timer/timer.hpp>
// #include <boost/json/src.hpp>
// #include <boost/filesystem.hpp>
// #include <boost/system/error_code.hpp>
// #include <boost/system.hpp>
// #include <boost/asio.hpp>
// #include <boost/version.hpp>

// #include <sqlite3.h>
// #include <gpiod.hpp>
// #include <httplib.h>
// #include <glib.h>
// #include <valgrind/valgrind.h>

// Project project headers
// #include <config.hpp>
// #include <utils.hpp>
// #include <defer.hpp>
// #include <gpioController.hpp>
// #include <mio.hpp>
// #include <file.hpp>

// using Poco::DateTime;
// using Poco::DateTimeFormat;
// using Poco::DateTimeFormatter;
// using Poco::DateTimeParser;

// using Poco::LocalDateTime;
// using Poco::Timespan;

// using Poco::delegate;
// using Poco::Exception;
// using Poco::NullPointerException;

// using namespace Poco::Net;
// using Poco::Net::HTTPRequestHandler;
// using Poco::Net::HTTPRequestHandlerFactory;
// using Poco::Net::HTTPResponse;
// using Poco::Net::HTTPServer;
// using Poco::Net::HTTPServerParams;
// using Poco::Net::HTTPServerRequest;
// using Poco::Net::HTTPServerResponse;
// using Poco::Net::ServerSocket;
// using Poco::Net::WebSocket;
// using Poco::Net::WebSocketException;

// using namespace Poco::Data::Keywords;
// using Poco::Data::RecordSet;
// using Poco::Data::RowFormatter;
// using Poco::Data::Session;
// using Poco::Data::Statement;
// using Poco::Data::SQLite::Notifier;

// using namespace std::literals;
// using namespace std;

// using namespace RaspberryPiDefines;

#endif
