#pragma once

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
  bool running;
};

}  // namespace cms
