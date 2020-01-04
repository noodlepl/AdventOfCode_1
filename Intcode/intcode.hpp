//
// Created by Adam Kępiński on 2020-01-04.
//

#ifndef ADVENTOFCODE_INTCODE_HPP
#define ADVENTOFCODE_INTCODE_HPP

#include <vector>
namespace aoc {
  class Intcode {
  public:
    Intcode(std::vector<int> program);

    void run();
    void display();

  private:
    std::vector<int> program_;
  };
}


#endif //ADVENTOFCODE_INTCODE_HPP
