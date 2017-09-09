//
// Created by uroboros on 08.09.17.
//

#ifndef TETRA_HTTPHELPER_H
#define TETRA_HTTPHELPER_H

#include <boost/asio.hpp>
#include <string>

using namespace boost::asio;
using std::string;

typedef void(*http_helper_data_received)();
typedef void(*http_helper_request_completed)();

class HttpHelper {
public:
    HttpHelper(const string& Host, const string& Relative_url,
               http_helper_data_received ReceivedCallback,
               http_helper_request_completed CompletedCallback,
                io_service& IOService);
    ~HttpHelper();
    void send_request();


private:
    string host;
    string relative_url;
    http_helper_data_received received_callback;
    http_helper_request_completed completed_callback;
    io_service &_io_service;
    ip::tcp::socket socket;
    ip::tcp::resolver resolver;

    streambuf request;
    streambuf response;



};


#endif //TETRA_HTTPHELPER_H
