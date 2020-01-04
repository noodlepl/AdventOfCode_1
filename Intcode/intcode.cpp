//
// Created by Adam Kępiński on 2020-01-04.
//

#include "intcode.hpp"
#include <iostream>

namespace aoc {
Intcode::Intcode(std::vector<int> program) : program_(std::move(program)) {}

void Intcode::run() {
  int pos = 0;
  bool run = true;

  while (run) {
    auto opcode = program_[pos];
    auto numPos1 = 0;
    auto numPos2 = 0;
    auto resultPos = 0;

    switch(opcode) {
    case 1:
      numPos1 = program_[pos + 1];
      numPos2 = program_[pos + 2];
      resultPos = program_[pos + 3];
      program_[resultPos] = program_[numPos1] + program_[numPos2];
      std::cout << "Opcode 1: num[" << numPos1 << "](" << program_[numPos1] << ") + num[" << numPos2 << "](" << program_[numPos2] << ") = " << program_[resultPos] << " at " << resultPos << std::endl;
      break;
    case 2:
      numPos1 = program_[pos + 1];
      numPos2 = program_[pos + 2];
      resultPos = program_[pos + 3];
      program_[resultPos] = program_[numPos1] * program_[numPos2];
      std::cout << "Opcode 2: num[" << numPos1 << "](" << program_[numPos1] << ") * num[" << numPos2 << "](" << program_[numPos2] << ") = " << program_[resultPos] << " at " << resultPos << std::endl;
      break;
    case 99:
      run = false;
      break;
    default:
      std::cout << "Error opcode " << opcode << std::endl;
    }

    pos += 4;
  }
}

void Intcode::display() {
  for (auto num : program_) {
    std::cout << num << ",";
  }
}

}