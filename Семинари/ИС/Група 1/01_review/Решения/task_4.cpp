#include "week1.h"

#include <iostream>
#include <vector>

/*----------------------------------------------------------------------------*/

void Week1::print(const int numberArray[], size_t arraySize) {
  for (size_t i = 0; i < arraySize; ++i) {
    std::cout << numberArray[i] << ' ';
  }
  std::cout << '\n';
}

/*----------------------------------------------------------------------------*/

void permute(
  const int numbersArray[], size_t arraySize,
  bool used[], int currentPermutation[], size_t permutationSize
) {
  if (permutationSize == arraySize) {
    Week1::print(currentPermutation, permutationSize);
  }
  else for (size_t i = 0; i < arraySize; ++i) {
    if (!used[i]) {
      used[i] = true;
      currentPermutation[permutationSize] = numbersArray[i];
      permute(numbersArray, arraySize, used, currentPermutation, permutationSize + 1);
      used[i] = false;
    }
  }
}

void permute(const int numbersArray[], size_t arraySize) {
  constexpr size_t MAX_SIZE = 10000;
  if (arraySize > MAX_SIZE) {
    std::cerr << "Week1::permute: size limit exceded!";
    return;
  }

  bool used[MAX_SIZE];
  for (size_t i = 0; i < arraySize; ++i) {
    used[i] = false;
  }

  int permutation[MAX_SIZE];
  permute(numbersArray, arraySize, used, permutation, /*permutationSize=*/0);
}

void Week1::task4() {
  int numbers[] = {1, 2, 5, 15};
  permute(numbers, sizeof(numbers) / sizeof(int));
}
