//
// Created by Kyle Gendreau on 7/26/21.
//

#ifndef INFORETRIEVAL_TFIDF_CITATION_CPP
#define INFORETRIEVAL_TFIDF_CITATION_CPP

#include "../include/Citation.h"

Citation::Citation(Source *source, uint32_t frequency) : src_(source), freq_(frequency) {
}

Citation::Citation(Source source, uint32_t frequency) : src_(&source), freq_(frequency) {
}

Source &Citation::getSource() {
    return *src_;
}

uint32_t Citation::getFrequency() {
    return freq_;
}

void Citation::incFreq(double inc) {
    freq_ += inc;
}

#endif //INFORETRIEVAL_TFIDF_CITATION_CPP