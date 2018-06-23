#ifndef QUICKMINER_QUICKMINER_H
#define QUICKMINER_QUICKMINER_H

#include <vector>

#include <string>

#include "RuleCache.h"

class QuickMiner {
private:
    int maxGap;
    int maxPrefixNum;   // Rule Cache 中最多的 prefix 数量
    int maxSuffixNum;   // Rule Cache 中每个 prefix 对应的最多的 suffix 数量
    std::vector<std::string> accessLogs;      // 待挖掘的访问序列
    std::vector<std::string> currenLogs;      // on-the-fly 生成规则的过程中，需要保存的日志
    RuleCache ruleCache;            // 存放生成的关联规则

public:
    explicit QuickMiner(int maxGap = 5, int maxPrefixNum = 1024, int maxSuffixNum = 16);

    // 批量挖掘关联规则：根据所有的访问日志，生成所有的规则
    void miningByBatch();

    // 增量挖掘关联规则：添加一个新的访问记录，同时生成新的rule。保证线程同步
    void miningByStep(std::string& log);

    // 根据 prefix 返回预测的后缀列表
    std::vector<Suffix> getPredictSuffix(std::string& prefix);


    int getMaxGap();
    void setMaxGap(int maxGap);
    std::vector<std::string> getAccessLogs();
    void setAccessLogs(std::vector<std::string>& accessLogs);
    std::vector<std::string> getCurrentLogs();
    int getMaxPreifxNum();
    int getMaxSuffixNum();
    RuleCache getRuleCache();

    void showRuleCache();
};


#endif //QUICKMINER_QUICKMINER_H
