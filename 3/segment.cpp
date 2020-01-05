//
// Created by Adam Kępiński on 2020-01-05.
//

#include "segment.hpp"

namespace aoc {
constexpr Segment::Segment(const Point& first, const Point& second) : first_(first), second_(second) {}

constexpr Point Segment::getFirst() const noexcept {
  return first_;
}

constexpr Point Segment::getSecond() const noexcept {
  return second_;
}

}
