//
// Created by cyril on 22/06/18.
//

#ifndef QUICKMINER_FILEACCESSLOG_H
#define QUICKMINER_FILEACCESSLOG_H

#include <ostream>
#include <string>

class FileAccessLog {
private:
    // Log记录格式：time: ugi= ip= cmd= Miner=	dst= perm=
    // 范例：2013-11-21 17:24:54,697: ugi=root	ip=/127.0.0.1	cmd=open	Miner=/input/access_log_1	dst=null	perm=null
    std::string time;   // 客户端访问文件的时间：yyyy-MM-dd HH:mm:ss,SSS
    std::string ugi;    // 客户端的用户标识
    std::string ip;     // 客户端的IP
    std::string cmd;    // 文件访问的具体操作，包括：open|create|delete|rename|mkdirs|listStatus|setReplication|setOwner|setPermission
    std::string src;    // 文件操作中源文件地址
    std::string dst;    // 文件操作中目标文件地址
    std::string perm;   // 操作权限
    bool valid = true;

public:
    friend std::ostream& operator << (std::ostream &output, FileAccessLog &log);

    static FileAccessLog parse(std::string logLine);

    std::string getTime();

    void setTime(std::string time);

    std::string getUgi();

    void setUgi(std::string ugi);

    std::string getIp();

    void setIp(std::string ip);

    std::string getCmd();

    void setCmd(std::string cmd);

    std::string getSrc();

    void setSrc(std::string src);

    std::string getDst();

    void setDst(std::string dst);

    std::string getPerm();

    void setPerm(std::string perm);

    bool isValid();

    void setValid(bool valid);
};


#endif //QUICKMINER_FILEACCESSLOG_H
