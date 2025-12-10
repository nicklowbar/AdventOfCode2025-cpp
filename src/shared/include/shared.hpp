#pragma once

#include <fstream>
#include <functional>

using SolutionFunction = std::function<unsigned long long(std::ifstream &)>;

void shared_main(const char *program_name, int argc, char *argv[],
                 SolutionFunction solution1, SolutionFunction solution2);
