#ifndef NETPACKAGE_H
#define NETPACKAGE_H

#define RAPIDJSON_HAS_STDSTRING 1


#include <string>
#include "libraries/rapidjson/document.h"
#include "libraries/rapidjson/writer.h"
#include "libraries/rapidjson/stringbuffer.h"

class NetPackage {
private:
    std::string from = "unassigned";
    std::string command = "NONE";
    std::string data =  "NONE";
public:
    NetPackage();
    std::string getJSONPackage();
    std::string getFrom();
    std::string getData();
    std::string getcommand();
    void setFrom(std::string);
    void setData(std::string);
    void setCommand(std::string);
    static rapidjson::Document convertToRJ_Document(std::string);
};

#endif // NETPACKAGE_H
