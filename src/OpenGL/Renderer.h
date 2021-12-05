#pragma once

#include <GL/glew.h>

#include <assert.h>

#include "VertexArray.h"
#include "Shader.h"
#include "IndexBuffer.h"

#define ASSERT(x) assert(x);

class Renderer {
public:
    void Clear() const;
    void Draw(const VertexArray& va, const Shader& shader) const;
};