#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "intcode.hpp"

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
  auto data = loadInput("input");

  data[1] = 12;
  data[2] = 2;

  aoc::Intcode intcode(std::move(data));

  intcode.run();
  intcode.display();

  return 0;
}