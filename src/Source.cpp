//
// Created by Kyle Gendreau on 7/26/21.
//

#ifndef INFORETRIEVAL_TFIDF_SOURCE_CPP
#define INFORETRIEVAL_TFIDF_SOURCE_CPP

#include "../include/Source.h"
#include <optional>

Source::Source(std::string filePath, uint32_t termCnt, uint32_t uniqueTermCnt, std::string title, std::string author,
               std::tm date) : path_(filePath), termCnt_(termCnt), uniqueTermCnt_(uniqueTermCnt) {

    title_ = (title.empty()) ? std::nullopt : title;
    author_ = (author.empty()) ? std::nullopt : author;
    date_ = (date == std::tm()) ? std::nullopt : date;

}

Source::Source(const Source &rhs) : path_(rhs.path_), termCnt_(rhs.termCnt_), uniqueTermCnt_(rhs.uniqueTermCnt_), title_(rhs.title_), author_(rhs.author_), date_(rhs.date_){
}

Source &Source::operator=(const Source &rhs) {
    if (this != &rhs) {
        Source ph(rhs);
        std::swap(this,&ph);
    }
    return *this;
}

Source &Source::operator=(const Source &&rhs) {
    return *this = rhs;
}

bool Source::operator==(const Source &rhs) const {
    return (this == &rhs) ? true : path_ == rhs.path_; //todo idk about this method of equivalence
}

bool Source::operator==(const Source &&rhs) const {
    return *this == rhs;
}

bool Source::operator!=(const Source &rhs) const {
    return !(*this == rhs);
}

bool Source::operator!=(const Source &&rhs) const {
    return *this != rhs;
}

#endif //INFORETRIEVAL_TFIDF_SOURCE_CPP