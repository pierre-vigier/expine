#pragma once

#include "VertexArray.h"
#include "Shader.h"

namespace Expine {
    class RenderAPI
    {
    public:
        enum class API
        {
            OpenGL = 0
        };
    public:
        // virtual void SetClearColor()
        virtual void Clear() const = 0;
        virtual void Draw(const VertexArray& va, const Shader& shader) = 0;

        inline static API GetAPI() { return s_API; }
    private:
        static API s_API;
    };
}