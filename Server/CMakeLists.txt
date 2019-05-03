cmake_minimum_required(VERSION 3.13)
project(Gladiators-GBP)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS  -pthread)

add_executable(Server Logic main.cpp Logic/GenericLinkedList.h Logic/GenericNode.h Logic/Zone.cpp Logic/Zone.h Networking/NetPackage.cpp Networking/NetPackage.h Networking/Server.h Logic/Gladiator.cpp Logic/Gladiator.h Logic/GA.cpp Logic/GA.h)