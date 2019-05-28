//
// Created by jondorito on 27/05/19.
//

#include <gtest/gtest.h>
#include "../Networking/NetPackage.h"

struct NetpackTest : testing::Test{
    NetPackage* netpack;
    NetpackTest(){
        netpack = new NetPackage;
    }

    ~NetpackTest(){
        delete netpack;
    }
};

TEST_F(NetpackTest, insertFrom){
    netpack->setFrom("Server");
    std::string expected = "{\"NetPackage\":{\"from\":\"Server\",\"data\":\"NONE\",\"command\":\"NONE\"}}";
    std::string result = netpack->getJSONPackage();
    ASSERT_EQ(expected, result);
}

TEST_F(NetpackTest, insertData){
    netpack->setData("data");
    std::string expected = "{\"NetPackage\":{\"from\":\"unassigned\",\"data\":\"data\",\"command\":\"NONE\"}}";
    std::string result = netpack->getJSONPackage();
    ASSERT_EQ(expected, result);
}

TEST_F(NetpackTest, insertCommand){
    netpack->setCommand("command");
    std::string expected = "{\"NetPackage\":{\"from\":\"unassigned\",\"data\":\"NONE\",\"command\":\"command\"}}";
    std::string result = netpack->getJSONPackage();
    ASSERT_EQ(expected, result);
}

