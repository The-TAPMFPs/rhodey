#pragma once
#include <sstream>
#include <string>

class Logger {
 public:
  static std::string message;

 public:
  static void log(std::string message);
  static std::string getMsg();
};