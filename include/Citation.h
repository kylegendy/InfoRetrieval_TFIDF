//
// Created by Kyle Gendreau on 7/25/21.
//

#ifndef TF_IDF_CITATION_H
#define TF_IDF_CITATION_H

#include "Source.h"

class Citation {
public:

    // def ctor
    Citation(Source* source = nullptr, uint32_t frequency = 0);

    // dtor
    ~Citation() = default;

    Source& getSource(); // returns address of source

    uint32_t getFrequency(); // returns the frequency of word in source

private:

    Source* src;

    uint32_t frequency;

};

#endif //TF_IDF_CITATION_H
