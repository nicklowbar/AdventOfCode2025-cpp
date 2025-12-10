#include <argparse/argparse.hpp>
#include <format>
#include <iostream>

#include <shared.hpp>

using SolutionFunction = std::function<unsigned long long(std::ifstream &)>;

void shared_main(const char *program_name, int argc, char *argv[],
                 SolutionFunction solution1, SolutionFunction solution2) {

  argparse::ArgumentParser program(program_name);
  program.add_argument("-v", "--verbose");

  unsigned int solution_idx;
  program.add_argument("solution")
      .help("Solution part to solve.")
      .store_into(solution_idx);

  std::string stream_path;
  program.add_argument("input")
      .help("Path to problem input")
      .store_into(stream_path);

  try {
    program.parse_args(argc, argv);
  } catch (const std::exception &err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    std::exit(1);
  }

  unsigned long long solution = 0;

  auto input = std::ifstream(stream_path);
  switch (solution_idx) {
  case 1:
    solution = solution1(input);
    break;
  case 2:
    solution = solution2(input);
    break;
  default:
    throw std::runtime_error(std::format("Invalid solution: {}", solution));
  }

  std::cout << std::format("Solution: {}\n", solution);
}