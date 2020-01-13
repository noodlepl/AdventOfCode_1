#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <map>

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

bool anyDoubles(const std::vector<int> &digits) {
  assert(digits.size() >= 2);

  auto next = digits.cbegin() + 1;
  return std::any_of(digits.cbegin(), digits.cend() - 1, [&next](int current){
    const bool are_equal = current == *next;
    ++next;
    return are_equal;
  });
}

bool anyDoubleOnly(const std::vector<int> &digits) {
  assert (digits.size() >= 0);

  auto prev = digits.cbegin();
  auto it = prev + 1;
  bool double_only = false;
  int repeat_count = 0;

  for (;it < digits.cend(); ++prev, ++it) {
    if (*it == *prev) {
      ++repeat_count;
      if (double_only) double_only = false;
    } else {
      repeat_count = 0;
      if (double_only) break;
    }

    if (repeat_count == 1) {
      double_only = true;
    }
  }

  return double_only;
}

bool isNotDecreasing(const std::vector<int>& digits) {
  assert(digits.size() >= 2);
  auto next = digits.cbegin() + 1;

  return std::all_of(digits.cbegin(), digits.cend() - 1, [&next](int current){
    const bool is_not_decreasing = *next >= current;
    ++next;
    return is_not_decreasing;
  });
}

int main() {
  int count = 0;

  for (int test_num = kMinRange; test_num <= kMaxRange; ++test_num) {
    std::vector<int> num_digits;
    num_digits.reserve(6);
    collectDigits(num_digits, test_num);
    bool doubles_only = anyDoubleOnly(num_digits);
    bool not_decreasing = isNotDecreasing(num_digits);
    if (doubles_only && not_decreasing) {
      ++count;
    }
  }

  std::cout << "Answer: " << count << "\n";


  return 0;
}