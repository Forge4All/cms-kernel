#include "core/logger.hpp"

#include <gtest/gtest.h>

TEST(LoggerTest, CanLogInfo) {
  cms::Logger logger;

  logger.info("This is an info message");
  ASSERT_TRUE(logger.hasLogged("[INFO]: This is an info message"));

  EXPECT_NO_THROW(logger.info("This is an info message"));
  EXPECT_NO_THROW(logger.warning("This is a warning message"));
  EXPECT_NO_THROW(logger.error("This is an error message"));
}
