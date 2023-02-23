#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include "loglevel.hpp"

#include <string>

namespace anjk
{

    class ILogger
    {
    public:
        virtual ~ILogger() = default;
        virtual void log(const LogLevel& level, const std::string& msg) = 0;
        std::string operator<<(const std::string& msg) { return msg; }
    };

}

#endif