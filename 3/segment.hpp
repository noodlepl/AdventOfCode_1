//
// Created by Adam Kępiński on 2020-01-05.
//

#ifndef ADVENTOFCODE_SEGMENT_HPP
#define ADVENTOFCODE_SEGMENT_HPP

#include <algorithm>
#include "point.hpp"

namespace aoc{
enum class Orientation{kClockwise, kAntiClockwise, kColinear};

constexpr Orientation orientation(const Point& p, const Point& q, const Point& r) noexcept {
  int val = (q.y() - p.y()) * (r.x() - q.x()) -
            (q.x() - p.x()) * (r.y() - q.y());

  if (val == 0) return Orientation::kColinear;

  return val > 0 ? Orientation::kClockwise : Orientation::kAntiClockwise;
}

class Segment {
public:
  constexpr Segment(const Point& first, const Point& second) noexcept : first_(first), second_(second) {}

  constexpr const Point& first() const noexcept {return first_;}
  constexpr const Point& second() const noexcept {return second_;}
  constexpr bool crosessWith(const Segment& other) const noexcept {
    Orientation o1 = orientation(first_, second_, other.first());
    Orientation o2 = orientation(first_, second_, other.second());
    Orientation o3 = orientation(other.first(), other.second(), first_);
    Orientation o4 = orientation(other.first(), other.second(), second_);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == Orientation::kColinear && contains(other.first())) return true;
    if (o2 == Orientation::kColinear && contains(other.second())) return true;
    if (o3 == Orientation::kColinear && other.contains(first_)) return true;
    if (o4 == Orientation::kColinear && other.contains(second_)) return true;

    return false;
  }

private:
  constexpr bool contains(const Point &point) const noexcept {
    return (point.x() <= std::max(first_.x(), second_.x()) && point.x() >= std::min(first_.x(), second_.x()) &&
            point.y() <= std::max(first_.y(), second_.y()) && point.y() >= std::min(first_.y(), second_.y()));
  }

private:
  Point first_;
  Point second_;
};
}


#endif //ADVENTOFCODE_SEGMENT_HPP
