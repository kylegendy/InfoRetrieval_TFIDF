//
// Created by Kyle Gendreau on 7/26/21.
//

#include "../include/Analyzer_txt.h"

Analyzer_txt::Analyzer_txt(std::string path, std::string title, std::string author, std::tm date) : src_(path, title, author, date), translator_(), strValidator_() {
    processFile(src_,trie_);
}

Source &Analyzer_txt::getSource() {
    return src_;
}

RadixTrie <Citation> &Analyzer_txt::getTrie() {
    return trie_;
}

std::string Analyzer_txt::validate(std::string s) const {
    std::string tok(translator_.removeAllAccents(s));
    tok = strValidator_(tok);
    return tok;
}

void Analyzer_txt::processFile(Source &source, RadixTrie <Citation> &trie) {

    // open file in ifstream
    std::ifstream inputFile;
    openFile(inputFile, source.path_);

    std::string word;

    while (infile >> word) { // for every word

        word = validate(word);

        if (!word.empty()) {
            auto it(trie.scout(word));
            if (it.first)
                ++(it.second->second.freq_);
            else {
                trie.insertOrAssign(word, Citation(source, 1));
                ++(source.uniqueTermCnt_);
            }

            ++(source.termCnt_);
        }
    }
}

void Analyzer_txt::openFile(std::ifstream &infile, const std::string &fileName) {
    infile.open(fileName.c_str());
    if (infile.fail()) {
        std::cout << "Error opening file : " << fileName << std::endl;
        std::cout << "press enter to exit";
        std::cin.get();
        std::cin.get();
        exit(1);
    }
}
