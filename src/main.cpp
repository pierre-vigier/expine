#include "SandBox/SandBox.h"

// #include "Expine/Log.h"
// #include "glm/glm.hpp"

int main(int argc, char** argv) {
    auto app = new SandBox("Test");
    app->Run();
    delete app;
}
