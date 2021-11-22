#include "Window.h"
#include "Log.h"
#include "Event.h"

namespace Expine
{
    Window::Window(const std::string &title)
       : m_Title(title)
    {
        Init();
    }
    
    void Window::SetEventCallback(std::function<void(const Event &)> fc) 
    {
        EventCallbackFunc = fc;
    }
    
    void Window::Init() 
    {
        int status = glfwInit();
        if (!status)
        {
            //Do something
        }
        glfwSetErrorCallback([](int error, const char* desc){
            XP_LOG_INFO("GLFW Error {}: {}", error, desc);
        });

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
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
                                        auto win = (Window *)glfwGetWindowUserPointer(w);
                                        WindowsClosedEvent e;
                                        win->EventCallbackFunc(e);
                                   });

        //Initialize GLEW
        glfwSetKeyCallback(m_Window, [](GLFWwindow *w, int key, int scancode, int action, int mods)
                           {
                               auto win = (Window *)glfwGetWindowUserPointer(w);
                               switch (action)
                               {
                               case GLFW_PRESS: {
                                   KeyPressedEvent e(key);
                                   win->EventCallbackFunc(e);
                                   break;}
                               case GLFW_RELEASE:{
                                   KeyReleasedEvent e(key);
                                   win->EventCallbackFunc(e);
                                   break;}
                               case GLFW_REPEAT:{
                                   XP_LOG_INFO("key repeat");
                                   break;
                               }
                               default:
                                   break;
                               }
                           });
        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *w, int button, int action, int mods)
                                   {
                                       auto &win = *(Window *)glfwGetWindowUserPointer(w);

                                       switch (action)
                                       {
                                       case GLFW_PRESS:
                                       {
                                           MouseButtonPressedEvent e(button);
                                           win.EventCallbackFunc(e);
                                           break;
                                       }
                                       case GLFW_RELEASE:
                                       {
                                           MouseButtonReleasedEvent e(button);
                                           win.EventCallbackFunc(e);
                                           break;
                                       }
                                       }
                                   });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *w, double xPos, double yPos)
                                 {
                                     auto &win = *(Window *)glfwGetWindowUserPointer(w);
                                     MouseMovedEvent e(xPos, yPos);
                                     win.EventCallbackFunc(e);
                                 });
        
    }

    void Window::OnUpdate() 
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }
    
    void Window::OnShutdown() 
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }
}