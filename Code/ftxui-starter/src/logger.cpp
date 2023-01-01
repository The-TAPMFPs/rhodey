#include "logger.h"
#include <sstream>

Message * Logger::messageLogHistory [200] = {NULL};
int Logger::messageLogCounter = 0;
Message * Logger::head = new Message("Start Of Simulation", NULL);

void Logger::log(std::string message)
{
    if (Logger::messageLogHistory[Logger::messageLogCounter%200] != NULL) {
	delete Logger::messageLogHistory[Logger::messageLogCounter%200];
	Logger::messageLogHistory[(Logger::messageLogCounter+1)%200]->prev = NULL;
	Logger::messageLogHistory[Logger::messageLogCounter%200] = new Message(message,
		    Logger::messageLogHistory[(Logger::messageLogCounter-1)%200]);
	Logger::head = Logger::messageLogHistory[Logger::messageLogCounter%200];
	Logger::messageLogCounter++;
    } else {
	Logger::messageLogHistory[Logger::messageLogCounter] = new Message(message,
		    Logger::messageLogHistory[Logger::messageLogCounter-1]);
	Logger::head = Logger::messageLogHistory[Logger::messageLogCounter%200];
	Logger::messageLogCounter++;
    }
}

std::vector<std::string> Logger::getMsg()
{
    Message * message = Logger::head;
    std::vector<std::string> toReturn;
    while (message != NULL && message->alive) {
	toReturn.push_back(message->str);
	message = message->prev;
    }
    return toReturn;
}
