//
// Created by uroboros on 08.09.17.
//

#include "HttpHelper.h"

const string HttpHelper::default_delim = "\r\n"; //HTTP specification
const string HttpHelper::end_delim = "\r\n\r\n"; //HTTP specification



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


HttpHelper::~HttpHelper() = default;

void HttpHelper::send_request() {
    ip::tcp::resolver::query query(host, "http");
    resolver.async_resolve(query, [this](const boost::system::error_code& ec_r,
                                         ip::tcp::resolver::iterator ep_iter)
    {
        async_connect(socket, ep_iter, [this](const boost::system::error_code& ec_c,
                                              ip::tcp::resolver::iterator iter_c)
        {
            if (!ec_c)
            {
                std::ostream rq_stream(&request);
                rq_stream << "GET " << relative_url << "HTTP /1.1" << default_delim;
                rq_stream << "Host: " << host << default_delim;
                rq_stream << "Accept:  */*" << default_delim;
                rq_stream << "Connection: close" << default_delim;
                rq_stream << default_delim; // HTTP rq header end
                async_write(socket, request, [this](const boost::system::error_code& ec_w,
                                                    std::size_t bytes_transferred)
                {
                    async_read_until(socket, response, end_delim,
                    [this](const boost::system::error_code& ec_ru, std::size_t bytes_readed)
                    {
                        //read_data();
                    });
                });

            }
        });
    });
}

