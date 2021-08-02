//
// Created by Kyle Gendreau on 7/17/21.
//

#ifndef INFORETRIEVAL_TFIDF_BIBLIO_H
#define INFORETRIEVAL_TFIDF_BIBLIO_H

#include "Source.h"

class Biblio {
public:

    using T = std::list<Source>

    // default ctor
    explicit Biblio();

    // alt ctor
    explicit Biblio(const Biblio& rhs);

    // dtor
    ~Biblio() = default;

    // assignment op
    Biblio &operator=(const Biblio& rhs);
    Biblio &operator=(const Biblio&& rhs);

//////////////////////////////////////////////////////
//// CAPACITY

    bool empty() const noexcept;

    uint32_t size() const noexcept;

//////////////////////////////////////////////////////
//// MODIFIERS

    void clear() noexcept;

    void insert(Source& src);
    void insert(Source&& src);

    void erase(Source& src);
    void erase(Source&& src);

    void swap(Biblio& rhs);

    void merge(Biblio& rhs);

//////////////////////////////////////////////////////
//// LOOKUPS

    bool contains(Source& src) const;
    bool contains(Source&& src) const;

    T::iterator find(Source& src);
    T::iterator find(Source&& src);

//////////////////////////////////////////////////////
//// ITERATORS

    T::iterator begin();

    T::iterator end();

private:

//////////////////////////////////////////////////////
//// VARIABLES

    T cont_;
};

#endif //INFORETRIEVAL_TFIDF_BIBLIO_H
