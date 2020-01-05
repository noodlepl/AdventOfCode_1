//
// Created by Adam Kępiński on 2020-01-05.
//

#ifndef ADVENTOFCODE_SEGMENT_HPP
#define ADVENTOFCODE_SEGMENT_HPP

#include "point.hpp"
namespace aoc{
class Segment {
public:
  Segment(Point first, Point second);

private:
  Point first_;
  Point second_;
};
}


#endif //ADVENTOFCODE_SEGMENT_HPP
