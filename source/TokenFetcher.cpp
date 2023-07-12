#include "TokenFetcher.h"
#include <Poco/SAX/InputSource.h>
#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/NodeIterator.h>
#include <Poco/DOM/NodeFilter.h>
#include <Poco/DOM/Document.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPMessage.h>
#include <Poco/URI.h>
#include <Poco/AutoPtr.h>
#include <Poco/Exception.h>
#include <iostream>
#include <string>


TokenFetcher::TokenFetcher(Poco::Net::HTTPClientSession& session, const std::string& server) :
    _session(session)
{
    _tokenURI = Poco::URI("http", server, "/api/webserver/token");
}

void TokenFetcher::fetchToken()
{
    try
    {
        Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, _tokenURI.getPathAndQuery(), Poco::Net::HTTPMessage::HTTP_1_1);
        Poco::Net::HTTPResponse response;

        _session.sendRequest(request);

        Poco::XML::InputSource input(_session.receiveResponse(response));
        Poco::XML::DOMParser parser;
        Poco::AutoPtr<Poco::XML::Document> pDoc = parser.parse(&input);
        Poco::XML::NodeIterator iter(pDoc, Poco::XML::NodeFilter::SHOW_TEXT);

        _token = iter.nextNode()->getNodeValue();
    }
    catch (Poco::Exception&)
    {
        throw;
    }
}
