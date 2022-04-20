#include "Camera.h"
#include "Input.h"
#include "Log.h"
#include <iostream>
namespace Expine
{
    PerspectiveCamera::PerspectiveCamera() : m_Position(glm::vec3(0.0f)),
                                             m_Up(glm::vec3(0.0f, 1.0f, 0.f)),
                                             m_Yaw(-90.f),
                                             m_FOV(70.f),
                                             m_Height(540.f),
                                             m_Width(960.f)
    {
        computeDirection();
        recalculateProjection();
    }

    void PerspectiveCamera::SetPosition(float x, float y, float z)
    {
        m_Position = glm::normalize(glm::vec3(x, y, z));
    }

    glm::mat4 PerspectiveCamera::GetMatrix()
    {
        return m_Projection * glm::lookAt(m_Position, m_Position + m_Direction, m_Up);
        // return glm::lookAt(m_Position,m_Position + m_Direction ,m_Up) * m_Projection;
    }

    void PerspectiveCamera::OnUpdate(float elapsed)
    {
        glm::vec3 move = m_Direction;
        move.y = 0;
        if (Input::IsKeyPressed(GLFW_KEY_W))
        {
            m_Position += move * m_MoveSpeed * elapsed;
        }
        if (Input::IsKeyPressed(GLFW_KEY_S))
        {
            m_Position -= move * m_MoveSpeed * elapsed;
        }
        if (Input::IsKeyPressed(GLFW_KEY_D))
        {
            auto right = glm::normalize(glm::cross(move, m_Up));
            m_Position += right * m_MoveSpeed * elapsed;
        }
        if (Input::IsKeyPressed(GLFW_KEY_A))
        {
            auto right = glm::normalize(glm::cross(move, m_Up));
            m_Position -= right * m_MoveSpeed * elapsed;
        }
        if (Input::IsKeyPressed(GLFW_KEY_E))
        {
            m_Yaw += m_RotateSpeed * elapsed;
        }
        if (Input::IsKeyPressed(GLFW_KEY_Q))
        {
            m_Yaw -= m_RotateSpeed * elapsed;
        }

        // check mouse coordinates
        glm::vec2 mPos = Input::GetMousePosition();
        static float lastMx = mPos.x;
        static float lastMy = mPos.y;
        float xOffset = mPos.x - lastMx;
        lastMx = mPos.x;
        m_Yaw += xOffset * m_Sensitivity;
        if (m_Yaw > 180)
        {
            m_Yaw -= 360;
        }
        if (m_Yaw < -180)
        {
            m_Yaw += 360;
        }
        float yOffset = mPos.y - lastMy;
        lastMy = mPos.y;
        m_Pitch -= yOffset * m_Sensitivity;
        if (m_Pitch > 89)
        {
            m_Pitch = 89;
        }
        if (m_Pitch < -89)
        {
            m_Pitch = -89;
        }
        computeDirection();
    }

    void PerspectiveCamera::recalculateProjection() {
        m_Projection = glm::perspective(glm::radians<float>(m_FOV), m_Width/m_Height , 0.1f, 1000.f);
    }

    void PerspectiveCamera::HandleEvent(Event &e)
    {
        if (e.OfType(EventType::WindowResizedEvent))
        {
            auto wre = static_cast<WindowResizedEvent &>(e);
            std::cout << "Windows resized " << wre.getWidth() << " * " << wre.getHeight() << std::endl;
            m_Width = (float)wre.getWidth();
            m_Height = (float)wre.getHeight();
            recalculateProjection();
        } else if (e.OfType(EventType::MouseScrolledEvent)) {
            auto mse = static_cast<MouseScrolledEvent &>(e);
            // change zoom level
            m_FOV += mse.getOffsetY();
            if( m_FOV > 80 ) {
                m_FOV = 80;
            }
            if( m_FOV < 20 ) {
                m_FOV = 20;
            }
            XP_LOG_INFO("FOV {}", m_FOV);
            recalculateProjection();
        }
    }

    void PerspectiveCamera::computeDirection()
    {
        m_Direction.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
        m_Direction.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
        m_Direction.y = sin(glm::radians(m_Pitch));
        m_Direction = glm::normalize(m_Direction);
    }

}