//
// Created by Kyle Gendreau on 7/17/21.
//

#ifndef TF_IDF_IR_TFIDF_H
#define TF_IDF_IR_TFIDF_H

#include "Biblio.h"

class IR_TFIDF {
public:

    using Cont = std::list;

    // def ctor
    explicit IR_TFIDF();

    // copy ctor
    explicit IR_TFIDF(const IR_TFIDF& rhs);

    // dtor
    ~IR_TFIDF();

    // assignment op
    IR_TFIDF& operator=(const IR_TFIDF& rhs);
    IR_TFIDF& operator=(const IR_TFIDF&& rhs);

//////////////////////////////////////////////////////
//// CAPACITY

    bool empty() const noexcept;

    uint32_t sizeDocuments() const noexcept;

    uint32_t sizeTerms() const noexcept;


//////////////////////////////////////////////////////
//// MODIFIERS

    void clear() noexcept;

    void insertDocument(std::string path); // document path

    void eraseDocument(std::string path); // document path

    void eraseTerm(std::string path); // document path

    void swap(IR_TFIDF& rhs);

//////////////////////////////////////////////////////
//// LOOKUPS

    bool contains(std::string path); // document path

    // todo an ordered container of sources along with their calculated values given the term
    Cont<std::pair<Source&,doub find(std::string term);

    // todo an ordered container of sources along with their calculated values given the query
    ... query(std::string query);

//////////////////////////////////////////////////////
//// ITERATORS

    iterator begin();

    iterator end();

private:

//////////////////////////////////////////////////////
//// VARIABLES

    Biblio bib_; // holds sources and respective data

    RadixTrie<Cont> inverseIndex_; // maps terms to documents


//////////////////////////////////////////////////////
//// METHODS

    Analyzer AnalyzerFactoryMethod(std::string path);

    void mergeTrie(RadixTrie<Citation>& trie);

};

#endif //TF_IDF_IR_TFIDF_H
