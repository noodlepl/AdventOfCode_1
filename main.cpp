#include <iostream>
#include <fstream>
#include <string>


int main() {
  std::ifstream input;
  input.open("input");
  if (input.is_open()) {
    std::string line;
    int accum = 0;
    while (std::getline(input, line)) {
      const int lineAsNum = std::stoi(line);
      std::cout << "Read input: " << lineAsNum << std::endl;
      accum += lineAsNum / 3 - 2;
      std::cout << "Accumulated fuel: " << accum << std::endl;
    }
  } else {
    std::cout << "Couldn't open file" << std::endl;
  }

  input.close();
  return 0;
}