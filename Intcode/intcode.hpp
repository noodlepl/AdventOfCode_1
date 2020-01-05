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
    Intcode(std::vector<int> program);

    void run();
    void display();
    int getValue(int index);

  private:
    void setValue(int index, int value);
    void execAdd(int instr_ptr);
    void execMultiply(int instr_ptr);

  private:
    std::vector<int> program_;
  };
}


#endif //ADVENTOFCODE_INTCODE_HPP
