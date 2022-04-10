#pragma once
#include <GL/glew.h> // just to include glew before GLFW...
#include "GLFW/glfw3.h"
#include "Event.h"
#include "OpenGLContext.h"
#include <string>
#include <functional>

namespace Expine {
    class Window {
    public:
        Window(const std::string &title);

        void SetEventCallback(std::function<void(Event &)> fc);
        void OnUpdate();
        void OnShutdown();
        
        GLFWwindow* GetNativeWindow() {
            return m_Window;
        }
    private:
        GLFWwindow *m_Window;
        std::string m_Title;
        OpenGLContext *m_Context;
    private:
        void Init();
        std::function<void(Event&)> EventCallbackFunc;
    };
}