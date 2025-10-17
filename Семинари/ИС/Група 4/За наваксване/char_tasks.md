# C-Style Strings (char*) Practice Tasks (50 Tasks)

Master C-style string manipulation through repetition and progressive complexity.

---

## Trivial Tasks (1-10)

### 1. String Declaration and Print
**Difficulty:** Trivial
**Task:** Declare a char array with a string literal, print it using printf/cout.

### 2. String Length Manual
**Difficulty:** Trivial
**Task:** Write a function that calculates string length by iterating until '\0' is found.

### 3. Character Access
**Difficulty:** Trivial
**Task:** Access and print individual characters of a string using array indexing.

### 4. Character Access via Pointer
**Difficulty:** Trivial
**Task:** Use pointer arithmetic to access and print each character of a string.

### 5. String Copy Simple
**Difficulty:** Trivial
**Task:** Copy one string to another character by character using a loop.

### 6. String Input
**Difficulty:** Trivial
**Task:** Read a string from user input into a char array, print it back.

### 7. First Character Check
**Difficulty:** Trivial
**Task:** Write a function that returns the first character of a string.

### 8. Last Character Check
**Difficulty:** Trivial
**Task:** Write a function that returns the last character (before '\0') of a string.

### 9. Character Count
**Difficulty:** Trivial
**Task:** Count how many times a specific character appears in a string.

### 10. String Comparison Manual
**Difficulty:** Trivial
**Task:** Write a function that compares two strings character by character, return 0 if equal.

---

## Simple Tasks (11-40)

### 11. Implement strlen
**Difficulty:** Simple
**Task:** Implement your own version of strlen() using pointer arithmetic.

### 12. Implement strcpy
**Difficulty:** Simple
**Task:** Implement your own version of strcpy() that copies a string to destination.

### 13. Implement strcat
**Difficulty:** Simple
**Task:** Implement your own version of strcat() that concatenates two strings.

### 14. Implement strcmp
**Difficulty:** Simple
**Task:** Implement your own version of strcmp() that returns negative, 0, or positive value.

### 15. String to Uppercase
**Difficulty:** Simple
**Task:** Write a function that converts all characters in a string to uppercase in-place.

### 16. String to Lowercase
**Difficulty:** Simple
**Task:** Write a function that converts all characters in a string to lowercase in-place.

### 17. Count Vowels
**Difficulty:** Simple
**Task:** Count the number of vowels (a, e, i, o, u) in a string, case-insensitive.

### 18. Count Consonants
**Difficulty:** Simple
**Task:** Count the number of consonants in a string.

### 19. Count Words
**Difficulty:** Simple
**Task:** Count the number of words in a string (words separated by spaces).

### 20. Reverse String In-Place
**Difficulty:** Simple
**Task:** Reverse a string in-place using two pointers (start and end).

### 21. Is Palindrome
**Difficulty:** Simple
**Task:** Write a function that checks if a string is a palindrome (case-insensitive).

### 22. Remove Spaces
**Difficulty:** Simple
**Task:** Remove all spaces from a string in-place.

### 23. Trim Leading Spaces
**Difficulty:** Simple
**Task:** Remove all leading whitespace characters from a string.

### 24. Trim Trailing Spaces
**Difficulty:** Simple
**Task:** Remove all trailing whitespace characters from a string.

### 25. Find Character First Occurrence
**Difficulty:** Simple
**Task:** Implement strchr() - find first occurrence of a character, return pointer or nullptr.

### 26. Find Character Last Occurrence
**Difficulty:** Simple
**Task:** Implement strrchr() - find last occurrence of a character, return pointer or nullptr.

### 27. Find Substring
**Difficulty:** Simple
**Task:** Implement strstr() - find first occurrence of a substring, return pointer or nullptr.

### 28. Count Substrings
**Difficulty:** Simple
**Task:** Count how many times a substring appears in a string (non-overlapping).

### 29. Replace Character
**Difficulty:** Simple
**Task:** Replace all occurrences of one character with another in a string.

### 30. String to Integer (atoi)
**Difficulty:** Simple
**Task:** Implement atoi() - convert a string to an integer, handle signs.

### 31. Integer to String (itoa)
**Difficulty:** Simple
**Task:** Convert an integer to a string representation.

### 32. Is Digit String
**Difficulty:** Simple
**Task:** Check if a string contains only digit characters.

### 33. Is Alpha String
**Difficulty:** Simple
**Task:** Check if a string contains only alphabetic characters.

### 34. Is Alphanumeric String
**Difficulty:** Simple
**Task:** Check if a string contains only alphanumeric characters.

### 35. String Array Sorting
**Difficulty:** Simple
**Task:** Sort an array of strings (char* array) alphabetically using strcmp.

### 36. Longest Word
**Difficulty:** Simple
**Task:** Find and return a pointer to the longest word in a sentence.

### 37. Shortest Word
**Difficulty:** Simple
**Task:** Find and return a pointer to the shortest word in a sentence.

### 38. String Tokenization
**Difficulty:** Simple
**Task:** Implement a simple tokenizer that splits a string by a delimiter character.

### 39. Remove Character
**Difficulty:** Simple
**Task:** Remove all occurrences of a specific character from a string in-place.

### 40. Duplicate String
**Difficulty:** Simple
**Task:** Implement strdup() - allocate memory and create a copy of a string.

---

## Complex Tasks (41-50)

### 41. String Replace Substring
**Difficulty:** Complex
**Task:** Replace all occurrences of a substring with another substring (handle different lengths).

### 42. Split String into Array
**Difficulty:** Complex
**Task:** Split a string by delimiter into a dynamically allocated array of strings, return array and count.

### 43. Join String Array
**Difficulty:** Complex
**Task:** Join an array of strings with a separator into a single dynamically allocated string.

### 44. Anagram Checker
**Difficulty:** Complex
**Task:** Write a function that checks if two strings are anagrams of each other.

### 45. String Permutations
**Difficulty:** Complex
**Task:** Generate and print all permutations of a string using recursion.

### 46. Run-Length Encoding
**Difficulty:** Complex
**Task:** Compress a string using run-length encoding (e.g., "aaabbc" -> "a3b2c1").

### 47. Run-Length Decoding
**Difficulty:** Complex
**Task:** Decompress a run-length encoded string back to original.

### 48. Regular Expression Match (Simple)
**Difficulty:** Complex
**Task:** Implement simple pattern matching with '*' (any sequence) and '?' (single char).

### 49. Word Frequency Counter
**Difficulty:** Complex
**Task:** Count frequency of each unique word in a text, store in an array of structs, sort by frequency.

### 50. CSV Parser
**Difficulty:** Complex
**Task:** Parse a CSV line into fields, handling quoted strings and escaped commas properly.

---

## Learning Objectives

By completing these tasks, you will develop instinctive understanding of:
- C-style string structure and null termination
- String traversal using pointers and indices
- Manual implementation of standard string functions
- In-place string manipulation techniques
- Dynamic memory allocation for strings
- String searching and pattern matching
- Character classification and transformation
- String parsing and tokenization
- Memory management for string operations
- Pointer arithmetic for string manipulation

**Practice Tip:** C-style strings are foundational to understanding memory and pointers in C++. Master these before moving to std::string. Repeat tasks until string manipulation becomes automatic.
