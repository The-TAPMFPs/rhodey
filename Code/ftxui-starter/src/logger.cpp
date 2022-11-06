#include "logger.h"

/**
 * \property Logger::message
 * \brief The First Message of the Simulation log
 */
std::string Logger::message = "ACTIONS WILL APPEAR HERE";


/**
 * \fn void Logger::log (std::string message)
 * \brief logs a message to the simulation log
 *
 * \param message the message to be logged
 */
void Logger::log(std::string message)
{
    Logger::message = message;
}

/**
 * \fn std::string Logger::getMsg ()
 * \brief gets the current message of the simulation log
 *
 * \return the current message of the simulation log
 */
std::string Logger::getMsg()
{
    return Logger::message;
}