#pragma once

#include <memory>
#include "Expine.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Shader.h"
#include "IndexBuffer.h"
#include "Texture.h"

using namespace Expine;
class SandBox : public Application
{
public:
    SandBox(const std::string& name);
    virtual void OnUpdate() override;

    float positions[16] = {
        100.0f, 100.0f, 0.0f, 0.0f,
        200.0f, 100.0f, 1.0f, 0.0f,
        200.0f, 200.0f, 1.0f, 1.0f,
        100.0f, 200.0f, 0.0f, 1.0f,
    };

    unsigned int indices[6] = {
        0, 1, 2,
        2, 3, 0,
    };

    std::shared_ptr<VertexArray> m_Va;
    std::shared_ptr<VertexBuffer> m_Vb;
    std::shared_ptr<IndexBuffer> m_Ib;
    std::shared_ptr<Shader> m_Shader;
    std::shared_ptr<Texture> m_Texture;
};