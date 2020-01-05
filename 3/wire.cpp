//
// Created by Adam Kępiński on 2020-01-05.
//

#include "wire.hpp"
#include <iostream>

namespace aoc {
  const Segment& Wire::goRight(int steps) {
    const Point first = segments_.empty() ? Point(0, 0) : segments_.back().second();
    const Point second(first.x() + steps, first.y());

    return segments_.emplace_back(first, second);
  }

  const Segment& Wire::goLeft(int steps) {
    const Point first = segments_.empty() ? Point(0, 0) : segments_.back().second();
    const Point second(first.x() - steps, first.y());

    return segments_.emplace_back(first, second);
  }

  const Segment& Wire::goUp(int steps) {
    const Point first = segments_.empty() ? Point(0, 0) : segments_.back().second();
    const Point second(first.x(), first.y() + steps);

    return segments_.emplace_back(first, second);
  }

  const Segment& Wire::goDown(int steps) {
    const Point first = segments_.empty() ? Point(0, 0) : segments_.back().second();
    const Point second(first.x(), first.y() - steps);

    return segments_.emplace_back(first, second);
  }

  std::vector<Point> Wire::getIntersections(const Wire& other_wire) {
    std::vector<Point> intersections;
    for (auto&& segment : other_wire.segments_) {
      auto segment_intersections = getIntersections(segment);
      for (auto&& point : segment_intersections) {
        intersections.push_back(point);
      }
    }

    return intersections;
  }

  std::vector<Point> Wire::getIntersections(const Segment &segment) {
    std::vector<Point> intersections;
    for(auto&& wire_seg : segments_) {
      if (wire_seg.crosessWith(segment)) {
        if (wire_seg.first().x() == wire_seg.second().x() && segment.first().y() == segment.second().y()) {
          intersections.emplace_back(wire_seg.first().x(), segment.first().y());
        } else if (wire_seg.first().y() == wire_seg.second().y() && segment.first().x() == segment.second().x()) {
          intersections.emplace_back(segment.first().x(), wire_seg.first().y());
        } else {
          std::cerr << "Segments not perpendicular!";
        }
      }
    }

    return intersections;
  }

}