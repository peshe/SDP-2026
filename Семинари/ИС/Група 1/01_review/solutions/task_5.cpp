#include "week1.h"

#include <iostream>

/*----------------------------------------------------------------------------*/

void vary(
  const int numberArray[], size_t arraySize, size_t k,
  bool used[], int currentVariation[], size_t variationSize
) {
  if (variationSize == k) {
    Week1::print(currentVariation, variationSize);
  }
  else for (size_t i = 0; i < arraySize; ++i) {
    if (!used[i]) {
      used[i] = true;
      currentVariation[variationSize] = numberArray[i];
      vary(numberArray, arraySize, k, used, currentVariation, variationSize + 1);
      used[i] = false;
    }
  }
}

void vary(const int numberArray[], size_t arraySize, size_t k) {
  constexpr size_t MAX_SIZE = 10000;
  if (k > arraySize || arraySize > MAX_SIZE) {
    return;
  }

  bool used[MAX_SIZE];
  for (size_t i = 0; i < arraySize; ++i) {
    used[i] = false;
  }

  int variation[MAX_SIZE];
  vary(numberArray, arraySize, k, used, variation, /*variationSize=*/0);
}

void Week1::task5() {
  int numbers[] = {1, 2, 5, 15};
  vary(numbers, sizeof(numbers) / sizeof(int), /*k=*/2);
}
