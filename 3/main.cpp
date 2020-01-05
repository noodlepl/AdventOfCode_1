#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "segment.hpp"
#include "wire.hpp"

using namespace aoc;

std::vector<Wire> loadInput(const std::string& path) {
  std::ifstream fs(path);
  std::vector<Wire> wires;

  if (fs.is_open()) {
    while (fs.good()) {
      std::string line;
      std::getline(fs, line);

      std::stringstream line_stream(line);
      std::string cell;

      Wire wire;

      while (std::getline(line_stream, cell, ',')) {
        assert(cell.size() > 1);
        const int steps = std::stoi(cell.substr(1));
        switch(cell[0]) {
        case 'R':
          wire.goRight(steps);
          break;
        case 'L':
          wire.goLeft(steps);
          break;
        case 'U':
          wire.goUp(steps);
          break;
        case 'D':
          wire.goDown(steps);
          break;
        default:
          std::cerr << "Unkown instruction " << cell << std::endl;
        }
      }

      wires.push_back(std::move(wire));
    }
    std::cout << std::endl;
  }

  fs.close();

  return wires;
}

int main() {
  auto wires = loadInput("input");

  auto intersections1 = wires[0].getIntersections(wires[1]);
  auto intersections2 = wires[1].getIntersections(wires[0]);

  assert(intersections1.size() == intersections2.size());
  const auto vec_size = intersections1.size();
  std::vector<int> summed_distances;
  summed_distances.reserve(vec_size);

  for (int i = 0; i < vec_size; ++i) {
    const auto summed_distance = intersections1[i].total_distance_from_origin +
                                 intersections2[i].total_distance_from_origin;
    if (summed_distance != 0)
      summed_distances.push_back(summed_distance);
  }

  int min_distance = summed_distances[0];
  for(auto&& dist : summed_distances) {
    min_distance = std::min(min_distance, dist);
  }

  std::cout << "Fewest steps to intersection is " << min_distance  << std::endl;

//  if (intersections.size() > 0) {
//    const Point origin(0, 0);
//    int min_distance = intersections[0].manhattanDistance(origin);
//    for (auto&& point : intersections) {
//      auto distance = point.manhattanDistance(origin);
//      min_distance = std::min(min_distance, distance);
//    }
//
//    std::cout << "Closest intersection is " << min_distance << " away." << std::endl;
//  } else {
//    std::cerr << "No intersections found" << std::endl;
//  }

  return 0;
}