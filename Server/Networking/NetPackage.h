//
// Created by jondorito on 29/04/19.
//

#ifndef GLADIATORS_GBP_NETPACKAGE_H
#define GLADIATORS_GBP_NETPACKAGE_H


#include <string>
#include "../libraries/rapidjson/document.h"

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



#endif //GLADIATORS_GBP_NETPACKAGE_H
