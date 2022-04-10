#include "Camera.h"
#include "Input.h"


namespace Expine
{
    PerspectiveCamera::PerspectiveCamera(): m_Position(glm::vec3(0.0f)), m_Direction(glm::vec3(0.f,0.f,-1.f)), m_Up(glm::vec3(0.0f,1.0f,0.f))
    {
        
    }
    
    void PerspectiveCamera::SetPosition(float x, float y, float z)
    {
       m_Position.x = x; 
       m_Position.y = y; 
       m_Position.z = z; 
    }
    
    glm::mat4 PerspectiveCamera::GetMatrix()
    {
        return glm::lookAt(m_Position,m_Direction,m_Up);
    }

    void PerspectiveCamera::OnUpdate() {
        if( Input::IsKeyPressed(GLFW_KEY_W) ) {
            m_Position += m_Direction;
        }
        if( Input::IsKeyPressed(GLFW_KEY_S) ) {
            m_Position -= m_Direction;
        }
    }
}