#ifndef DEBUGHANDLING
#define DEBUGHANDLING

#include <iostream>
#include <string>
#include "timeclass.h"

enum LogLevel {
    Error = 0,
    Warning,
    Information
};

extern void registerLogGameTime(Time* p_LogGameTime);
extern void unregisterLogGameTime();

extern void printLogMessage(std::string message);

extern void printError(std::string message);

extern void printWarning(std::string message);

extern void printInformation(std::string message);

#endif // DEBUGHANDLING

