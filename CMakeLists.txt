cmake_minimum_required(VERSION 3.18.4)
project(
    expine
    VERSION 0.1.0
    LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW 1.13 REQUIRED)

add_subdirectory(vendor/spdlog)

add_subdirectory(vendor/glm)

add_executable(
    expine
    src/main.cpp
    src/Expine/Application.cpp
    src/Expine/Log.cpp
)
target_compile_features(expine PRIVATE cxx_std_17)
target_include_directories(expine PUBLIC src/Expine src/OpenGL)
target_link_libraries(expine PUBLIC glfw spdlog_header_only OpenGL::GL GLEW::GLEW glm dl)
# imgui dl)