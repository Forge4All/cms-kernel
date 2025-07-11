#pragma once

#include "core/config.hpp"
#include "core/logger.hpp"

namespace cms {

class Kernel {
 public:
  Kernel(const std::string& configPath = "config.env");
  ~Kernel();

  bool start();
  void stop();
  bool isRunning() const;
  void restart();

 private:
  bool running_;
  std::string configPath_;
  Logger logger_;
  Config config_;
};

}  // namespace cms
