#ifndef Token_Fetcher_INCLUDED
#define Token_Fetcher_INCLUDED


#include <Poco/Net/HTTPClientSession.h>
#include <Poco/URI.h>
#include <string>


#define Token_Fetcher_SERVICE


class Token_Fetcher_SERVICE TokenFetcher
{
public:
    TokenFetcher(Poco::Net::HTTPClientSession& session, const std::string& server);

    void fetchToken();

    std::string getToken() const;

private:
    Poco::Net::HTTPClientSession& _session;
    Poco::URI _tokenURI;
    std::string _token;

};


inline std::string TokenFetcher::getToken() const 
{
    return _token;
}


#endif
