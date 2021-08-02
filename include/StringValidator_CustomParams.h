//
// Created by Kyle Gendreau on 7/26/21.
//

#ifndef INFORETRIEVAL_TFIDF_STRINGVALIDATOR_CUSTOMPARAMS_H
#define INFORETRIEVAL_TFIDF_STRINGVALIDATOR_CUSTOMPARAMS_H

#include <string>

struct Cust_CharValidator {
    void operator()(char32_t& c) {
        // check if uppercase letter
        if (c - 'A' < 26 && c - 'A' > -1) {
            return;
        }
        // check if lowercase letter
        else if (c - 'a' < 26 && c - 'a' > -1) {
            c = char32_t('A' + (c - 'a')); // make uppercase
            return;
        }
        // check for special symbols
        else if (c == ' ') {
            return; // dont worry about spaces
        }
        // replace non-accepted chars
        else {
            c = '*'; // will be searched for and replaced with empty string
            return;
        }
    }
};

struct Cust_StrValidator {
    void operator()(std::string& s) {

        // get rid of replacements for non-accepted chars
        replaceAll(s,"*","");

        // todo get rid of ignorable postfixes

        // todo get rid of ignorable words
    }

    void replaceAll(std::string &og, const std::string replacee, const std::string replacer) {
        int32_t index(og.find(replacee));
        if (index != -1) {
            og.replace(og.find(replacee),replacee.size(),replacer);
            replaceAll(og,replacee,replacer);
        }
    }
};

#endif //INFORETRIEVAL_TFIDF_STRINGVALIDATOR_CUSTOMPARAMS_H
