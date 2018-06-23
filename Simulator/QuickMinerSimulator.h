/**
 * 采用 QuickMiner 算法作为 PredictCache 的预测算法，模拟使用
 * */

#ifndef QUICKMINER_QUICKMINERSIMULATOR_H
#define QUICKMINER_QUICKMINERSIMULATOR_H

#include "Simulator.h"
#include "QuickMiner.h"

class QuickMinerSimulator : public Simulator {
private:
    QuickMiner miner;
    int prefectNum;

public:
    explicit QuickMinerSimulator(int fileCacheSize, int prefectNum = 3) : Simulator(fileCacheSize), prefectNum(prefectNum), miner(3, 8, 1024) {};

    // currentFile not used yes.
    std::vector<std::string> getPredictFiles(std::string currentFile) override ;

    // generate new rule by step
    void generateNewRule(std::string currentFile);

};


#endif //QUICKMINER_QUICKMINERSIMULATOR_H
