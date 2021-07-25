//
// Created by Kyle Gendreau on 7/17/21.
//

#ifndef TF_IDF_BIBLIO_H
#define TF_IDF_BIBLIO_H

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

    void insert(Source& doc);
    void insert(Source&& doc);

    void erase(Source& doc);
    void erase(Source&& doc);

    void swap(Biblio& rhs);

    void merge(Biblio& rhs);

//////////////////////////////////////////////////////
//// LOOKUPS

    bool contains(Source& doc) const;
    bool contains(Source&& doc) const;

    T::iterator find(Source& doc);
    T::iterator find(Source&& doc);

//////////////////////////////////////////////////////
//// ITERATORS

    T::iterator begin();

    T::iterator end();

private:

//////////////////////////////////////////////////////
//// VARIABLES

    T cont_;
};

#endif //TF_IDF_BIBLIO_H
