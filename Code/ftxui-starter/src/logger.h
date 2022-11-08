#pragma once
#include <sstream>
#include <string>
#include <vector>

class Logger {
 public:
  static std::string message;
  static std::vector<std::string> messages;

 public:
  static void log(std::string message);
  static std::string getMsg();
};