#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "glm/glm.hpp"

namespace Expine
{
    std::shared_ptr<spdlog::logger> Log::s_Logger;

    void Log::Init() 
    {
        s_Logger = spdlog::stderr_color_mt("Expine");
    }
}