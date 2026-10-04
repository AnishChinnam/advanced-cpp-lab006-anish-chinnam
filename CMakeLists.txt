cmake_minimum_required(VERSION 3.16)
project(LinkedListLab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_executable(test_linked_lists tests/test_linked_lists.cpp)

target_include_directories(test_linked_lists PRIVATE include)

if(BUILD_TESTING)
    add_test(NAME test_linked_lists COMMAND test_linked_lists)
endif()
