#include "Application.h"
#include <iostream>

namespace Expine
{
    Application* Application::s_Instance = nullptr;
    
    Application::Application() 
    {
        std::cout << "Application created" << std::endl;

        s_Instance = this;

        int status = glfwInit();
        if( !status ) {
            //Do something
        }
        //glfwSetErrorCallback();
        m_Window = glfwCreateWindow( 960, 540, "Untitled", nullptr, nullptr);
        if(!m_Window) {
            // Do something
        }
        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1);

        //Initialize GLEW

    }
    
    Application::~Application() 
    {
        std::cout << "Application destroyed" << std::endl;
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }
    
    void Application::Run() 
    {
        while( m_IsRunning ) {
            std::cout << "Application Running" << std::endl; 
        }
    }
}