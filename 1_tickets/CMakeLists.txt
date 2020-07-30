cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(tickets VERSION 0.0.1)

add_executable(tickets_cli ticketsHW.cpp)

set(SOURCES  ../testSystem/cTester.cpp)
set(HEADERS  ../testSystem/cTester.h)
add_library(TesterLib ${SOURCES} ${HEADERS})


set_target_properties(tickets_cli TesterLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(tickets_cli TesterLib)
