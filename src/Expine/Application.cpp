#include "Application.h"
#include "Log.h"
#include <iostream>

namespace Expine
{
    //Application* Application::s_Instance = nullptr;

    Application::Application(const std::string& title)
        :m_Title(title) 
    {
        Log::Init();
        XP_LOG_INFO("Application created");

        //s_Instance = this;

        int status = glfwInit();
        if( !status ) {
            //Do something
        }
        //glfwSetErrorCallback();
        m_Window = glfwCreateWindow( 960, 540, m_Title.c_str(), nullptr, nullptr);
        if(!m_Window) {
            // Do something
        }
        glfwMakeContextCurrent(m_Window);
        //glfwSwapInterval(1);

        glfwSetWindowUserPointer(m_Window, this);

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* w) {
            auto app = (Application*)glfwGetWindowUserPointer(w);
            app->m_IsRunning = false;
        });
        //Initialize GLEW

    }
    
    Application::~Application() 
    {
        XP_LOG_INFO("Application destroyed");
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }
    
    void Application::Run() 
    {
        while( m_IsRunning ) {
            glfwPollEvents();
            glfwSwapBuffers(m_Window);
        }
    }
}