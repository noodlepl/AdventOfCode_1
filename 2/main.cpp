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
  aoc::Intcode intcode;
  bool done = false;
  constexpr int target = 19690720;

  for(int noun = 0; noun < data.size(); ++noun) {
    for (int verb = 0; verb < data.size(); ++verb) {
      std::cout << "noun=" << noun << " verb=" << verb << std::endl;
      intcode.loadProgram(data);
      intcode.setValue(1, noun);
      intcode.setValue(2, verb);
      intcode.run();
      if (intcode.getValue(0) == target) {
        done = true;
        std::cout << "Finished! Noun = " << noun << ", verb = " << verb << std::endl;
        break;
      }
    }
    if (done) {
      break;
    }
  }

  return 0;
}