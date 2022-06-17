#include <absl/status/status.h>
#include <iostream>

int main(int argc, char **argv) {
  absl::Status status = absl::OkStatus();

  std::cout << status << std::endl;
}
