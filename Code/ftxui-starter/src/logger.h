#pragma once
#include <sstream>
#include <string>
#include <vector>
struct Message{
    std::string str;
    Message * prev;
    bool alive;
    Message(std::string str,  Message * prev) {
	this->str = str;
	this->prev = prev;
	this->alive = true;
    };
};

class Logger {
 public:
  static Message * messageLogHistory [200];
  static int messageLogCounter;
  static Message * head;

 public:
  static void log(std::string message);
  static std::vector<std::string> getMsg();
};
