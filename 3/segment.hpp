//
// Created by Adam Kępiński on 2020-01-05.
//

#ifndef ADVENTOFCODE_SEGMENT_HPP
#define ADVENTOFCODE_SEGMENT_HPP

#include "point.hpp"
namespace aoc{
class Segment {
public:
  constexpr Segment(const Point& first, const Point& second);

  constexpr Point getFirst() const noexcept;
  constexpr Point getSecond() const noexcept;

private:
  Point first_;
  Point second_;
};
}


#endif //ADVENTOFCODE_SEGMENT_HPP
