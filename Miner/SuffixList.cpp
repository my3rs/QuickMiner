//
// Created by cyril on 6/12/18.
//

#include "SuffixList.h"
#include <iostream>

void SuffixList::add(std::string& suffixName) {
    // init: add the first suffix
    if (this->suffixList.empty()) {
        suffixList.emplace_back(Suffix(suffixName, 1));
        key2Position.emplace(suffixName, 0);

        return;
    }

    int posObj = key2Position.find(suffixName) == key2Position.end() ? -1 : key2Position[suffixName];

    // first time to add
    if (posObj == -1) {
        unsigned long tailPos = suffixList.size() - 1;
        bool insert = false;

        for (unsigned long i = tailPos; i >= 0; i--) {
            if (1 < suffixList[i].getSupport()) {
                insert = true;
                suffixList.insert(suffixList.begin() + i + 1, Suffix(suffixName, 1));
                updateKey2Pos(suffixName, INT32_MAX, i + 1);
                break;
            }
        }
        if (!insert) {
            suffixList.insert(suffixList.begin(), Suffix(suffixName, 1));
            updateKey2Pos(suffixName, INT32_MAX, 0);
        }
    }
    // not the first time to add
    else {
        int pos = posObj;

        int newSupport = suffixList[pos].getSupport() + 1;
        bool insert = false;
        for (int i = pos; i >= 0; i--) {
            if (newSupport < suffixList[i].getSupport()) {
                insert = true;
                suffixList.erase(suffixList.begin() + pos);
                suffixList.insert(suffixList.begin() + i + 1, Suffix(suffixName, newSupport));
                updateKey2Pos(suffixName, pos, i + 1);
                break;
            }
        }
        if (!insert) {
            suffixList.erase(suffixList.begin() + pos);
            suffixList.insert(suffixList.begin(), Suffix(suffixName, newSupport));
            updateKey2Pos(suffixName, pos, 0);
        }
    }

    // 如果超出规定的 List 大小，移除最后一个元素
    if (suffixList.size() > this->maxSuffixSize) {
        std::string key = suffixList[maxSuffixSize].getSuffix();
          suffixList.erase(suffixList.end() - 1);
        key2Position.erase(key);
    }
}


void SuffixList::updateKey2Pos(std::string &suffixName, unsigned long oldPos, unsigned long newPos) {
    if (oldPos == newPos) {
        return;
    }

    for (auto entry : key2Position) {
        if (entry.second >= newPos && entry.second < oldPos) {
            key2Position[entry.first] = entry.second + 1;
        }
    }
    key2Position[suffixName] = newPos;
}

std::map<std::string, int>& SuffixList::getKey2Position() {
    return key2Position;
}


std::vector<Suffix>& SuffixList::getSuffixList() {
    return suffixList;
}

void SuffixList::setMaxSuffixSize(int maxSuffixSize) {
    this->maxSuffixSize = maxSuffixSize;
}

std::ostream&operator<<(std::ostream &out, SuffixList &sl) {
    out << "[";
    for (auto &entry : sl.suffixList) {
        out << entry << ", ";
    }
    out << "\b\b]";

    return out;
}
