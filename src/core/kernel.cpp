#include "core/kernel.hpp"

#include <iostream>

#include "core/logger.hpp"

namespace cms {

Kernel::Kernel() : running_(false) {}
Kernel::~Kernel() {
  if (running_) {
    stop();
  }
}

void Kernel::start() {
  if (!running_) {
    running_ = true;
    logger_.info("Kernel started.");
  } else {
    logger_.warning("Kernel is already running.");
  }
}

void Kernel::stop() {
  if (running_) {
    running_ = false;
    logger_.info("Kernel stopped.");
  } else {
    logger_.warning("Kernel is not running.");
  }
}

void Kernel::restart() {
  if (running_) {
    stop();
  }
  start();
  logger_.info("Kernel restarted.");
}

bool Kernel::isRunning() const { return running_; }

}  // namespace cms
