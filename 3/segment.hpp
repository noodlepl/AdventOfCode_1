//
// Created by Adam Kępiński on 2020-01-05.
//

#ifndef ADVENTOFCODE_SEGMENT_HPP
#define ADVENTOFCODE_SEGMENT_HPP

#include <algorithm>
#include "point.hpp"

namespace aoc{
enum class Orientation{kClockwise, kAntiClockwise, kColinear};

class Segment {
public:
  constexpr Segment(const Point& first, const Point& second) noexcept : first_(first), second_(second) {}

  constexpr Point getFirst() const noexcept {return first_;}
  constexpr Point getSecond() const noexcept {return second_;}
  constexpr bool crosessWith(const Segment& other) const noexcept {
    return true;
  }

private:
  constexpr bool onSegment(const Point& point) const noexcept {
    return (point.x() <= std::max(first_.x(), second_.x()) && point.x() >= std::min(first_.x(), second_.x()) &&
            point.y() <= std::max(first_.y(), second_.y()) && point.y() >= std::min(first_.y(), second_.y()));
  }
  constexpr Orientation orientation(const Point& point) const noexcept {
    int val = (point.y() - first_.y()) * (second_.x() - point.x()) -
              (point.x() - first_.x()) * (second_.y() - point.y());

    if (val == 0) return Orientation::kColinear;

    return val > 0 ? Orientation::kClockwise : Orientation::kAntiClockwise;
  }


private:
  Point first_;
  Point second_;
};
}


#endif //ADVENTOFCODE_SEGMENT_HPP
