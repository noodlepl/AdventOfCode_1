//
// Created by Adam Kępiński on 2020-01-04.
//

#ifndef ADVENTOFCODE_INTCODE_HPP
#define ADVENTOFCODE_INTCODE_HPP

#include <vector>
#include <optional>

namespace aoc {
  class Intcode {
  public:
    Intcode() = default;
    Intcode(std::vector<int> program);

    void run();
    void display() const;
    int getValue(int index) const;
    void setValue(int index, int value);
    void loadProgram(std::vector<int> program);

  private:
    void execAdd(int instr_ptr);
    void execMultiply(int instr_ptr);
    void execInput(int instr_ptr);
    void execOutput(int instr_ptr);

  private:
    std::vector<int> program_;
  };
}


#endif //ADVENTOFCODE_INTCODE_HPP
