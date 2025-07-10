#include "core/config.hpp"

#include <fstream>
#include <stdexcept>
#include <string>

namespace cms {
cms::Config::Config() { settings_["default_setting"] = "default_value"; }

bool Config::loadFromFile(const std::string& filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    return false;
  }

  std::string line;
  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '#') {
      continue;
    }

    size_t eq = line.find('=');
    if (eq == std::string::npos) {
      continue;
    }

    std::string key = line.substr(0, eq);
    std::string value = line.substr(eq + 1);
    settings_[key] = value;
  }

  file.close();
  return true;
}

std::string Config::get(const std::string& key) const {
  auto it = settings_.find(key);
  if (it != settings_.end()) {
    return it->second;
  }
  throw std::runtime_error("Key not found: " + key);
}

void Config::set(const std::string& key, const std::string& value) {
  settings_[key] = value;
}

void Config::saveToFile(const std::string& filename) const {
  std::ofstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file for writing: " + filename);
  }

  for (const auto& pair : settings_) {
    file << pair.first << "=" << pair.second << "\n";
  }

  file.close();
}

}  // namespace cms
