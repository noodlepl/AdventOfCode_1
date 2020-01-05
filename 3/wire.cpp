//
// Created by Adam Kępiński on 2020-01-05.
//

#include "wire.hpp"
#include <iostream>

namespace aoc {
  void Wire::goRight(int steps) {
    const Point first = segments_.empty() ? Point(0, 0) : segments_.back().segment.second();
    const Point second(first.x() + steps, first.y());
    const int current_distance = segments_.empty() ? 0 : segments_.back().distance_from_origin;

    segments_.emplace_back(first, second, current_distance + steps);
  }

  void Wire::goLeft(int steps) {
    const Point first = segments_.empty() ? Point(0, 0) : segments_.back().segment.second();
    const Point second(first.x() - steps, first.y());
    const int current_distance = segments_.empty() ? 0 : segments_.back().distance_from_origin;

    segments_.emplace_back(first, second, current_distance + steps);
  }

  void Wire::goUp(int steps) {
    const Point first = segments_.empty() ? Point(0, 0) : segments_.back().segment.second();
    const Point second(first.x(), first.y() + steps);
    const int current_distance = segments_.empty() ? 0 : segments_.back().distance_from_origin;

    segments_.emplace_back(first, second, current_distance + steps);
  }

  void Wire::goDown(int steps) {
    const Point first = segments_.empty() ? Point(0, 0) : segments_.back().segment.second();
    const Point second(first.x(), first.y() - steps);
    const int current_distance = segments_.empty() ? 0 : segments_.back().distance_from_origin;

    segments_.emplace_back(first, second, current_distance + steps);
  }

  std::vector<Wire::IntersectionData> Wire::getIntersections(const Wire& other_wire) {
    std::vector<Wire::IntersectionData> intersections;
    for (auto&& segment_data : other_wire.segments_) {
      auto segment_intersections = getIntersections(segment_data.segment);
      for (auto&& point : segment_intersections) {
        const int intersection_to_segment_end = std::max(std::abs(point.x() - segment_data.segment.second().x()),
            std::abs(point.y() - segment_data.segment.second().y()));
        int intersection_distance = segment_data.distance_from_origin - intersection_to_segment_end;
        intersections.emplace_back(point, intersection_distance);
      }
    }

    return intersections;
  }

  std::vector<Point> Wire::getIntersections(const Segment& test_segment) {
    std::vector<Point> intersections;
    for(auto&& wire_seg : segments_) {
      if (wire_seg.segment.crosessWith(test_segment)) {
        if (wire_seg.segment.first().x() == wire_seg.segment.second().x() && test_segment.first().y() == test_segment.second().y()) {
          intersections.emplace_back(wire_seg.segment.first().x(), test_segment.first().y());
        } else if (wire_seg.segment.first().y() == wire_seg.segment.second().y() && test_segment.first().x() == test_segment.second().x()) {
          intersections.emplace_back(test_segment.first().x(), wire_seg.segment.first().y());
        } else {
          std::cerr << "Segments not perpendicular!";
        }
      }
    }

    return intersections;
  }

}