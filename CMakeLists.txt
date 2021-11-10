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

add_library(stb_image vendor/stb_image/stb_image.cpp)
target_include_directories(stb_image PUBLIC vendor/stb_image)

add_executable(
    expine
    src/main.cpp
    src/Expine/Application.cpp
    src/Expine/Log.cpp
    src/OpenGL/Renderer.cpp
    src/OpenGL/VertexBuffer.cpp
    src/OpenGL/IndexBuffer.cpp
    src/OpenGL/VertexArray.cpp
    src/OpenGL/VertexBufferLayout.cpp
    src/OpenGL/Shader.cpp
    src/OpenGL/Texture.cpp
    src/SandBox/SandBox.cpp
)
target_compile_features(expine PRIVATE cxx_std_17)
target_include_directories(expine PUBLIC src/Expine src/OpenGL)
target_link_libraries(expine PUBLIC stb_image glfw spdlog_header_only OpenGL::GL GLEW::GLEW glm dl)
# imgui dl)