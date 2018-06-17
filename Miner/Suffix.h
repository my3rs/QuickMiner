//
// Created by cyril on 6/12/18.
//

#ifndef QUICKMINER_SUFFIX_H
#define QUICKMINER_SUFFIX_H

#include <string>



class Suffix {
private:
    std::string suffix;     // suffix 代表的文件名， TODO： 替换为文件对象，挖掘更多信息
    int support = 1;        // suffix 发生的次数

public:
    Suffix(std::string &suffix, int support) : suffix(suffix), support(support) {};

    std::string getSuffix();

    void setSuffix(std::string &suffix);

    int getSupport();

    void setSupport(int support);

    friend std::ostream &operator<<(std::ostream &out, const Suffix &s);
};


#endif //QUICKMINER_SUFFIX_H
