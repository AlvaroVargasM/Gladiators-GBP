//
// Created by jondorito on 29/04/19.
//

#define RAPIDJSON_HAS_STDSTRING 1

#include "NetPackage.h"

#include "NetPackage.h"
#include "../libraries/rapidjson/document.h"
#include "../libraries/rapidjson/writer.h"
#include "../libraries/rapidjson/stringbuffer.h"

NetPackage::NetPackage() {
}

std::string NetPackage::getJSONPackage(){
    rapidjson::Document docu;

    docu.SetObject();

    rapidjson::Document::AllocatorType& allocator = docu.GetAllocator();

    rapidjson::Value object(rapidjson::kObjectType);
    object.AddMember("from", this->from, allocator);
    object.AddMember("data", this->data, allocator);
    object.AddMember("command", this->command, allocator);
    docu.AddMember("NetPackage", object, allocator);

    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
    docu.Accept(writer);

    return strbuf.GetString();
}

std::string NetPackage::getFrom() {
    return this->from;
}

std::string NetPackage::getData() {
    return this->data;
}

std::string NetPackage::getcommand() {
    return this->command;
}

void NetPackage::setFrom(std::string form) {
    this->from = form;
}

void NetPackage::setData(std::string data) {
    this->data = data;
}

void NetPackage::setCommand(std::string command) {
    this->command = command;
}

