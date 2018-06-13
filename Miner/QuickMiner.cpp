#include <iostream>
#include "QuickMiner.h"


QuickMiner::QuickMiner(int maxGap, int maxPrefixNum, int maxSuffixNum)
    : accessLogs(), currenLogs(), ruleCache()
{
    // empty
}


void QuickMiner::miningByBatch() {
    // 检查日志输入序列
    if (accessLogs.empty()) {
        std::cout << "Access Logs is null! Exit...\n";
        return ;
    }

    // 根据规则 Ai & Aj -> Ak, i < j < k, j - 1 <= maxGap, k - j <= maxGap 生成规则
    for (int i = 0; i < accessLogs.size() - 2; i ++) {

        for (int j = i + 1; j <= maxGap + i && j < accessLogs.size() - 1; j ++) {
            std::string prefix = accessLogs[i] + "|" + accessLogs[j];

            for (int k = j + 1; k <= maxGap + j && k < accessLogs.size(); k ++) {
                string suffix = accessLogs[k];
                ruleCache.addRule(prefix, suffix);
            }
        }
    }
}

void QuickMiner::miningByStep(std::string& log) {
    int maxSize = 2 * maxGap + 1;

    // 如果 currentLogs.size < maxSize, 则直接添加新 log
    if (currenLogs.size() < maxSize) {
        currenLogs.emplace_back(log);
    }
    // 如果 currentLog.size >= maxSize, 则需要剔除最老的 log，再添加新 log
    else {
        currenLogs.erase(currenLogs.begin());
        currenLogs.emplace_back(log);
    }

    // 根据规则 Ai & Aj -> Ak, i < j < k, j - i <= maxGap, k - j <= maxGap 生成新规则
    // 从后向前，确定 maxGap 的区间找 prefix
    int lastPos = currenLogs.size() - 1;
    for (int j = lastPos -1; j >= lastPos - maxGap && j >= 1; j --) {
        // 类似 a|b -> b 这种规则不生成
        if (currenLogs[j] == log) {
            continue;
        }

        for (int i = j - 1; i >= j - maxGap && i >= 0; i--) {
            // 类似 a|b -> a 这种规则不生成
            if (currenLogs[i] == log) {
                continue
            }

            ruleCache.addRule(currenLogs[i] + currenLogs[j], log);
        }
    }


}



std::vector<string> QuickMiner::getPredictSuffix(std::string& prefix) {
    std::vector<std::string> suffixList;

    try {
        SuffixList suffixes = ruleCache.getRules().get(prefix);
        suffixList.emplace_back(suffixes.getSuffixList().begin(), suffixes.getSuffixList().end());
    } catch (std::range_error& error) {
        // do nothing
    }

    return suffixList;

}


int QuickMiner::getMaxGap() {
    return maxGap;
}

void QuickMiner::setMaxGap(int maxGap) {
    this->maxGap = maxGap;
}

std::vector<std::string> QuickMiner::getAccessLogs() {
    return accessLogs;
}

void QuickMiner::setAccessLogs(std::vector<std::string> &accessLogs) {
    this->accessLogs = accessLogs;
}

std::vector<std::string> QuickMiner::getCurrentLogs() {
    return currenLogs;
}

int QuickMiner::getMaxPreifxNum() {
    return maxPrefixNum;
}

int QuickMiner::getMaxSuffixNum() {
    return maxSuffixNum;
}


RuleCache QuickMiner::getRuleCache() {
    return ruleCache;
}

