#pragma once

#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "Event.h"
#include <string>
#include <functional>

namespace Expine {
    class Window {
    public:
        Window(const std::string &title);

        void SetEventCallback(std::function<void(Event &)> fc);
        void OnUpdate();
        void OnShutdown();
    private:
        GLFWwindow *m_Window;
        std::string m_Title;
    private:
        void Init();
        std::function<void(Event&)> EventCallbackFunc;
    };
}