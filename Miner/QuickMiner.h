#ifndef QUICKMINER_QUICKMINER_H
#define QUICKMINER_QUICKMINER_H

#include <vector>
using std::vector;

#include <string>
using std::string;

class QuickMiner {
private:
    int maxGap;
    int maxPrefixNum;   // Rule Cache 中最多的 prefix 数量
    int maxSuffixNum;   // Rule Cache 中每个 prefix 对应的最多的 suffix 数量
    vector<string> accessLogs;      // 待挖掘的访问序列
    vector<string> currentogs;      // on-the-fly 生成规则的过程中，需要保存的日志

};


#endif //QUICKMINER_QUICKMINER_H
