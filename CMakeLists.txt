cmake_minimum_required(VERSION 3.16)
project(LinkedList LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        ListTest
        LinkedListTest/test.cpp
        LinkedList/linked_list.c
        LinkedList/linked_list.h
)
target_link_libraries(
        ListTest
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(ListTest)