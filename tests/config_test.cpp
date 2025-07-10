#include "core/config.hpp"

#include <gtest/gtest.h>

TEST(ConfigTest, DefaultConfig) {
  cms::Config config;

  EXPECT_EQ(config.get("default_setting"), "default_value");
}

TEST(ConfigTest, LoadFromFile) {
  cms::Config config;

  ASSERT_TRUE(config.loadFromFile("config-sample.env"));

  EXPECT_EQ(config.get("DB_HOST"), "localhost");
  EXPECT_EQ(config.get("DB_USER"), "cms");
  EXPECT_EQ(config.get("SITE_NAME"), "My CMS Site");
}

TEST(ConfigTest, GetNonExistentKey) {
  cms::Config config;

  ASSERT_THROW(config.get("non_existent_key"), std::runtime_error);
}

TEST(ConfigTest, SetAndGetKey) {
  cms::Config config;

  config.set("new_key", "new_value");
  EXPECT_EQ(config.get("new_key"), "new_value");

  config.set("new_key", "updated_value");
  EXPECT_EQ(config.get("new_key"), "updated_value");

  config.set("new_key", "final_value");
  EXPECT_EQ(config.get("new_key"), "final_value");

  config.saveToFile("test_config.env");
  cms::Config newConfig;
  ASSERT_TRUE(newConfig.loadFromFile("test_config.env"));
  EXPECT_EQ(newConfig.get("new_key"), "final_value");
  remove("test_config.env");
}
