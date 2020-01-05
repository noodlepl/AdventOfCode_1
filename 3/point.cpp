//
// Created by Adam Kępiński on 2020-01-05.
//

#include "point.hpp"

namespace aoc {
  constexpr Point::Point(int x, int y) noexcept : x_(x), y_(y) {}

  constexpr int Point::x() const noexcept {
    return x_;
  }

constexpr int Point::y() const noexcept {
  return y_;
}
}