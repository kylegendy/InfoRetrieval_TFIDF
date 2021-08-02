//
// Created by Kyle Gendreau on 7/25/21.
//

#ifndef INFORETRIEVAL_TFIDF_ANALYZER_TXT_H
#define INFORETRIEVAL_TFIDF_ANALYZER_TXT_H

#include <fstream>
#include "Analyzer.h"
#include "Citation.h"
#include "StringValidator_CustomParams.h"
#include "../module/StringValidator/include/StringValidator.h"
#include "../module/DeAccenter/include/DeAccenter.h"
#include "../module/RadixTrie/include/RadixTrie.h"

class Analyzer_txt : public Analyzer {
public:

    // def ctor
    explicit Analyzer_txt(std::string path, std::string title = "", std::string author = "", std::tm date = std::tm());

    // dtor
    ~Analyzer_txt() override = default;

    virtual Source& getSource() override;

    virtual RadixTrie<Citation>& getTrie() override;

private:

//////////////////////////////////////////////////////
//// VARIABLES

    // stores the src info
    Source src_;

    // class to remove all diacritics
    DeAccenter translator_;

    // class to ensure normalization
    StringValidator<Cust_CharValidator,Cust_StrValidator> strValidator_;

    // stores the inverse index specific for the document
    RadixTrie<Citation> trie_;

//////////////////////////////////////////////////////
//// FUNCTIONS

    std::string validate(std::string s) const;

    static void processFile(Source &source, RadixTrie<Citation> &trie);

    static void openFile(std::ifstream &infile, const std::string &fileName);

};

#endif //INFORETRIEVAL_TFIDF_ANALYZER_TXT_H
