#include <iostream>
#include <string>
#include <vector>
#include <cassert>

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

bool checkForDoubles(const std::vector<int>& digits) {
  assert(digits.size() >= 2);
  int prev = digits[0];
  for (int i = 1; i < digits.size(); ++i) {
    auto current = digits[i];
    if (current == prev)
      return true;
    prev = current;
  }
  
  return false;
}

bool isNotDecreasing(const std::vector<int>& digits) {
  assert(digits.size() >= 2);
  int prev = digits[0];
  for (int i = 1; i < digits.size(); ++i) {
    auto current = digits[i];
    if (current < prev)
      return false;
  }

  return true;
}

int main() {


  return 0;
}