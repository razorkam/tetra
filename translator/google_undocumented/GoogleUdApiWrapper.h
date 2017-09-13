//
// Created by uroboros on 07.09.17.
//

#ifndef TETRA_GOOGLEUDAPIWRAPPER_H
#define TETRA_GOOGLEUDAPIWRAPPER_H

#include "../Translator.h"


class GoogleUdApiWrapper : public Translator {
public:
    virtual void translate();
    GoogleUdApiWrapper();
private:
    static const std::string HOST;
    static const std::string RELATIVE_URL;
};


#endif //TETRA_GOOGLEUDAPIWRAPPER_H
