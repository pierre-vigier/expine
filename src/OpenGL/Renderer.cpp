#include "Renderer.h"

#include <iostream>

void Renderer::Clear() const{
    glClear( GL_COLOR_BUFFER_BIT );
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
        shader.Bind();
        // shader.SetUniform4f("u_Color", r, 0.5f, 0.0f, 1.0f);
        va.Bind();
        ib.Bind();

        glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}