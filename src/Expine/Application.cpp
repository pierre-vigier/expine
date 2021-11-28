#include "Application.h"
#include "Log.h"
#include "Event.h"
#include "Window.h"
#include <iostream>

namespace Expine
{
    //Application* Application::s_Instance = nullptr;

    Application::Application(const std::string &title)
        : m_Title(title)
    {
        Log::Init();
        XP_LOG_INFO("Application created");

        //create a window
        m_Window = new Window(title);
        m_Window->SetEventCallback([this](Event &e){HandleEvent(e);});
    }

    Application::~Application()
    {
        XP_LOG_INFO("Application destroyed");
        m_Window->OnShutdown();
        for(auto *l : m_Layers) {
            delete l;
        }
        delete m_Window;
    }

    void Application::HandleEvent(Event &e)
    {
        if( e.OfType(EventType::WindowsClosedEvent) ) {
            m_IsRunning = false;
            e.Handled = true;
        }
        for(auto it = m_Layers.rbegin(); it != m_Layers.rend(); it++ ) {
            XP_LOG_INFO("Processing event , sending to layers");
            (*it)->HandleEvent(e);
            if( e.Handled )
                break;
        }
    }

    void Application::Run()
    {
        while (m_IsRunning)
        {
            glClearColor(1.0, 0.0, 0.0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);
            for(auto *l : m_Layers) {
                l->OnUpdate();
            }
            m_Window->OnUpdate();
        }
    }
    
    void Application::PushLayer(Layer *layer) 
    {
        m_Layers.push_back(layer);
        layer->OnMount();
    }
}