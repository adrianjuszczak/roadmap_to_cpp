#include <iostream>
#include <memory>
#include <vector>

class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void getClassName() = 0;
};

class ScreenLogger : public ILogger {
public:
    void getClassName() override  {
        std::cout << "Screen Logger. \n";
    }
};

class FileLogger : public ILogger {
public:
    void getClassName() override {
        std::cout << "File Logger. \n";
    }
};

class LoggerType {
public:
    LoggerType(ILogger* logger)
        : m_logger{logger} {}

    private:
    ILogger* m_logger;
};

int
main()
{
    {
        std::vector<std::unique_ptr<ILogger>> loggers;
        loggers.push_back(std::make_unique<FileLogger>());

        
    }

}

