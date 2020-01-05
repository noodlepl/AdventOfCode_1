//
// Created by Adam Kępiński on 2020-01-05.
//

#ifndef ADVENTOFCODE_WIRE_HPP
#define ADVENTOFCODE_WIRE_HPP

#include <vector>
#include "segment.hpp"

namespace aoc {
class Wire {
public:
  struct SegmentData {
    SegmentData(const Point& first, const Point& second, int distance) : segment(first, second), distance_from_origin(distance){}
    Segment segment;
    int distance_from_origin;
  };

  struct IntersectionData {
    IntersectionData(const Point& point, int distance) : intersection(point), total_distance_from_origin(distance) {}
    Point intersection;
    int total_distance_from_origin;
  };

  void goRight(int steps);
  void goLeft(int steps);
  void goUp(int steps);
  void goDown(int steps);

  // return points of perpendicular intersections
  std::vector<IntersectionData> getIntersections(const SegmentData& test_segment);
  std::vector<IntersectionData> getIntersections(const Wire& other_wire);

private:
  std::vector<SegmentData> segments_;
};
}


#endif //ADVENTOFCODE_WIRE_HPP
