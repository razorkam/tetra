//
// Created by uroboros on 07.09.17.
//

#include "Translator.h"
#include <boost/python.hpp>

std::string Translator::get_text() {
    return translated_text;
}


void Translator::set_text(std::string text) {
    source_text = text;
}







BOOST_PYTHON_MODULE(tetra_translator)
{



}



