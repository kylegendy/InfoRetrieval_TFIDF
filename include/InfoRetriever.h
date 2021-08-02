//
// Created by Kyle Gendreau on 7/17/21.
//

#ifndef INFORETRIEVAL_TFIDF_InfoRetriever_H
#define INFORETRIEVAL_TFIDF_InfoRetriever_H

#include "Biblio.h"
#include "Analyzer_txt.h"

class InfoRetriever {
public:

    using Cont = std::list<Citation>;

    // def ctor
    explicit InfoRetriever();

    // copy ctor
    explicit InfoRetriever(const InfoRetriever& rhs);

    // dtor
    ~InfoRetriever() = default;

    // assignment op
    InfoRetriever& operator=(const InfoRetriever& rhs);
    InfoRetriever& operator=(const InfoRetriever&& rhs);

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

    void swap(InfoRetriever& rhs);

//////////////////////////////////////////////////////
//// LOOKUPS

    bool contains(std::string path); // document path

    // get a an ordered container of sources along with their values
    Cont find(std::string term);

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

#endif //INFORETRIEVAL_TFIDF_InfoRetriever_H
