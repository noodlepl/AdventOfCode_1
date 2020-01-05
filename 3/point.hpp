//
// Created by Adam Kępiński on 2020-01-05.
//

#ifndef ADVENTOFCODE_POINT_HPP
#define ADVENTOFCODE_POINT_HPP


namespace aoc {
class Point {
public:
  constexpr Point(int x, int y) noexcept;

  constexpr int x() const noexcept;
  constexpr int y() const noexcept;

private:
  int x_;
  int y_;
};
}


#endif // ADVENTOFCODE_POINT_HPP
