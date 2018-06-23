include_directories(../LRUCache)

add_library(simulator STATIC FileAccessLog.cpp QuickMinerSimulator.cpp Simulator.cpp)
target_link_libraries(simulator lru_cache)