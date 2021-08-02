//
// Created by Kyle Gendreau on 8/1/21.
//

#ifndef INFORETRIEVAL_TFIDF_InfoRetriever_CPP
#define INFORETRIEVAL_TFIDF_InfoRetriever_CPP

#include "../include/InfoRetriever.h"

InfoRetriever::InfoRetriever() : bib_(), inverseIndex_() {
}

InfoRetriever::InfoRetriever(const InfoRetriever &rhs) : bib_(rhs.bib_), inverseIndex_(rhs.inverseIndex_) {
}

InfoRetriever &InfoRetriever::operator=(const InfoRetriever &rhs) {
    if (this != &rhs) {
        InfoRetriever ph(rhs);
        this->swap(ph);
    }
    return *this;
}

InfoRetriever &InfoRetriever::operator=(const InfoRetriever &&rhs) {
    return *this = rhs;
}

bool InfoRetriever::empty() const noexcept {
    return bib_.empty();
}

uint32_t InfoRetriever::sizeDocuments() const noexcept {
    return bib_.size();
}

uint32_t InfoRetriever::sizeTerms() const noexcept {
    return inverseIndex_.size();
}

void InfoRetriever::clear() noexcept {
    bib_.clear();
    inverseIndex_.clear();
}

void InfoRetriever::insertDocument(std::string path) {

    // create a new analyzer via factory method design pattern
    std::unique_ptr<Analyzer> analPtr(AnalyzerFactoryMethod(path));

    // make exception safe
    InfoRetriever ph(*this);
    ph.bib_.insert(analPtr->getSource());
    ph.mergeTrie(analPtr->getTrie());

    // finish it off with a swap
    this->swap(ph);
}


void InfoRetriever::swap(InfoRetriever &rhs) {
    if (this != &rhs) {
        bib_.swap(rhs.bib_);
        inverseIndex_.swap(rhs.inverseIndex_);
    }
}

bool InfoRetriever::contains(std::string path) {
    if (!empty()) {
        Source srcPh(path);
        return bib_.contains(srcPh);
    }
    return false;
}

Cont <Citation> InfoRetriever::find(std::string term) {
    return inverseIndex_.find(term)->second;
}
