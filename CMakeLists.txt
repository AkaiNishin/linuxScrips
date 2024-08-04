cmake_minimum_required(VERSION 3.20)
project(linuxScrips CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# fetch latest argparse
include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

FetchContent_Declare(
    cpr 
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8
)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(
    json 
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

add_subdirectory(source)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(
    ${PROJECT_NAME} PRIVATE
    commands
    argparse
    cpr::cpr
    nlohmann_json::nlohmann_json
)

set(SCRIP_SOURCE ${CMAKE_SOURCE_DIR}/scrips)
set(SCRIP_DIR ${CMAKE_SOURCE_DIR}/scrips)
add_custom_target(
    copy_scrips ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${SCRIP_SOURCE} ${SCRIP_DIR}
    COMMENT "Copy script to binary directory"
)

add_dependencies(${PROJECT_NAME} copy_scrips)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/source)

