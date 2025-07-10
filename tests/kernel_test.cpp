#include "core/kernel.hpp"

#include <gtest/gtest.h>

TEST(KernelTest, StartsAndStopsCorrectly) {
  cms::Kernel kernel;

  EXPECT_FALSE(kernel.isRunning());

  kernel.start();
  EXPECT_TRUE(kernel.isRunning());

  kernel.stop();
  EXPECT_FALSE(kernel.isRunning());

  kernel.restart();
  EXPECT_TRUE(kernel.isRunning());
  kernel.stop();
  EXPECT_FALSE(kernel.isRunning());
}
