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
//  auto data = loadInput("input");

//  data[1] = 12;
//  data[2] = 2;
//
//  aoc::Intcode intcode(std::move(data));
//
//  intcode.run();
//  intcode.display();

  auto data = loadInput("input");
  aoc::Intcode intcode(data);

  for(int noun = 0; noun < std::numeric_limits<int>::max(); ++noun) {
    for (int verb = 0; verb < std::numeric_limits<int>::max(); ++verb) {
      intcode.setValue(1, noun);
      intcode.setValue(2, noun);

    }
  }

  return 0;
}