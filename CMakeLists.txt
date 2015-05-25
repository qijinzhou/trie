cmake_minimum_required(VERSION 2.8.7)
project(trie_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES test.cpp)

add_executable(trie_test ${SOURCE_FILES})

target_link_libraries(trie_test ${GTEST_BOTH_LIBRARIES})

add_test(all trie_test)

