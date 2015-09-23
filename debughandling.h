#ifndef DEBUGHANDLING
#define DEBUGHANDLING

#include <iostream>
#include <string>
#include <SFML/System/Time.hpp>

enum LogLevel {
    Error = 0,
    Warning,
    Information
};

extern void registerLogGameTime(sf::Time* p_LogGameTime);
extern void unregisterLogGameTime();

extern void printLogMessage(std::string message);

extern void printError(std::string message);

extern void printWarning(std::string message);

extern void printInformation(std::string message);

#endif // DEBUGHANDLING

