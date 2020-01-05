//
// Created by Adam Kępiński on 2020-01-05.
//

#include "wire.hpp"
#include <iostream>

namespace aoc {
namespace {
  int distanceToSegmentEnd(const Segment& segment, const Point& point) {
    assert(point.x() == segment.second().x() || point.y() == segment.second().y());

    return std::max(std::abs(point.x() - segment.second().x()),
                    std::abs(point.y() - segment.second().y()));
  }
}
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
      auto segment_intersections = getIntersections(segment_data);
      for (auto&& point : segment_intersections) {
        intersections.push_back(point);
      }
    }

    return intersections;
  }

  std::vector<Wire::IntersectionData> Wire::getIntersections(const SegmentData& test_segment) {
    std::vector<IntersectionData> intersections;
    for(auto&& wire_seg : segments_) {
      if (wire_seg.segment.crosessWith(test_segment.segment)) {
        if (wire_seg.segment.first().x() == wire_seg.segment.second().x() &&
            test_segment.segment.first().y() == test_segment.segment.second().y()) {
          Point intersection(wire_seg.segment.first().x(), test_segment.segment.first().y());

          const int dist_test_segment = test_segment.distance_from_origin - distanceToSegmentEnd(test_segment.segment, intersection);
          const int dist_wire_segment = wire_seg.distance_from_origin - distanceToSegmentEnd(wire_seg.segment, intersection);
          if (dist_test_segment + dist_wire_segment > 0)
            intersections.emplace_back(intersection, dist_test_segment + dist_wire_segment);
        } else if (wire_seg.segment.first().y() == wire_seg.segment.second().y() &&
                   test_segment.segment.first().x() == test_segment.segment.second().x()) {
          Point intersection(test_segment.segment.first().x(), wire_seg.segment.first().y());

          const int dist_test_segment = test_segment.distance_from_origin - distanceToSegmentEnd(test_segment.segment, intersection);
          const int dist_wire_segment = wire_seg.distance_from_origin - distanceToSegmentEnd(wire_seg.segment, intersection);

          if (dist_test_segment + dist_wire_segment > 0)
            intersections.emplace_back(intersection, dist_test_segment + dist_wire_segment);
        } else {
          std::cerr << "Segments not perpendicular!";
        }
      }
    }

    return intersections;
  }

}