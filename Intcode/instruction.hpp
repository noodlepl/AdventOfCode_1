//
// Created by Adam Kępiński on 2020-01-13.
//

#ifndef ADVENTOFCODE_INSTRUCTION_HPP
#define ADVENTOFCODE_INSTRUCTION_HPP

#include <vector>

namespace aoc {
class Instruction {
public:
  Instruction(const std::vector<int>& program, int instr_ptr);

private:
  int opcode;
  std::vector<int> parameters_modes;
};
}


#endif // ADVENTOFCODE_INSTRUCTION_HPP
