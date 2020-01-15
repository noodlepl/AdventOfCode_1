//
// Created by Adam Kępiński on 2020-01-04.
//

#include "intcode.hpp"
#include <iostream>
#include <exception>
#include <sstream>
#include <cassert>

namespace aoc {

namespace {
enum Opcode {
  ADD = 1,
  MULTIPLY = 2,
  INPUT = 3,
  OUTPUT = 4,
  HALT = 99,
};

class ProgramExecutor {
public:
  ProgramExecutor(std::vector<int> program) : program_(program) {}

  class iterator {
  public:
    using value_type = int;
    using reference = int&;
    using pointer = int*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    iterator(std::vector<int>::iterator it) : current_(it) {}

    reference operator*() {return *current_;}
    pointer operator->() {return &**this;}

    iterator& operator++() {
      // TODO: Parse opcodes
      current_ += instruction_step(static_cast<Opcode>(*current_));
      return *this;
    }
    iterator operator++(int) {
      const auto temp(*this);
      ++*this;
      return temp;
    }

  private:
    int instruction_step(Opcode opcode) {
      switch(opcode) {
      case ADD:
      case MULTIPLY:
        return 4;
      case INPUT:
      case OUTPUT:
      case HALT:
        return 2;
      }
    }

  private:
    std::vector<int>::iterator current_;
  };

  iterator begin() {return iterator(program_.begin());};
  iterator end() {return iterator(program_.end());};

private:
  std::vector<int> program_;
};

}

Intcode::Intcode(std::vector<int> program) : program_(std::move(program)) {}

void Intcode::run() {
  int instr_ptr = 0;
  bool run = true;

  try {
    while (run) {

      auto opcode = getValue(instr_ptr);

      switch(opcode) {
      case ADD:
        execAdd(instr_ptr);
        break;
      case MULTIPLY:
        execMultiply(instr_ptr);
        break;
      case HALT:
        run = false;
        break;
      default:
        std::cout << "Error opcode " << opcode << std::endl;
      }

      instr_ptr += 4;
    }
  } catch(const std::exception& ex) {
    std::cerr << "Exception occured. " << ex.what() << std::endl;
  }
}

void Intcode::display() const {
  for (auto num : program_) {
    std::cout << num << ",";
  }
}

int Intcode::getValue(int index) const {
  if (index >= program_.size()) {
    std::stringstream msg;
    msg << "Couldn't get value from position " << index << ". Size of program is " << program_.size();
    throw std::invalid_argument(msg.str());
  }
  return program_[index];
}

void Intcode::execAdd(int instr_ptr) {
  assert (getValue(instr_ptr) == ADD);

  int numPos1 = getValue(instr_ptr + 1);
  int numPos2 = getValue(instr_ptr + 2);
  int resultPos = getValue(instr_ptr + 3);
  setValue(resultPos, getValue(numPos1) + getValue(numPos2));

//  std::cout << "Opcode 1: num[" << numPos1 << "](" << program_[numPos1] << ") + num[" << numPos2 << "](" << program_[numPos2] << ") = " << program_[resultPos] << " at " << resultPos << std::endl;
}

void Intcode::execMultiply(int instr_ptr) {
  assert (getValue(instr_ptr) == MULTIPLY);

  int numPos1 = program_[instr_ptr + 1];
  int numPos2 = program_[instr_ptr + 2];
  int resultPos = program_[instr_ptr + 3];
  program_[resultPos] = program_[numPos1] * program_[numPos2];
//  std::cout << "Opcode 2: num[" << numPos1 << "](" << program_[numPos1] << ") * num[" << numPos2 << "](" << program_[numPos2] << ") = " << program_[resultPos] << " at " << resultPos << std::endl;
}

void Intcode::setValue(int index, int value) {
  if (index >= program_.size()) {
    std::stringstream msg;
    msg << "Couldn't store value at position " << index << ". Size of program is " << program_.size();
    throw std::invalid_argument(msg.str());
  }
  program_[index] = value;
}

void Intcode::loadProgram(std::vector<int> program) {
  program_ = std::move(program);
}

}