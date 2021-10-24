cmake_minimum_required(VERSION 3.18.4)
project(
    expine
    VERSION 0.1.0
    LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)

add_subdirectory(vendor/spdlog)
#set(spdlog_DIR vendor/spdlog)
#find_package(spdlog)
# add_subdirectory(vendor/glm)

add_executable(
    expine
    src/main.cpp
    src/Expine/Application.cpp
)
target_compile_features(expine PRIVATE cxx_std_17)
# target_compile_definitions(expine
#     PUBLIC
#         SPDLOG_COMPILED_LIB
#         SPDLOG_FMT_EXTERNAL
# )
target_link_libraries(expine PUBLIC glfw spdlog_header_only)
# imgui dl)