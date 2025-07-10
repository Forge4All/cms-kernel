#include <iostream>

#include "core/kernel.hpp"

int main() {
  cms::Kernel kernel;
  kernel.start();

  kernel.stop();

  return 0;
}
