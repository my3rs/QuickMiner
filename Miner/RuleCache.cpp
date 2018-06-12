#include "RuleCache.h"


bool RuleCache::addRule(std::string prefix, std::string suffix) {
    bool isNewRule = true;
    SuffixList suffixList;
    try {
        suffixList = rules.get(prefix);
    } catch (std::range_error &error) {
        suffixList.setMaxSuffixSize(maxSuffixCapacity);
        isNewRule = false;
    }

    suffixList.add(suffix);
    rules.put(prefix, suffixList);

    return isNewRule;
}

cache::LRUCache<std::string, SuffixList>& RuleCache::getRules() {
    return this->rules;
}

int RuleCache::getMaxCapacity() {
    return this->maxCapacity;
}

int RuleCache::getMaxSuffixCapacity() {
    return this->maxSuffixCapacity;
}