#pragma once

#include <string>
#include <unordered_map>

namespace cms {
class Config {
 public:
  Config();

  bool loadFromFile(const std::string& filename);
  std::string get(const std::string& key) const;
  void set(const std::string& key, const std::string& value);
  void saveToFile(const std::string& filename) const;

 private:
  std::unordered_map<std::string, std::string> settings_;
};
}  // namespace cms
