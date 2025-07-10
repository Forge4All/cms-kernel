#pragma once

#include "core/logger.hpp"

namespace cms {

class Kernel {
 public:
  Kernel();
  ~Kernel();

  void start();
  void stop();
  bool isRunning() const;
  void restart();

 private:
  bool running_;

  Logger logger_;
};

}  // namespace cms
