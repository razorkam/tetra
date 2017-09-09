//
// Created by uroboros on 08.09.17.
//

#include "HttpHelper.h"



HttpHelper::HttpHelper(const string &Host, const string& Relative_url, http_helper_data_received ReceivedCallback,
                       http_helper_request_completed CompletedCallback, io_service &IOService) :
host(Host),
relative_url(Relative_url),
received_callback(ReceivedCallback),
completed_callback(CompletedCallback),
_io_service(IOService),
socket(IOService),
resolver(IOService) {

}


HttpHelper::~HttpHelper() {

}

void HttpHelper::send_request() {
    ip::tcp::resolver::query query(host, "http");

}

