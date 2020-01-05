//
// Created by Adam Kępiński on 2020-01-05.
//

#ifndef ADVENTOFCODE_WIRE_HPP
#define ADVENTOFCODE_WIRE_HPP

#include <vector>
#include "segment.hpp"

namespace aoc {
class Wire {
public:
  void goRight(int steps);
  void goLeft(int steps);
  void goUp(int steps);
  void goDown(int steps);

private:
  std::vector<Segment> segments_;
};
}


#endif //ADVENTOFCODE_WIRE_HPP
