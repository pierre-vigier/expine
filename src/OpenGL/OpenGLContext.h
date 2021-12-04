#pragma once

#include "Renderer/RenderingContext.h"
#include <GL/glew.h>
#include "GLFW/glfw3.h"

namespace Expine
{
    class OpenGLContext : public RenderingContext
    {
    public:
        OpenGLContext(GLFWwindow *w);
        virtual void Init() override;
        virtual void SwapBuffers() override;
    private:
        GLFWwindow *m_Window;
    };
}