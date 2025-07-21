#include <main.hpp>
#include <random>
#include <stdlib.h>
#include <stdio.h>
#include <uuid/uuid.h>
#include <cstring>
#include <mutex>

#include <Poco/Crypto/CipherFactory.h>

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

#include <sqlite3.h>
#include <defer.hpp>
#include <utilFuncs.hpp>
#include <gpioController.hpp>
#include <boost/lockfree/queue.hpp>
#include <ostream>



using namespace std::literals;

using namespace Poco;
using namespace Poco::Net;
using namespace std;
using namespace Poco::JSON;

using Poco::DateTime;
using Poco::DateTimeFormat;
using Poco::DateTimeFormatter;
using Poco::DateTimeParser;
using Poco::LocalDateTime;



#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace sql::mysql;

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    try
    {
       
        std::cout << "Program Started: " << utilFuncs::getDateTimeLocal() << std::endl;
        std::cout << "Build Date: " << __DATE__ << std::endl;
        std::cout << "Build Time: " << __TIME__ << std::endl;
        
        // gpioController gpioCtl;
        // auto gpios = gpioCtl.getGpioObjects();
        // gpios["gpio23"]->setGpioValue(1);
        // gpios["gpio24"]->setGpioValue(1);
        // std::this_thread::sleep_for(1000ms);
        // gpios["gpio23"]->setGpioValue(0);
        // gpios["gpio24"]->setGpioValue(0);

    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << " " << utilFuncs::getDateTimeLocal() << std::endl;
        goto programStop;
    }

programStop:   
    std::cout << "Program Stopped: " << utilFuncs::getDateTimeLocal() << std::endl;
    return 0;


}