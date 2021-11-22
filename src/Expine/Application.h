#pragma once

#include "Event.h"
#include "Window.h"

#include <string>

namespace Expine {
    class Application
    {
    public:
        Application(const std::string& title);
        Application(const Application &a) = delete;
        ~Application();

        void HandleEvent(const Event &e);
        void Run();
        virtual void OnUpdate() {};
    private:
        std::string m_Title;
        bool m_IsRunning = true;
        Window *m_Window;
    //private:
    //    static Application* s_Instance;
    };
}