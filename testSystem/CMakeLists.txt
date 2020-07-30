cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(cTesterLibrary VERSION 0.0.1)
set(SOURCES cTester.cpp)
set(HEADERS cTester.h)
add_library(TesterLib ${SOURCES} ${HEADERS})

set_target_properties(TesterLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(TesterLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})