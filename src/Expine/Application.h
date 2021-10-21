#pragma once

#include "GLFW/glfw3.h"

namespace Expine {
    class Application
    {
    public:
        Application();
        ~Application();

        void Run();
    private:
        bool m_IsRunning = true;
        GLFWwindow* m_Window;
    private:
        static Application* s_Instance;
    };
}