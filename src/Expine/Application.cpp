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

        // glfwSetCharCallback(m_Window,[](GLFWwindow* w, unsigned int c) {
        //     auto app = (Application*)glfwGetWindowUserPointer(w);
        //     XP_LOG_INFO("key pressed");
        // });
        //Initialize GLEeW
        glfwSetKeyCallback(m_Window,[](GLFWwindow *w, int key, int scancode, int action, int mods){
            auto app = (Application*)glfwGetWindowUserPointer(w);
            switch (action)
            {
            case GLFW_PRESS:
                XP_LOG_INFO("key pressed");
                break;
            case GLFW_RELEASE:
                XP_LOG_INFO("key released");
                break;
            case GLFW_REPEAT:
                XP_LOG_INFO("key repeat");
                break;
            
            default:
                break;
            }
        });
        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* w, int button, int action, int mods)
		{
			auto& app = *(Application*)glfwGetWindowUserPointer(w);

			switch (action)
			{
				case GLFW_PRESS:
				{
                    XP_LOG_INFO("Mouse button pressed");
					break;
				}
				case GLFW_RELEASE:
				{
                    XP_LOG_INFO("Mouse button released");
					break;
				}
			}
		});


		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* w, double xPos, double yPos)
		{
			auto& app = *(Application*)glfwGetWindowUserPointer(w);
            XP_LOG_INFO("Mouse cursor at : {}, {}",xPos,yPos);

		});
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