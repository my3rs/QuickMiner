/**
 * 后缀列表， 保持特性：
 * 1. 可以快速判断一个 suffix 是否在列表中；
 * 2. 列表按照 support 由在到小保持顺序；
 * 3. 具有大小， 列表满时，移除最近最少使用的suffix（LFU）
 * */

#ifndef QUICKMINER_SUFFIXLIST_H
#define QUICKMINER_SUFFIXLIST_H

#include <string>
#include <map>
#include <vector>

#include "Suffix.h"
//#include "RuleCache.h"

class SuffixList {
private:
    std::map<std::string, int> key2Position;
    std::vector<Suffix> suffixList;
    int maxSuffixSize;

public:
    explicit SuffixList(int maxSuffixSize = 16) : key2Position(), suffixList(), maxSuffixSize(maxSuffixSize) {};

    // 向 SuffixList 中添加 Suffix 元素， 如果
    // 1. 该 Suffix 存在， 增加 suffix.support
    // 2. 该 Suffix 不存在， 添加 suffix, support = 1
    // 最后，移动 suffix 到相同 support 元素的第一个位置，更新位置映射
    void add(std::string &suffixName);

    void updateKey2Pos(std::string &suffixName, unsigned long oldPos, unsigned long newPos);

    std::map<std::string, int> &getKey2Position();

    std::vector<Suffix> &getSuffixList();

    void setMaxSuffixSize(int maxSuffixSize);

    friend std::ostream&operator<<(std::ostream &out, SuffixList &sl);
};


#endif //QUICKMINER_SUFFIXLIST_H
