#pragma once

#include <memory>
#include "spdlog/spdlog.h"

namespace Expine{
    class Log {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger;}
    private:
        static std::shared_ptr<spdlog::logger> s_Logger;
    };
}

#define XP_LOG_INFO(...) Expine::Log::GetLogger()->info(__VA_ARGS__)