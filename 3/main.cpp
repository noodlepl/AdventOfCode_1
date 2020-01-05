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

  const auto& first_wire_segments = wires[0].segments();

  for (auto&& segment : first_wire_segments) {

  }
}