#include "SandBox/SandBox.h"

#include "spdlog/spdlog.h"
// #include "glm/glm.hpp"

int main(int argc, char** argv) {
    spdlog::info("Welcome to spdlog!");
    spdlog::debug("This is a default");
    auto app = new SandBox("Test");
    app->Run();
    delete app;
}
