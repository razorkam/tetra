//
// Created by uroboros on 07.09.17.
//

#include "Translator.h"
#include <boost/python.hpp>
#include "HttpHelper.h"
#include "google_undocumented/GoogleUdApiWrapper.h"

std::string Translator::get_text() {
    return translated_text;
}


void Translator::set_text(const std::string& text) {
    source_text = text;
}

Translator::Translator() {
    http_helper = new HttpHelper();
}

Translator::~Translator() {
    delete http_helper;
}


class TranslatorWrap : public Translator, public boost::python::wrapper<Translator>
{
    virtual void translate() {
        get_override("translate")();
    }

};


BOOST_PYTHON_MODULE(tetra_translator)
{
    using namespace boost::python;
    class_<TranslatorWrap, boost::noncopyable>("Translator")
            .def("translate", pure_virtual(&Translator::translate))
            .def("set_text", &Translator::set_text)
            .def("get_text", &Translator::get_text);

    class_<GoogleUdApiWrapper, bases<Translator> >("GoogleTranslator");
}



