//
// Created by Kyle Gendreau on 7/25/21.
//

#ifndef TF_IDF_ANALYZER_TXT_H
#define TF_IDF_ANALYZER_TXT_H

#include "Analyzer.h"

class Analyzer_txt : public Analyzer {
public:

    // def ctor
    Analyzer_txt(std::string path);

    // dtor
    ~Analyzer_txt() override = default;

    // src

    // trie
};

#endif //TF_IDF_ANALYZER_TXT_H
