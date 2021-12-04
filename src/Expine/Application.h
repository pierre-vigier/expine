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

        void HandleEvent(Event &e);
        void Run();

        void PushLayer(Layer *layout);
    private:
        std::string m_Title;
        bool m_IsRunning = true;
        Window *m_Window;
        std::vector<Layer *> m_Layers;
    };
}