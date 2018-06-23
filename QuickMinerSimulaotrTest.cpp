#include "QuickMinerSimulator.h"


using std::vector;
using std::string;

int main(int argc, char* argv[]) {
    for (int fileCacheSize = 1; fileCacheSize <= 50; fileCacheSize ++) {
        QuickMinerSimulator simulator(fileCacheSize);
        // get data set
        vector<string> logs = simulator.getDataSet("/home/cyril/DataSet/audit.log", "/user/root/input/sogou/query-log-");

        // generate rules: QuickMine don't need to generate rules ahead
        int hitCount = 0;
        int prefetchCount = 0;
        clock_t totalTime = 0;

        for (auto currentFile : logs) {
            clock_t start = clock();
            string targetFile = simulator.getFileFromCache(currentFile);
            if (targetFile.empty()) {
                // read miss causes prediction
                for (auto file : simulator.getPredictFiles(currentFile)) {
                    simulator.putFileIntoCache(file, file);
                    prefetchCount ++;
                }
            } else {
                // hit
                hitCount ++;
            }

            // generate new rules incrementally
            simulator.generateNewRule(currentFile);

            clock_t end = clock();
            totalTime += end - start;
        }
        cout << "Cache Size: " << fileCacheSize << "\tQuickMiner Hit Ratio: " << hitCount * 1.0f / logs.size()
             << "\tTotal Time: " << totalTime * 1.0f / CLOCKS_PER_SEC << "s.\n";

    }
}