cmake_minimum_required(VERSION 3.18.4)
project(
    expine
    VERSION 0.1.0
    LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)

add_executable(
    expine
    src/main.cpp
    src/Expine/Application.cpp
)
target_compile_features(expine PRIVATE cxx_std_17)
target_link_libraries(expine PUBLIC glfw)
# imgui dl)