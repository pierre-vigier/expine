#include "Camera.h"
#include "Input.h"

namespace Expine
{
    PerspectiveCamera::PerspectiveCamera() : m_Position(glm::vec3(0.0f)),
                                             m_Up(glm::vec3(0.0f, 1.0f, 0.f)),
                                             m_Angle(180.f),
                                             m_Projection(glm::perspective(70.0f, 960.f / 540.f, 0.1f, 1000.f))
    {
        computeDirection();
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

    void PerspectiveCamera::OnUpdate()
    {
        if (Input::IsKeyPressed(GLFW_KEY_W))
        {
            m_Position += m_Direction * m_MoveSpeed;
        }
        if (Input::IsKeyPressed(GLFW_KEY_S))
        {
            m_Position -= m_Direction * m_MoveSpeed;
        }
        if (Input::IsKeyPressed(GLFW_KEY_D))
        {
            auto right = glm::normalize(glm::cross(m_Direction, m_Up));
            m_Position += right * m_MoveSpeed;
        }
        if (Input::IsKeyPressed(GLFW_KEY_A))
        {
            auto right = glm::normalize(glm::cross(m_Direction, m_Up));
            m_Position -= right * m_MoveSpeed;
        }
        if (Input::IsKeyPressed(GLFW_KEY_E))
        {
            m_Angle += m_RotateSpeed;
            if (m_Angle > 180)
            {
                m_Angle -= 360;
            }
            computeDirection();
        }
        if (Input::IsKeyPressed(GLFW_KEY_Q))
        {
            m_Angle-=m_RotateSpeed;
            if (m_Angle < -180)
            {
                m_Angle += 360;
            }
            computeDirection();
        }
    }

    void PerspectiveCamera::computeDirection() {
        m_Direction.x = cos(glm::radians(m_Angle));
        m_Direction.z = sin(glm::radians(m_Angle));
        m_Direction = glm::normalize(m_Direction);
    }
}