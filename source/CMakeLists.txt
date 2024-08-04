add_library(commands OBJECT Commands.cpp)

target_include_directories(commands PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(commands PUBLIC
    cpr::cpr
    nlohmann_json::nlohmann_json
)

