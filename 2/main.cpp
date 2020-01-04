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
      std::cout << num << std::endl;
      result.push_back(num);
    }
  }

  fs.close();
  
  return result;
}

int main() {
  loadInput("input");
  return 0;
}