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
        m_Window->SetEventCallback([this](const Event &e){HandleEvent(e);});
    }

    Application::~Application()
    {
        XP_LOG_INFO("Application destroyed");
        m_Window->OnShutdown();
        delete m_Window;
    }

    void Application::HandleEvent(const Event &e)
    {
        XP_LOG_INFO("Event catched {}", e.GetName());
        if( e.OfType(EventType::WindowsClosedEvent) ) {
            m_IsRunning = false;
        }
    }

    void Application::Run()
    {
        while (m_IsRunning)
        {
            OnUpdate();
            m_Window->OnUpdate();
        }
    }
}