#include "intcode.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

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

int main() {
  aoc::Intcode intcode(loadInput("input"));

  intcode.display();

  return 0;
}