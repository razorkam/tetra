//
// Created by uroboros on 07.09.17.
//

#include "GoogleUdApiWrapper.h"
#include "../HttpHelper.h"

const std::string GoogleUdApiWrapper::HOST = "translate.googleapis.com";
const std::string GoogleUdApiWrapper::RELATIVE_URL = "/translate_a/single?client=gtx&sl=auto&tl=ru&dt=t&q=";


GoogleUdApiWrapper::GoogleUdApiWrapper() : Translator() {
}

void GoogleUdApiWrapper::translate() {
    translated_text = http_helper->http_GET_request(HOST, RELATIVE_URL + source_text);
}

GoogleUdApiWrapper::~GoogleUdApiWrapper() {

}
