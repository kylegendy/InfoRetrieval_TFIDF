//
// Created by Kyle Gendreau on 7/26/21.
//

#ifndef INFORETRIEVAL_TFIDF_BIBLIO_CPP
#define INFORETRIEVAL_TFIDF_BIBLIO_CPP

#include "../include/Biblio.h"

Biblio::Biblio() : cont_() {
}

Biblio::Biblio(const Biblio &rhs) : cont_(rhs.cont_) {
}

Biblio &Biblio::operator=(const Biblio &rhs) {
    if (this != &rhs) {
        Biblio ph(rhs);
        std::swap(this,&rhs);
    }
    return *this;
}

Biblio &Biblio::operator=(const Biblio &&rhs) {
    return *this = rhs;
}

bool Biblio::empty() const noexcept {
    return cont_.empty();
}

uint32_t Biblio::size() const noexcept {
    return cont_.size();
}

void Biblio::clear() noexcept {
    cont_ = T();
}

void Biblio::insert(Source &src) {
    cont_.insert(doc);
}

void Biblio::insert(Source &&src) {
    insert(doc);
}

void Biblio::erase(Source &src) {
    cont_.erase(src);
}

void Biblio::erase(Source &&src) {
    erase(src);
}

void Biblio::swap(Biblio &rhs) {
    if (this != &rhs) {
        std::swap(&cont_,&rhs.cont_);
    }
    return *this;
}

void Biblio::merge(Biblio &rhs) {
    if (this != &rhs) {
        for (auto it(rhs.begin()); it != rhs.end(); ++it) {
            insert(*it);
        }
        rhs.clear();
    }
}

bool Biblio::contains(Source &src) const {
    return find(src) == end();
}

bool Biblio::contains(Source &&src) const {
    return contains(src);
}

T::iterator Biblio::find(Source &doc) {
    for (auto it(begin()); it != end(); ++it) {
        if (*it == src)
            return it;
    }
    return end();
}

T::iterator Biblio::find(Source &&src) {
    return find(src);
}

T::iterator Biblio::begin() {
    return cont_.begin();
}

T::iterator Biblio::end() {
    return cont_.end();
}

#endif //INFORETRIEVAL_TFIDF_BIBLIO_CPP