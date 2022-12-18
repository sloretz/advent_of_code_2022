#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  // Prime the loop with one elf
  std::vector<int> ledger{0};
  while (std::cin) {
    std::string ledger_line;
    std::getline(std::cin, ledger_line);
    if (ledger_line.empty()) {
      // Blank line means there's a new elf
      ledger.push_back(0);
    } else {
      // Add calories for elf
      ledger.back() += std::stoi(ledger_line);
    }
  }

  // Find the elf with the most calories
  size_t fattest_elf = 0;
  int most_calories = 0;
  for(size_t elf = 1; elf <= ledger.size(); ++elf) {
    int calories = ledger.at(elf-1);
    if (calories > most_calories) {
      most_calories = calories;
      fattest_elf = elf;
    }
  }

  std::cout << "The fattest elf is: " << fattest_elf << " with " << most_calories << " calories\n";

  std::sort(std::begin(ledger), std::end(ledger), std::greater<int>());

  std::cout << "The fattest 3 elves are carrying " << std::accumulate(ledger.begin(), ledger.begin() + 3, 0) << " calories\n";
  return 0;
}