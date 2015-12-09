#include "debughandling.h"

static std::ostream& logStream = std::cout;
static LogLevel currentLogLevel = Information;
static Time* sp_LogGameTime = nullptr;

void registerLogGameTime(Time* p_LogGameTime)
{
    sp_LogGameTime = p_LogGameTime;
}

void unregisterLogGameTime()
{
    sp_LogGameTime = nullptr;
}

void printLogMessage(std::string message)
{
    if(nullptr!=sp_LogGameTime)
    {
        logStream << "[" << sp_LogGameTime->asSeconds() << "]";
    }
    logStream << message << std::endl;
}

void printError(std::string message)
{
    if((int)currentLogLevel <= (int)Error)
    {
        logStream << "[Error]";
        printLogMessage(message);
    }
}

void printWarning(std::string message)
{
    if((int)currentLogLevel <= (int)Warning)
    {
        logStream << "[Warning]";
        printLogMessage(message);
    }
}

void printInformation(std::string message)
{
    if((int)currentLogLevel <= (int)Information)
    {
        logStream << "[Information]";
        printLogMessage(message);
    }
}
