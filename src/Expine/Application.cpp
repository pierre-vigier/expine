#include "Application.h"
#include "Log.h"
#include "Event.h"
#include <iostream>

namespace Expine
{
    //Application* Application::s_Instance = nullptr;

    Application::Application(const std::string &title)
        : m_Title(title)
    {
        Log::Init();
        XP_LOG_INFO("Application created");

        //s_Instance = this;

        int status = glfwInit();
        if (!status)
        {
            //Do something
        }
        //glfwSetErrorCallback();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow(960, 540, m_Title.c_str(), nullptr, nullptr);
        if (!m_Window)
        {
            // Do something
        }
        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1);

        /* Make the window's contect current */
        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1);

        // Initialize GLEW
        if (glewInit() != GLEW_OK)
        {
            fprintf(stderr, "Failed to initialize GLEW\n");
            getchar();
            glfwTerminate();
        }

        XP_LOG_INFO(glGetString(GL_VERSION));

        glfwSetWindowUserPointer(m_Window, this);

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *w)
                                   {
                                       auto &app = *(Application *)glfwGetWindowUserPointer(w);
                                       app.m_IsRunning = false;
                                   });

        //Initialize GLEeW
        glfwSetKeyCallback(m_Window, [](GLFWwindow *w, int key, int scancode, int action, int mods)
                           {
                               auto app = (Application *)glfwGetWindowUserPointer(w);
                               switch (action)
                               {
                               case GLFW_PRESS:
                                   app->HandleEvent(KeyPressedEvent(key));
                                   break;
                               case GLFW_RELEASE:
                                   app->HandleEvent(KeyReleasedEvent(key));
                                   break;
                               case GLFW_REPEAT:
                                   XP_LOG_INFO("key repeat");
                                   break;

                               default:
                                   break;
                               }
                           });
        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *w, int button, int action, int mods)
                                   {
                                       auto &app = *(Application *)glfwGetWindowUserPointer(w);

                                       switch (action)
                                       {
                                       case GLFW_PRESS:
                                       {
                                           app.HandleEvent(MouseButtonPressedEvent(button));
                                           break;
                                       }
                                       case GLFW_RELEASE:
                                       {
                                           app.HandleEvent(MouseButtonReleasedEvent(button));
                                           break;
                                       }
                                       }
                                   });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *w, double xPos, double yPos)
                                 {
                                     auto &app = *(Application *)glfwGetWindowUserPointer(w);
                                     app.HandleEvent(MouseMovedEvent(xPos, yPos));
                                 });
    }

    Application::~Application()
    {
        XP_LOG_INFO("Application destroyed");
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Application::HandleEvent(const Event &e)
    {
        XP_LOG_INFO("Event catched {}", e.GetName());
    }

    void Application::Run()
    {
        while (m_IsRunning)
        {
            glfwPollEvents();
            glfwSwapBuffers(m_Window);
        }
    }
}