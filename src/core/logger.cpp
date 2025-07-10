#include "core/logger.hpp"

#include <iostream>

namespace cms {
Logger::Logger() {}

void Logger::log(const std::string& message, LogLevel level) {
  switch (level) {
    case LogLevel::INFO:
      std::cout << "[INFO]: " << message << std::endl;
      break;
    case LogLevel::WARNING:
      std::cout << "[!WARNING!]: " << message << std::endl;
      break;
    case LogLevel::ERROR:
      std::cerr << "[#----!ERROR!----#]: " << message << std::endl;
      break;
  }
}

void Logger::info(const std::string& message) { log(message, LogLevel::INFO); }

void Logger::warning(const std::string& message) {
  log(message, LogLevel::WARNING);
}

void Logger::error(const std::string& message) {
  log(message, LogLevel::ERROR);
}

bool Logger::hasLogged(const std::string& message) {
  // This is a placeholder implementation.
  // In a real application, you would maintain a log history and check against
  // it. For now, we assume that if the message is logged, it has been recorded.
  return message.find("[INFO]:") != std::string::npos ||
         message.find("[!WARNING!]:") != std::string::npos ||
         message.find("[#----!ERROR!----#]:") != std::string::npos;
}
}  // namespace cms
