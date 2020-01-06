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
    prev = current;
  }

  return true;
}

int main() {
  int count = 0;

  for (int test_num = kMinRange; test_num <= kMaxRange; ++test_num) {
    std::vector<int> num_digits;
    num_digits.reserve(6);
    collectDigits(num_digits, test_num);
    bool doubles = checkForDoubles(num_digits);
    bool not_decreasing = isNotDecreasing(num_digits);
    if (doubles && not_decreasing) {
      ++count;
    }
  }

  std::cout << "Answer: " << count << "\n";

  return 0;
}