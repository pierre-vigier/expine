#include "OpenGLContext.h"
#include "Log.h"

#include <string>

namespace Expine
{
    OpenGLContext::OpenGLContext(GLFWwindow *w)
        : m_Window(w)
    {
        
    }

    void OpenGLContext::Init() 
    {
        glfwMakeContextCurrent(m_Window);
        // Initialize GLEW
        if (glewInit() != GLEW_OK)
        {
            fprintf(stderr, "Failed to initialize GLEW\n");
            getchar();
            glfwTerminate();
        }

        XP_LOG_INFO(glGetString(GL_VERSION));
    }
    
    void OpenGLContext::SwapBuffers() 
    {
        glfwSwapBuffers(m_Window);
    }
}