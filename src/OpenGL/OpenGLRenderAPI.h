#pragma once

#include <GL/glew.h>

#include <assert.h>

#include "Renderer/RenderAPI.h"
#include "VertexArray.h"
#include "Shader.h"
#include "IndexBuffer.h"

#define ASSERT(x) assert(x);

class OpenGLRenderAPI : public Expine::RenderAPI {
public:
    void Clear() const override;
    virtual void Draw(const VertexArray& va, const Shader& shader) override;
};