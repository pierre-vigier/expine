#pragma once

#include "Application.h"
#include "glm/vec2.hpp"

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

        static glm::vec2 GetMousePosition() {
            // get window
            auto *win = Application::Get().GetWindow().GetNativeWindow();
            double x,y;
            glfwGetCursorPos(win, &x, &y);
            return glm::vec2((float)x, (float)y);
        }
    };
}