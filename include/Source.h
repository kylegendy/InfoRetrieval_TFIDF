//
// Created by Kyle Gendreau on 7/17/21.
//

#ifndef INFORETRIEVAL_TFIDF_SOURCE_H
#define INFORETRIEVAL_TFIDF_SOURCE_H

#include <optional>
#include <time.h>
#include <string>

class Source {
public:

    // def ctor
    explicit Source(std::string filePath, std::string title = "", std::string author = "", std::tm date = std::tm(), uint32_t termCnt = 0, uint32_t uniqueTermCnt = 0);

    // copy ctor
    explicit Source(const Source& rhs);

    // dtor
    ~Source() = default;

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
    uint32_t termCnt_;

    // the total number of unique terms
    uint32_t uniqueTermCnt_;

    // the title of the doc
    std::optional<std::string> title_;

    // author name
    std::optional<std::string> author_;

    // date written
    std::optional<std::tm> date_;

};

#endif //INFORETRIEVAL_TFIDF_SOURCE_H
