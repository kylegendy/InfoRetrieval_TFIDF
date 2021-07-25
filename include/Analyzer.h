//
// Created by Kyle Gendreau on 7/24/21.
//

#ifndef TF_IDF_ANALYZER_H
#define TF_IDF_ANALYZER_H

#include "Citation.h"

// abstract base class
class Analyzer {
public:

    // def ctor
    Analyzer() = default;

    // dtor
    virtual ~Analyzer() = default;

    // stores the src info
    Source src;

    // stores the inverse index specific for the document
    RadixTrie<Citation> trie;

};

#endif //TF_IDF_ANALYZER_H
