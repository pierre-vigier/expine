#include "Renderer.h"

namespace Expine {
    void Renderer::Submit(const VertexArray& va, const Shader& shader)
    {
        RenderCommand::Draw(va,shader);
    }
}