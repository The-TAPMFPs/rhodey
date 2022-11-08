#include "logger.h"

std::vector<std::string> Logger::messages = {"ACTIONS WILL APPEAR HERE"};
std::string Logger::message = "ACTIONS WILL APPEAR HERE";

void Logger::log(std::string message)
{
    // Logger::messages.push_back(message);
    Logger::message = message;
}

std::string Logger::getMsg()
{
    // std::string toReturn = Logger::messages.back();
    std::string toReturn = Logger::message;
    return toReturn;
}
