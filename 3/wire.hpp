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
  const Segment& goRight(int steps);
  const Segment& goLeft(int steps);
  const Segment& goUp(int steps);
  const Segment& goDown(int steps);

  // return points of perpendicular intersections
  std::vector<Point> isCrossedBy(const Segment& segment);

private:
  std::vector<Segment> segments_;
};
}


#endif //ADVENTOFCODE_WIRE_HPP
