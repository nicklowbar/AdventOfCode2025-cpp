#include <format>
#include <iostream>

#include <shared.hpp>

using SolutionFunction = std::function<unsigned long long(std::ifstream &)>;

void shared_main(int argc, char **argv, SolutionFunction solution1,
                 SolutionFunction solution2) {

  auto input = std::ifstream();
  auto solution = solution1(input);

  std::cout << std::format("Solution: {}\n", solution);
}