#include "week1.h"

#include <iostream>
#include <string>

/*----------------------------------------------------------------------------*/

bool isPalindrome(const std::string& str, unsigned symmetricOffset) {
  if (str.length() - 2 * symmetricOffset < 2) {
    // At most 1 letter - definitely a palindrome.
    return true;
  }

  char start = str[symmetricOffset];
  char end = str[str.length() - 1 - symmetricOffset];

  return (start == end) && isPalindrome(str, symmetricOffset + 1);
}

bool isPalindrome(const std::string& str) {
  return isPalindrome(str, /*symmetricOffset=*/0);
}

void Week1::task3() {
  std::string str;
  std::cout << "Enter a string:\t";
  std::cin >> str;
  std::cout << str << " is " <<
    (isPalindrome(str) ? "" : "not ") << "a palindrome" << std::endl;
}
