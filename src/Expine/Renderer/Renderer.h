#pragma once

// #include "RenderAPI.h"
#include "RenderCommand.h"
#include "VertexArray.h"
#include "Shader.h"

namespace Expine {
	class Renderer
	{
	public:
        static void Submit(const VertexArray& va, const Shader& shader);
		// inline static RenderAPI::API GetAPI() { return RenderAPI::GetAPI(); }
	};
}
