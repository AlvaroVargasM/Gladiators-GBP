cmake_minimum_required(VERSION 3.13)
project(Gladiators-GBP)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libraries/googletest-master)
include_directories(libraries/googletest-master/googletest/include)
include_directories(libraries/googletest-master/googlemock/include)

SET(CMAKE_CXX_FLAGS  -pthread)

add_executable(Server Logic main.cpp Logic/GenericLinkedList.h Logic/GenericNode.h Logic/Zone.cpp Logic/Zone.h Networking/NetPackage.cpp Networking/NetPackage.h Networking/Server.h Logic/Gladiator.cpp Logic/Gladiator.h Logic/GA.cpp Logic/GA.h Logic/IntimidationZone.h Logic/IntimidationZone.cpp Logic/RNG.cpp Logic/RNG.h Networking/Server.h Networking/Server.cpp Logic/PathSolver.cpp Logic/PathSolver.h Logic/Game.h Logic/Game.cpp Logic/timer.cpp Logic/timer.h UnitTest/PathFindingTesting.cpp MockObjects/MockPathSolver.h)
target_link_libraries(Server gtest gtest_main)