/**
 * 存储关联规则， prefix 采用 LRU 替换策略， suffix 采用 LFU 替换策略
 * */

#ifndef QUICKMINER_RULECACHE_H
#define QUICKMINER_RULECACHE_H

#include "LRUCache.h"
#include "SuffixList.h"


class RuleCache {
private:
    cache::LRUCache<std::string, SuffixList> rules;     // 存储Rules： Key为 A|B 形式的 prefix， Value为预测的后缀列表
    int maxCapacity;                // capacity of cache
    int maxSuffixCapacity;          // capacity of Prefix's SuffixList

public:
    bool addRule(std::string prefix, std::string suffix);

    cache::LRUCache<std::string, SuffixList>& getRules();

    int getMaxCapacity();

    int getMaxSuffixCapacity();

};


#endif //QUICKMINER_RULECACHE_H
