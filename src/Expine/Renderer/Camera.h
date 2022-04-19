#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Event.h"

namespace Expine {
    class PerspectiveCamera
    {
    public:
        PerspectiveCamera();

        void SetPosition(float x, float y, float z);

        glm::mat4 GetMatrix();

        void OnUpdate(float elapsed);

        void HandleEvent(Event &e);
    private:
        void computeDirection();

        glm::mat4 m_Projection;
        glm::vec3 m_Position;
        glm::vec3 m_Direction;
        glm::vec3 m_Up;
        float m_MoveSpeed = 1.0f;
        float m_RotateSpeed = 30.0f;
        float m_Sensitivity = 0.1f;
        float m_Yaw = 90.f;
        float m_Pitch = 0.f;
    };
}