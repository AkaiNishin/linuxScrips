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

set(SCRIP_SOURCE ${CMAKE_SOURCE_DIR}/scrips)
set(SCRIP_DIR ${CMAKE_SOURCE_DIR}/scrips)
add_custom_target(
    copy_scrips ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${SCRIP_SOURCE} ${SCRIP_DIR}
    COMMENT "Copy script to binary directory"
)

add_dependencies(${PROJECT_NAME} copy_scrips)

