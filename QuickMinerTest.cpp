//
// Created by cyril on 6/13/18.
//

#include <iostream>
#include "QuickMiner.h"

int main(int argc, char* argv[]) {
    std::vector<std::string> logs;
    logs.emplace_back("a");
    logs.emplace_back("b");
    logs.emplace_back("c");
    logs.emplace_back("d");
    logs.emplace_back("e");
    logs.emplace_back("f");
    logs.emplace_back("g");
    logs.emplace_back("h");
    logs.emplace_back("i");
    logs.emplace_back("j");
    
    QuickMiner miner;
    miner.setMaxGap(3);
    
    
    // 批量挖掘关联规则
    miner.setAccessLogs(logs);
    miner.miningByBatch();
    
    
    // 增量挖掘关联关系

    for (auto &log : logs) {
        miner.miningByStep(log);
    }

    miner.showRuleCache();
}