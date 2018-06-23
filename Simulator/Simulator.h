//
// Created by cyril on 22/06/18.
//

#ifndef QUICKMINER_SIMULATOR_H
#define QUICKMINER_SIMULATOR_H

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

#include "../LRUCache/LRUCache.h"


class Simulator {
public:
    cache::LRUCache<string, string> FILE_CACHE;
    explicit Simulator(int fileCacheSize) : FILE_CACHE(cache::LRUCache<string, string>(fileCacheSize)) {};

    /**
	 * 从指定的文件中读取文件访问日志数据集
	 * @param filePath
	 * @param cutCommonPrefix	需要截断的文件名公共前缀
	 * @return	文件访问序列的文件名列表
	 */
    vector<string> getDataSet(string filePath, string cutCommonPrefix);

    /**
    * 从File Cache中读取文件，同时将文件加入Cache。
    * @param fileName
    * @return 命中返回文件名，未命中返回NULL。
    */
    string getFileFromCache(string fileName);


    /**
	 * 将fileName代表的文件放入Cache
	 * @param fileName
	 * @param file
	 */
    void putFileIntoCache(string fileName, string file);

    /**
    * 抽象方法。获取预测的后续文件
    * @param currentFile
    * @return	后续文件列表
    */
    virtual vector<string> getPredictFiles(string currentFile) = 0;
};


#endif //QUICKMINER_SIMULATOR_H
