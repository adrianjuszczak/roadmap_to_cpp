#ifndef CONSOLELOGGER_HPP
#define CONSOLELOGGER_HPP

#include "ilogger.hpp"

#include <iostream>

namespace anjk {

    class ConsoleLogger final : public ILogger {

        ~ConsoleLogger() override;

        void log(const LogLevel& level, const std::string& msg);
        std::string operator<<(const std::string& msg) { return msg; }
    }; 


}

#endif