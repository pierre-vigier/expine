#include "RenderCommand.h"

#include "OpenGLRenderAPI.h"

namespace Expine {
    RenderAPI* RenderCommand::s_RenderAPI = new OpenGLRenderAPI();
}