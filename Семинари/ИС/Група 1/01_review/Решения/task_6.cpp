#include "week1.h"

#include <iostream>

/*----------------------------------------------------------------------------*/

void combine(
  const int numberArray[], size_t arraySize, size_t k,
  size_t nextI,
  int currentCombination[], size_t combinationSize
) {
  if (combinationSize == k) {
    Week1::print(currentCombination, combinationSize);
  }
  else for (size_t i = nextI; i < arraySize; ++i) {
    currentCombination[combinationSize] = numberArray[i];
    combine(numberArray, arraySize, k, i + 1, currentCombination, combinationSize + 1);
  }
}

void combine(const int numberArray[], size_t arraySize, size_t k) {
  constexpr size_t MAX_SIZE = 10000;
  if (k > arraySize || arraySize > MAX_SIZE) {
    return;
  }

  int combination[MAX_SIZE];
  combine(numberArray, arraySize, k, /*nextI=*/0, combination, /*combinationSize=*/0);
}

void Week1::task6() {
  int numbers[] = {1, 2, 5, 15};
  combine(numbers, sizeof(numbers) / sizeof(int), /*k=*/2);
}
