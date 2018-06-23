#include "QuickMinerSimulator.h"


using std::vector;
using  std::string;
std::vector<std::string> QuickMinerSimulator::getPredictFiles(std::string currentFile) {
    vector<string> predictSuffixes;
    vector<string> history = miner.getCurrentLogs();
    unsigned long historySize = history.size();

    if (historySize >= 2) {
        string prefix = history[historySize - 2] + "|" + history[historySize - 1];
        vector<Suffix> candidateSuffix = miner.getPredictSuffix(prefix);

        int count = 0;
        for (int i = 0; i< candidateSuffix.size() && count < this->prefectNum; i++) {
            string suffix = candidateSuffix[i].getSuffix();
            try {
                FILE_CACHE.get(suffix);
                continue;
            } catch (...) {
                predictSuffixes.emplace_back(suffix);
                count ++;
            }

        }
    }
    return predictSuffixes;
}

void QuickMinerSimulator::generateNewRule(std::string currentFile) {
    miner.miningByStep(currentFile);
}

