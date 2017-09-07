//
// Created by uroboros on 07.09.17.
//

#ifndef TETRA_TRANSLATOR_H
#define TETRA_TRANSLATOR_H

#include <string>

class Translator {
    public:
        Translator();
        std::string get_text();
        virtual void translate() = 0;
        void set_text(std::string text);
    private:
        std::string translated_text;
        std::string source_text;

};


#endif //TETRA_TRANSLATOR_H
