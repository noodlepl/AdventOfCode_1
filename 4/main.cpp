#include <iostream>
#include <string>
#include <vector>

namespace {
constexpr int kMinRange = 372037;
constexpr int kMaxRange = 905157;
}

void collectDigits(std::vector<int>& digits, int num) {
  if (num > 9) {
    collectDigits(digits, num / 10);
  }
  digits.push_back(num % 10);
}

int main() {


  return 0;
}