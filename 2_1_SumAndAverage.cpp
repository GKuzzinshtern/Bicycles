// Посчитать сумму и среднее арифметическое цифр в числе
#include <iostream>
#include <limits>

int main() {
  constexpr uint32_t ciKOEF_MULTI{10}; // must be >0
  uint32_t iInNumber{};

  std::cout << "Enter digits: ";
  std::cin >> iInNumber; // without checking for correctness

  uint32_t iTempNumber{iInNumber};
  uint32_t iSum{};
  uint32_t iCounter{};
  while (iTempNumber != 0) {
    uint32_t iTempNumberZeroEnd{iInNumber};
    uint32_t iDigit{};
    iTempNumberZeroEnd = (iTempNumber / ciKOEF_MULTI) * ciKOEF_MULTI;
    iDigit = iTempNumber - (iTempNumberZeroEnd);
    iTempNumber /= ciKOEF_MULTI;
    if (iSum > (std::numeric_limits<std::uint32_t>::max() - iDigit)) {
      std::cout << "The sum is overlimit\n";
      return -1;
    }
    std::cout << iDigit << ' ';
    iSum += iDigit;
    ++iCounter;
  }
  std::cout << '\n';

  if (iCounter == 0) {
    std::cout << "There is no digits \n";
    return -1;
  }
  std::cout << iSum << " / " << iCounter << " = " << (iSum / static_cast<double>(iCounter)) << '\n';

  return 0;
}

