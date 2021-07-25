//
// Created by Kyle Gendreau on 7/17/21.
//

#ifndef TF_IDF_SOURCE_H
#define TF_IDF_SOURCE_H

#include <optional>
#include <time>

class Source {
public:

    // def ctor
    explicit Source();

    // copy ctor
    explicit Source(const Source& rhs);

    // dtor
    ~Source();

    // assignment op
    Source& operator=(const Source& rhs);
    Source& operator=(const Source&& rhs);

    bool operator==(const Source& rhs) const;
    bool operator==(const Source&& rhs) const;

    bool operator!=(const Source& rhs) const;
    bool operator!=(const Source&& rhs) const;

//////////////////////////////////////////////////////
//// VARIABLES

    // absolute path? relative?
    std::string path_;

    // the total number of terms
    uint32_t termSize_;

    // the total number of unique terms
    uint32_t uniqueTermSize_;

    // the title of the doc
    std::optional<std::string> title_;

    // author name
    std::optional<std::string> author_;

    // date written
    std::optional<std::tm> date_;

};

#endif //TF_IDF_SOURCE_H
