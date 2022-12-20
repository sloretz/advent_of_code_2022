#include <cassert>
#include <numeric>
#include <iostream>
#include <map>

// X: 1
// Y: 2
// Z: 3
// win: 6
// draw: 3
// loss: 0
const std::map<std::string, int> kScoreLookup{
  {"A X", 4},
  {"A Y", 8},
  {"B X", 1},
  {"A Z", 3},
  {"B Y", 5},
  {"B Z", 9},
  {"C X", 7},
  {"C Y", 2},
  {"C Z", 6},
};

// X: lose
// Y: draw
// Z: win
const std::map<std::string, int> kScoreLookup2{
  {"A X", 3 + 0},
  {"A Y", 1 + 3},
  {"A Z", 2 + 6},
  {"B X", 1 + 0},
  {"B Y", 2 + 3},
  {"B Z", 3 + 6},
  {"C X", 2 + 0},
  {"C Y", 3 + 3},
  {"C Z", 1 + 6},
};

int main() {

  int total_score = 0;
  int total_score2 = 0;
  while (std::cin) {
    std::string round_line;
    std::getline(std::cin, round_line);
    if(round_line.empty()) {
      break;
      // End of file but file ends with newline?
    }

    total_score += kScoreLookup.at(round_line);
    total_score2 += kScoreLookup2.at(round_line);
  }

  std::cout << "Total Score: " << total_score << "\n";
  std::cout << "Total Score interpretation 2: " << total_score2 << "\n";

  return 0;
}