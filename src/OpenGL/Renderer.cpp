#include "Renderer.h"

#include <iostream>

void Renderer::Clear() const{
    glClear( GL_COLOR_BUFFER_BIT );
}

void Renderer::Draw(const VertexArray& va, const Shader& shader) const
{
        shader.Bind();
        // shader.SetUniform4f("u_Color" r, 0.5f, 0.0f, 1.0f);
        va.Bind();

        glDrawElements(GL_TRIANGLES, va.GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
}