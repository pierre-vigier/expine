cmake_minimum_required(VERSION 3.18.4)
project(
    expine
    VERSION 0.1.0
    LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(
    expine
    src/main.cpp
)
target_compile_features(expine PRIVATE cxx_std_17)
# target_link_libraries(expine PUBLIC imgui dl)