#pragma once
#include <GL/glew.h>

#include "Event.h"
#include "Window.h"
#include "Layer.h"

#include <string>
#include <vector>

namespace Expine {
    class Application
    {
    public:
        Application(const std::string& title);
        Application(const Application &a) = delete;
        ~Application();

        //Assumption, one Window per app
        Window& GetWindow() { return *m_Window; }

        void HandleEvent(Event &e);
        void Run();

        void PushLayer(Layer *layout);

        static Application& Get() { return *s_Instance; }
    private:
        static Application* s_Instance;
        std::string m_Title;
        bool m_IsRunning = true;
        Window *m_Window;
        std::vector<Layer *> m_Layers;

        // time management
        float m_lastFrameTime = 0.f;
    };
}