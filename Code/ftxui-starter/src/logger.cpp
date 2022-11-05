#include "logger.h"

std::string Logger::message = "ACTIONS WILL APPEAR HERE";

void Logger::log(std::string message)
{
    Logger::message = message;
}

std::string Logger::getMsg()
{
    return Logger::message;
}