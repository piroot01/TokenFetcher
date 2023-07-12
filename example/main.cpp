#include "TokenFetcher.h"
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Exception.h>
#include <string>
#include <iostream>

int main()
{
    std::string server = "192.168.100.250";
    Poco::Net::HTTPClientSession session(server);

    TokenFetcher fetcher(session, server);

    try
    {
        fetcher.fetchToken();
    }
    catch (Poco::Exception& e)
    {
        std::cerr << e.displayText() << std::endl;
    }

    std::cout << fetcher.getToken() << '\n';

    return 0;
}
