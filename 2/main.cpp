#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

  int pos = 0;
  bool run = true;

  while (run) {
    auto opcode = data[pos];
    auto numPos1 = 0;
    auto numPos2 = 0;
    auto resultPos = 0;

    switch(opcode) {
    case 1:
      numPos1 = data[pos + 1];
      numPos2 = data[pos + 2];
      resultPos = data[pos + 3];
      data[resultPos] = data[numPos1] + data[numPos2];
      std::cout << "Opcode 1: num[" << numPos1 << "](" << data[numPos1] << ") + num[" << numPos2 << "](" << data[numPos2] << ") = " << data[resultPos] << " at " << resultPos << std::endl;
      break;
    case 2:
      numPos1 = data[pos + 1];
      numPos2 = data[pos + 2];
      resultPos = data[pos + 3];
      data[resultPos] = data[numPos1] * data[numPos2];
      std::cout << "Opcode 2: num[" << numPos1 << "](" << data[numPos1] << ") * num[" << numPos2 << "](" << data[numPos2] << ") = " << data[resultPos] << " at " << resultPos << std::endl;
      break;
    case 99:
      run = false;
      break;
    default:
      std::cout << "Error opcode " << opcode << std::endl;
    }

    pos += 4;
  }

  for (auto num : data) {
    std::cout << num << ",";
  }

  return 0;
}