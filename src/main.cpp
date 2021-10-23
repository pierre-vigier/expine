#include "SandBox/SandBox.h"

int main(int argc, char** argv) {
    auto app = new SandBox("Test");
    app->Run();
    delete app;
}
