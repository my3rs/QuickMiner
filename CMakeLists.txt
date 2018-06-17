PROJECT(QuickMiner)

CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(Miner)

ADD_SUBDIRECTORY(Miner)
ADD_SUBDIRECTORY(LRUCache)
ADD_SUBDIRECTORY(Simulator)

ADD_EXECUTABLE(QuickMinerSimulaotrTest QuickMinerSimulaotrTest.cpp)
TARGET_LINK_LIBRARIES(QuickMinerSimulaotrTest quick_miner)

ADD_EXECUTABLE(QuickMinerTest QuickMinerTest.cpp)
TARGET_LINK_LIBRARIES(QuickMinerTest quick_miner lru_cache)