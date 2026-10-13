cmake_minimum_required(VERSION 3.20)
project(LabStack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(Stack STATIC src/stack.cpp)
target_include_directories(Stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(StackApp app/main.cpp)
target_link_libraries(StackApp PRIVATE Stack)

include(CTest)
if(BUILD_TESTING)
    add_executable(StackTests tests/test_stack.cpp)
    target_link_libraries(StackTests PRIVATE Stack)
    add_test(NAME StackTests COMMAND StackTests)
endif()
