//
// Created by Kyle Gendreau on 7/24/21.
//

#ifndef INFORETRIEVAL_TFIDF_ANALYZER_H
#define INFORETRIEVAL_TFIDF_ANALYZER_H

#include "Citation.h"

// abstract base class
class Analyzer {
public:

    // def ctor
    explicit Analyzer() = default;

    // dtor
    virtual ~Analyzer() = default;

    // return the source object
    virtual Source& getSource() = 0;

    // return the trie object
    virtual RadixTrie<Citation>& getTrie() = 0;

};

#endif //INFORETRIEVAL_TFIDF_ANALYZER_H
