#include "core/kernel.hpp"

#include <iostream>

namespace cms {

Kernel::Kernel() : running(false) {}
Kernel::~Kernel() {
  if (running) {
    stop();
  }
}

void Kernel::start() {
  if (!running) {
    running = true;
    std::cout << "Kernel started." << std::endl;
  } else {
    std::cout << "Kernel is already running." << std::endl;
  }
}

void Kernel::stop() {
  if (running) {
    running = false;
    std::cout << "Kernel stopped." << std::endl;
  } else {
    std::cout << "Kernel is not running." << std::endl;
  }
}

void Kernel::restart() {
  if (running) {
    stop();
  }
  start();
}

bool Kernel::isRunning() const { return running; }

}  // namespace cms
