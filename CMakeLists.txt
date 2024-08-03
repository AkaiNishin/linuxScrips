cmake_minimum_required(VERSION 3.20)
project(linuxScrips CXX)

add_executable(${PROJECT_NAME} main.cpp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# fetch latest argparse
include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

target_link_libraries(${PROJECT_NAME} argparse)

add_custom_target(
    copy_scrips ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/scrips ${CMAKE_BINARY_DIR}/scrips
    COMMENT "Copy script to binary directory"
)

add_dependencies(${PROJECT_NAME} copy_scrips)

