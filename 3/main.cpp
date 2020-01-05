#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "segment.hpp"

std::vector<int> loadInput(const std::string& path) {
  std::ifstream fs(path);
  std::vector<int> result;

  if (fs.is_open()) {
    while (fs.good()) {
      std::string numAsString;
      std::getline(fs, numAsString, ',');
      const int num = std::stoi(numAsString);
      std::cout << num << ",";
      result.push_back(num);
    }
    std::cout << std::endl;
  }

  fs.close();

  return result;
}

using namespace aoc;

int main() {
  Segment segment(Point(0, 0), Point(1, 2));
  segment.getFirst();
}