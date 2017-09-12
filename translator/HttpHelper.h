//
// Created by uroboros on 08.09.17.
//

#ifndef TETRA_HTTPHELPER_H
#define TETRA_HTTPHELPER_H

#include <boost/asio.hpp>
#include <string>

using namespace boost::asio;
using std::string;



class HttpHelper {
public:
    HttpHelper & HttpHelper();
    ~HttpHelper();

    streambuf sync_query(const string &host, const string& relative_url);


private:
    io_service _io_service;
    ip::tcp::socket socket;
    ip::tcp::resolver resolver;
    streambuf request;
    streambuf response;
    static const string default_lb_delim;
    static const string header_end_delim;
    static const string HTTP_version;
    std::exception last_exception;
};


#endif //TETRA_HTTPHELPER_H
