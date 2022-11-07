#include "logger.h"

std::string Logger::message = "ACTIONS WILL APPEAR HERE";

void Logger::log(std::string message)
{
    Logger::message += message;
}

std::string Logger::getMsg()
{
    std::string toReturn = Logger::message;
    Logger::message = "";
    return toReturn;
}
