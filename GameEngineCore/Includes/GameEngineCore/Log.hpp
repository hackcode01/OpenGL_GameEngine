#ifndef LOG_HPP
#define LOG_HPP

#include "spdlog/spdlog.h"

namespace GameEngine {
    #ifdef NDEBUG
        #define LOG_INFO(...)
        #define LOG_WARNING(...)
        #define LOG_ERROR(...)
        #define LOG_CRITICAL(...)
    #else
        #define LOG_INFO(...) spdlog::info(__VA_ARGS__)
        #define LOG_WARNING(...) spdlog::warn(__VA_ARGS__)
        #define LOG_ERROR(...) spdlog::error(__VA_ARGS__)
        #define LOG_CRITICAL(...) spdlog::critical(__VA_ARGS__)
    #endif
}

#endif
