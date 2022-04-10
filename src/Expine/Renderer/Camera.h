#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Expine {
    class PerspectiveCamera
    {
    public:
        PerspectiveCamera();

        void SetPosition(float x, float y, float z);

        glm::mat4 GetMatrix();

        void OnUpdate();
    private:
        glm::vec3 m_Position;
        glm::vec3 m_Direction;
        glm::vec3 m_Up;
    };
}