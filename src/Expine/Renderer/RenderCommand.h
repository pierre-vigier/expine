#pragma once

#include "RenderAPI.h"

namespace Expine {
    class RenderCommand
    {
    public:
        inline static void Draw(const VertexArray& va, const Shader& shader) {
            s_RenderAPI->Draw(va, shader);
        }
    private:
        static RenderAPI* s_RenderAPI;
    };
}