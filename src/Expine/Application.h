#pragma once

#include "GLFW/glfw3.h"

#include <string>

namespace Expine {
    class Application
    {
    public:
        Application(const std::string& title);
        ~Application();

        void Run();
    private:
        std::string m_Title;
        bool m_IsRunning = true;
        GLFWwindow* m_Window;
    //private:
    //    static Application* s_Instance;
    };
}