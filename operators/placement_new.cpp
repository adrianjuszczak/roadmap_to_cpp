#include <iostream>
#include <string>

/**
 *  new - alokuje pamięc i tworzy tam obiekt
 *  placement new - pozwala na stworzenie obiektu pod wskazanym adresem
 *
 *  PLUSY, szybszy w tworzeniu obiektów, ponieważ pomija wstępną alokację
 *  mogę być przypadki, gdzie wymagana będzie wielokrotna rekonstrukcja obiektów
 */

class ILogger
{
public:
    ILogger()
    {
        std::cout << "ILogger CTOR. \n";
    }
    virtual ~ILogger()
    {
        std::cout << "ILogger DTOR. \n";
    }
    virtual void log() = 0;
};

class ConsoleLogger final : public ILogger
{
public:
    ConsoleLogger() : log_ctx{"default CTOR created"}
    {
        std::cout << "ConsoleLogger CTOR. \n";
    }
    ~ConsoleLogger() override
    {
        std::cout << "ConsoleLogger DTOR. \n";
    }
    void log() override
    {
        std::cout << "log: " << log_ctx << std::endl;
    }

private:
    std::string log_ctx;
};

char *buffer[sizeof(ILogger) * 2];

int main()
{
    ILogger *logger1 = new (&buffer[0 * sizeof(ILogger)]) ConsoleLogger();
    /**
     *  @note do not use delete on previous created buffer
     *  you can explicitly invoke destructor 
    */
    logger1->~ILogger();
}