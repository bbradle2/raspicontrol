#pragma once

#include <string>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <filesystem>
#include <iomanip>
#include <random>
#include <stdlib.h>
#include <stdio.h>
#include <uuid/uuid.h>
#include <cstring>
#include <mutex>
#include <ostream>
#include <unistd.h> // For sleep
#include <condition_variable>
#include <syncstream>
#include <future>
#include <exception>
#include <system_error> // for std::error_code
#include <cstdio>       // for std::printf
#include <cassert>
#include <algorithm>
#include <fstream>
#include <future>
#include <httplib.h>

#include <glib.h>

//#include <Poco/Crypto/CipherFactory.h>

#include "Poco/Exception.h"
#include "Poco/StreamCopier.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Exception.h"
#include "Poco/ThreadPool.h"
#include "Poco/URI.h"
#include "Poco/URIStreamOpener.h"
#include "Poco/NullStream.h"

#include "Poco/Net/HTTPStreamFactory.h"
#include "Poco/Net/HTTPSStreamFactory.h"
#include "Poco/Net/AcceptCertificateHandler.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/InvalidCertificateHandler.h"
#include "Poco/Net/Context.h"
#include "Poco/Net/SSLManager.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPSClientSession.h"
#include "Poco/Net/HTTPCredentials.h"
#include "Poco/Net/WebSocket.h"

#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/Util/Application.h"

#include "Poco/JSON/Object.h"
#include "Poco/JSON/JSON.h"
#include "Poco/JSON/Parser.h"

#include "Poco/Dynamic/Var.h"

#include "Poco/Data/Session.h"
#include "Poco/Data/SQLite/Connector.h"
// #include "Poco/Data/MySQL/Connector.h"
// #include "Poco/Data/PostgreSQL/Connector.h"

#include <boost/lockfree/queue.hpp>
#include <boost/exception/all.hpp>
#include <boost/exception/errinfo_errno.hpp>     // For errno information
#include <boost/exception/errinfo_file_name.hpp> // For file name information
#include <boost/algorithm/string.hpp>

#include <sqlite3.h>
#include <gpiod.hpp>
#include <valgrind/valgrind.h>

//Project project headers
#include <defer.hpp>
#include <utilFuncs.hpp>
#include <gpioController.hpp>
#include <mio.hpp>
#include <raspberryPiDefines.hpp>

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

using namespace std::literals;
using namespace std;

using Poco::DateTime;
using Poco::DateTimeFormat;
using Poco::DateTimeFormatter;
using Poco::DateTimeParser;
using Poco::LocalDateTime;
using namespace RaspberryPiDefines;
