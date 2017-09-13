//
// Created by uroboros on 08.09.17.
//

#include "HttpHelper.h"

const string HttpHelper::default_lb_delim = "\r\n"; //HTTP specification line break delim
const string HttpHelper::header_end_delim = "\r\n\r\n";
const string HttpHelper::HTTP_version = "1.1";

HttpHelper::HttpHelper():
_io_service(),
socket(_io_service),
resolver(_io_service)
{
  //  boost::asio::io_service::work work(_io_service);
   // std::thread thread([&io_service](){_io_service.run();});
}


HttpHelper::~HttpHelper() = default;

void HttpHelper::sync_query(const string &host, const string& relative_url) {
    try {
        ip::tcp::resolver::query query(host, "http");
        auto ep_iter = resolver.resolve(query);
        connect(socket, ep_iter);
        std::ostream rq_stream(&request);
        rq_stream << "GET " << relative_url << "HTTP/" << HTTP_version << default_lb_delim;
        rq_stream << "Host: " << host << default_lb_delim;
        rq_stream << "Accept:  */*" << default_lb_delim;
        rq_stream << "Connection: close" << default_lb_delim;
        rq_stream << header_end_delim; // HTTP rq header end
        write(socket, request);
        read_until(socket, response, header_end_delim); //read HTTP response header
        boost::system::error_code error;
        while (static_cast<bool>(read(socket, response,
                                      transfer_at_least(1), error))) {
        }

        if (error != boost::asio::error::eof)
            throw boost::system::system_error(error);

    }

    catch (std::exception &e){
        last_exception = e;
    }

    socket.close();
}

string HttpHelper::http_GET_request(const string &host, const string &relative_url) {
    sync_query(host, relative_url);
    auto buf = response.data();
    string result(buffers_begin(buf), buffers_begin(buf) + response.size());
    return result;
}
