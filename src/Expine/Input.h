#pragma once

#include "Application.h"

namespace Expine {
    class Input
    {
    public:
        static bool IsKeyPressed(const uint16_t keyCode){
            
            // get window
            auto *win = Application::Get().GetWindow().GetNativeWindow();
            auto state = glfwGetKey(win,keyCode);
            return state == GLFW_PRESS || state == GLFW_REPEAT;
        }
    };
}