/*
--- Day 1: Secret Entrance ---

The Elves have good news and bad news.

The good news is that they've discovered project management! This has given them
the tools they need to prevent their usual Christmas emergency. For example,
they now know that the North Pole decorations need to be finished soon so that
other critical tasks can start on time.

The bad news is that they've realized they have a different emergency: according
to their resource planning, none of them have any time left to decorate the
North Pole!

To save Christmas, the Elves need you to finish decorating the North Pole by
December 12th.

Collect stars by solving puzzles. Two puzzles will be made available on each
day; the second puzzle is unlocked when you complete the first. Each puzzle
grants one star. Good luck!

You arrive at the secret entrance to the North Pole base ready to start
decorating. Unfortunately, the password seems to have been changed, so you can't
get in. A document taped to the wall helpfully explains:

"Due to new security protocols, the password is locked in the safe below. Please
see the attached document for the new combination."

The safe has a dial with only an arrow on it; around the dial are the numbers 0
through 99 in order. As you turn the dial, it makes a small click noise as it
reaches each number.

The attached document (your puzzle input) contains a sequence of rotations, one
per line, which tell you how to open the safe. A rotation starts with an L or R
which indicates whether the rotation should be to the left (toward lower
numbers) or to the right (toward higher numbers). Then, the rotation has a
distance value which indicates how many clicks the dial should be rotated in
that direction.

So, if the dial were pointing at 11, a rotation of R8 would cause the dial to
point at 19. After that, a rotation of L19 would cause it to point at 0.

Because the dial is a circle, turning the dial left from 0 one click makes it
point at 99. Similarly, turning the dial right from 99 one click makes it point
at 0.

So, if the dial were pointing at 5, a rotation of L10 would cause it to point
at 95. After that, a rotation of R5 could cause it to point at 0.

The dial starts by pointing at 50.

You could follow the instructions, but your recent required official North Pole
secret entrance security training seminar taught you that the safe is actually a
decoy. The actual password is the number of times the dial is left pointing at 0
after any rotation in the sequence.

For example, suppose the attached document contained the following rotations:

L68
L30
R48
L5
R60
L55
L1
L99
R14
L82

Following these rotations would cause the dial to move as follows:

    The dial starts by pointing at 50.
    The dial is rotated L68 to point at 82.
    The dial is rotated L30 to point at 52.
    The dial is rotated R48 to point at 0.
    The dial is rotated L5 to point at 95.
    The dial is rotated R60 to point at 55.
    The dial is rotated L55 to point at 0.
    The dial is rotated L1 to point at 99.
    The dial is rotated L99 to point at 0.
    The dial is rotated R14 to point at 14.
    The dial is rotated L82 to point at 32.

Because the dial points at 0 a total of three times during this process, the
password in this example is 3.

Analyze the rotations in your attached document. What's the actual password to
open the door?
*/

#include <iostream>
#include <string>

#include <regex>
#include <shared.hpp>

unsigned long long solution1(std::ifstream &input);
unsigned long long solution2(std::ifstream &input);

int main(int argc, char *argv[]) {
  shared_main(EXECUTABLE_NAME, argc, argv, solution1, solution2);
}

enum Direction { L, R };

unsigned long long solution1(std::ifstream &input) {
  std::regex re(R"(^([LR])(\d+)\s*$)");
  std::string line;
  const int modulus = 100;

  unsigned long long solution = 0;
  auto dial = 50;

  while (!input.eof()) {
    input >> line;

    std::smatch m;

    std::regex_search(line, m, re);
    /*
    std::cout << std::format("Matches: {}, {}, {}", m[0].str(), m[1].str(),
                             m[2].str())
              << std::endl;
    */
    std::string_view sv_line(m[0].first, m[0].second);
    std::string_view sv_direction(m[1].first, m[1].second);
    std::string_view sv_amount(m[2].first, m[2].second);

    int amount;
    auto result = std::from_chars(sv_amount.data(),
                                  sv_amount.data() + sv_amount.size(), amount);
    if (result.ec != std::errc{}) {
      std::runtime_error(std::format("Failed to parse amount: {}", sv_amount));
    }

    while (amount > 0) {
      switch (sv_direction[0]) {
      case 'L':
        dial--;
        if (dial < 0) {
          dial += modulus;
        }
        break;
      case 'R':
        dial++;
        if (dial >= modulus) {
          dial -= modulus;
        }
        break;
      default:
        throw std::runtime_error(
            std::format("Invalid input direction: {}", sv_direction));
      }
      // std::cout << std::format("Dial: {}", dial) << std::endl;
      amount--;
    }
    std::cout << std::format("Processed: {} Moved dial to: {}", sv_line, dial)
              << std::endl;

    if (dial == 0) {
      solution++;
    }
  }

  return solution;
}

unsigned long long solution2(std::ifstream &input) {
  std::regex re(R"(^([LR])(\d+)\s*$)");
  std::string line;
  const int modulus = 100;

  unsigned long long solution = 0;
  auto dial = 50;

  while (!input.eof()) {
    input >> line;

    std::smatch m;

    std::regex_search(line, m, re);
    /*
    std::cout << std::format("Matches: {}, {}, {}", m[0].str(), m[1].str(),
                             m[2].str())
              << std::endl;
    */
    std::string_view sv_line(m[0].first, m[0].second);
    std::string_view sv_direction(m[1].first, m[1].second);
    std::string_view sv_amount(m[2].first, m[2].second);

    int amount;
    auto result = std::from_chars(sv_amount.data(),
                                  sv_amount.data() + sv_amount.size(), amount);
    if (result.ec != std::errc{}) {
      std::runtime_error(std::format("Failed to parse amount: {}", sv_amount));
    }

    while (amount > 0) {
      switch (sv_direction[0]) {
      case 'L':
        dial--;
        if (dial < 0) {
          dial += modulus;
        }
        break;
      case 'R':
        dial++;
        if (dial >= modulus) {
          dial -= modulus;
        }
        break;
      default:
        throw std::runtime_error(
            std::format("Invalid input direction: {}", sv_direction));
      }
      // std::cout << std::format("Dial: {}", dial) << std::endl;
      if (dial == 0) {
        solution++;
      }
      amount--;
    }
    std::cout << std::format("Processed: {} Moved dial to: {}", sv_line, dial)
              << std::endl;
  }

  return solution;
}
