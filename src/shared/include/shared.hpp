#include <fstream>
#include <functional>

using SolutionFunction = std::function<unsigned long long(std::ifstream &)>;

void shared_main(int argc, char **argv, SolutionFunction solution1,
                 SolutionFunction solution2);
