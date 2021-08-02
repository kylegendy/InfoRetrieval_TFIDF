//
// Created by Kyle Gendreau on 7/25/21.
//

#ifndef INFORETRIEVAL_TFIDF_CITATION_H
#define INFORETRIEVAL_TFIDF_CITATION_H

#include "Source.h"

class Citation {
public:

    // def ctor
    Citation(Source* source = nullptr, uint32_t frequency = 0);

    // alt ctor
    Citation(Source source, uint32_t frequency = 0);

    // dtor
    ~Citation() = default;

    Source& getSource(); // returns address of source

    uint32_t getFrequency(); // returns the frequency of word in source

    void incFreq(double inc);

private:

    Source* src_;

    uint32_t freq_;

};

#endif //INFORETRIEVAL_TFIDF_CITATION_H
