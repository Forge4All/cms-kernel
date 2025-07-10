#pragma once

#include <string>

namespace cms {

class Logger {
 public:
  enum class LogLevel { INFO, WARNING, ERROR };

  Logger();

  void log(const std::string& message, LogLevel level = LogLevel::INFO);

  void info(const std::string& message);
  void warning(const std::string& message);
  void error(const std::string& message);

  bool hasLogged(const std::string& message);
};

}  // namespace cms
