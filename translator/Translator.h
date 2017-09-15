//
// Created by uroboros on 07.09.17.
//

#ifndef TETRA_TRANSLATOR_H
#define TETRA_TRANSLATOR_H

#include <string>

class HttpHelper;

class Translator {
public:
    Translator();
    virtual ~Translator();
    std::string get_text();
    virtual void translate() = 0; //pure virtual
    void set_text(const std::string& text);
protected:
        std::string translated_text;
        std::string source_text;
        HttpHelper* http_helper;
};


#endif //TETRA_TRANSLATOR_H
