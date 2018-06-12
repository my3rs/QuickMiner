include_directories(../LRUCache)

add_library(quick_miner STATIC QuickMiner.cpp RuleCache.cpp SuffixList.cpp Suffix.cpp)
target_link_libraries(quick_miner lru_cache)