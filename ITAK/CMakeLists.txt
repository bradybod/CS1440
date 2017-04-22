cmake_minimum_required(VERSION 3.6)
project(ITAK)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ITAK.cpp ITAK.hpp PortScanAnalyzer.cpp PortScanAnalyzer.hpp DOSAnalyzer.cpp DOSAnalyzer.hpp Config.cpp Config.hpp Dictionary.cpp Dictionary.hpp KeyValue.cpp KeyValue.hpp Result.cpp Result.hpp UserIP.hpp UserIPList.cpp UserIPList.hpp Analyzer.hpp KeyDictionary.hpp KeyCount.cpp KeyCount.hpp)
add_executable(ITAK ${SOURCE_FILES})