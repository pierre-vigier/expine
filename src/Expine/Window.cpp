#include "Window.h"
#include "Log.h"
#include "Event.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace Expine
{
    Window::Window(const std::string &title)
        : m_Title(title)
    {
        Init();
    }

    void Window::SetEventCallback(std::function<void(Event &)> fc)
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
        glfwSetErrorCallback([](int error, const char *desc)
                             { XP_LOG_INFO("GLFW Error {}: {}", error, desc); });

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
                               case GLFW_PRESS:
                               {
                                   KeyPressedEvent e(key);
                                   win->EventCallbackFunc(e);
                                   break;
                               }
                               case GLFW_RELEASE:
                               {
                                   KeyReleasedEvent e(key);
                                   win->EventCallbackFunc(e);
                                   break;
                               }
                               case GLFW_REPEAT:
                               {
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
        const char *glsl_version = "#version 130";
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        //IMGUI_CHECKVERSION();
        ImGuiIO& io = ImGui::GetIO();
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        //io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windowss
        ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);

    }
    void Window::OnUpdate()
    {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        static bool open = true;
        ImGui::ShowDemoWindow(&open);
        ImGui::Begin("Hello, world!");            // Create a window called "Hello, world!" and append into it.
        ImGui::Text("This is some useful text."); // Display some text (you can use a format strings too)
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
        ImGui::Render();
        auto rs = ImGui::GetDrawData();
        ImGui_ImplOpenGL3_RenderDrawData( rs);
        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
        glfwSwapBuffers(m_Window);
    }

    void Window::OnShutdown()
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }
}