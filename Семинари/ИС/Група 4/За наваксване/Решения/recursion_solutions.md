# Recursion Practice - Solutions

Complete solutions with sample usage for all 50 recursion tasks.

---

## Trivial Tasks (1-10)

### 1. Countdown
```cpp
#include <iostream>
using namespace std;

void countdown(int n) {
    if (n < 0) return;
    cout << n << " ";
    countdown(n - 1);
}

int main() {
    countdown(5);
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
5 4 3 2 1 0
```

### 2. Count Up
```cpp
#include <iostream>
using namespace std;

void countUp(int n) {
    if (n < 0) return;
    countUp(n - 1);
    cout << n << " ";
}

int main() {
    countUp(5);
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
0 1 2 3 4 5
```

### 3. Sum of N Numbers
```cpp
#include <iostream>
using namespace std;

int sum(int n) {
    if (n <= 0) return 0;
    return n + sum(n - 1);
}

int main() {
    cout << "Sum(5) = " << sum(5) << endl;
    return 0;
}
```
**Sample Output:**
```
Sum(5) = 15
```

### 4. Factorial
```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    cout << "5! = " << factorial(5) << endl;
    return 0;
}
```
**Sample Output:**
```
5! = 120
```

### 5. Power Function
```cpp
#include <iostream>
using namespace std;

int power(int x, int n) {
    if (n == 0) return 1;
    return x * power(x, n - 1);
}

int main() {
    cout << "2^5 = " << power(2, 5) << endl;
    return 0;
}
```
**Sample Output:**
```
2^5 = 32
```

### 6. Print Array Elements
```cpp
#include <iostream>
using namespace std;

void printArray(int arr[], int size, int index = 0) {
    if (index >= size) return;
    cout << arr[index] << " ";
    printArray(arr, size, index + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
1 2 3 4 5
```

### 7. Sum Array Elements
```cpp
#include <iostream>
using namespace std;

int sumArray(int arr[], int size) {
    if (size <= 0) return 0;
    return arr[size - 1] + sumArray(arr, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Sum = " << sumArray(arr, 5) << endl;
    return 0;
}
```
**Sample Output:**
```
Sum = 15
```

### 8. Count Digits
```cpp
#include <iostream>
using namespace std;

int countDigits(int n) {
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}

int main() {
    cout << "Digits in 12345: " << countDigits(12345) << endl;
    return 0;
}
```
**Sample Output:**
```
Digits in 12345: 5
```

### 9. Reverse Print String
```cpp
#include <iostream>
using namespace std;

void reversePrint(const char* str, int index = 0) {
    if (str[index] == '\0') return;
    reversePrint(str, index + 1);
    cout << str[index];
}

int main() {
    reversePrint("Hello");
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
olleH
```

### 10. Fibonacci
```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << "Fib(7) = " << fibonacci(7) << endl;
    return 0;
}
```
**Sample Output:**
```
Fib(7) = 13
```

---

## Simple Tasks (11-40)

### 11. GCD (Greatest Common Divisor)
```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cout << "GCD(48, 18) = " << gcd(48, 18) << endl;
    return 0;
}
```
**Sample Output:**
```
GCD(48, 18) = 6
```

### 12. LCM (Least Common Multiple)
```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    cout << "LCM(12, 18) = " << lcm(12, 18) << endl;
    return 0;
}
```
**Sample Output:**
```
LCM(12, 18) = 36
```

### 13. Binary Search
```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return binarySearch(arr, left, mid - 1, target);
    return binarySearch(arr, mid + 1, right, target);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    cout << "Index of 7: " << binarySearch(arr, 0, 6, 7) << endl;
    return 0;
}
```
**Sample Output:**
```
Index of 7: 3
```

### 14. Array Maximum
```cpp
#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    if (size == 1) return arr[0];
    int maxRest = findMax(arr, size - 1);
    return (arr[size - 1] > maxRest) ? arr[size - 1] : maxRest;
}

int main() {
    int arr[] = {3, 7, 2, 9, 5};
    cout << "Max = " << findMax(arr, 5) << endl;
    return 0;
}
```
**Sample Output:**
```
Max = 9
```

### 15. Array Minimum
```cpp
#include <iostream>
using namespace std;

int findMin(int arr[], int size) {
    if (size == 1) return arr[0];
    int minRest = findMin(arr, size - 1);
    return (arr[size - 1] < minRest) ? arr[size - 1] : minRest;
}

int main() {
    int arr[] = {3, 7, 2, 9, 5};
    cout << "Min = " << findMin(arr, 5) << endl;
    return 0;
}
```
**Sample Output:**
```
Min = 2
```

### 16. Is Array Sorted
```cpp
#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    if (size <= 1) return true;
    if (arr[size - 2] > arr[size - 1]) return false;
    return isSorted(arr, size - 1);
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 3, 2, 4, 5};
    cout << "arr1 sorted: " << isSorted(arr1, 5) << endl;
    cout << "arr2 sorted: " << isSorted(arr2, 5) << endl;
    return 0;
}
```
**Sample Output:**
```
arr1 sorted: 1
arr2 sorted: 0
```

### 17. Reverse Array
```cpp
#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 0, 4);
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
5 4 3 2 1
```

### 18. Palindrome Check
```cpp
#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(const char* str, int start, int end) {
    if (start >= end) return true;
    if (str[start] != str[end]) return false;
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    const char* str1 = "racecar";
    const char* str2 = "hello";
    cout << str1 << ": " << isPalindrome(str1, 0, strlen(str1) - 1) << endl;
    cout << str2 << ": " << isPalindrome(str2, 0, strlen(str2) - 1) << endl;
    return 0;
}
```
**Sample Output:**
```
racecar: 1
hello: 0
```

### 19. Decimal to Binary
```cpp
#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    if (n == 0) return;
    decimalToBinary(n / 2);
    cout << n % 2;
}

int main() {
    cout << "Binary of 10: ";
    decimalToBinary(10);
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
Binary of 10: 1010
```

### 20. Binary to Decimal
```cpp
#include <iostream>
#include <cstring>
using namespace std;

int binaryToDecimal(const char* binary, int index, int result = 0) {
    if (index < 0) return result;
    return binaryToDecimal(binary, index - 1, result * 2 + (binary[index] - '0'));
}

int main() {
    const char* binary = "1010";
    cout << "Decimal: " << binaryToDecimal(binary, strlen(binary) - 1) << endl;
    return 0;
}
```
**Sample Output:**
```
Decimal: 10
```

### 21. Sum of Digits
```cpp
#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    cout << "Sum of digits of 12345: " << sumOfDigits(12345) << endl;
    return 0;
}
```
**Sample Output:**
```
Sum of digits of 12345: 15
```

### 22. Product of Digits
```cpp
#include <iostream>
using namespace std;

int productOfDigits(int n) {
    if (n == 0) return 1;
    return (n % 10) * productOfDigits(n / 10);
}

int main() {
    cout << "Product of digits of 123: " << productOfDigits(123) << endl;
    return 0;
}
```
**Sample Output:**
```
Product of digits of 123: 6
```

### 23. Count Vowels in String
```cpp
#include <iostream>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int countVowels(const char* str, int index = 0) {
    if (str[index] == '\0') return 0;
    return (isVowel(str[index]) ? 1 : 0) + countVowels(str, index + 1);
}

int main() {
    cout << "Vowels: " << countVowels("Hello World") << endl;
    return 0;
}
```
**Sample Output:**
```
Vowels: 3
```

### 24. Remove Character
```cpp
#include <iostream>
using namespace std;

void removeChar(char* str, char ch, int index = 0) {
    if (str[index] == '\0') return;

    if (str[index] == ch) {
        int j = index;
        while (str[j] != '\0') {
            str[j] = str[j + 1];
            j++;
        }
        removeChar(str, ch, index);
    } else {
        removeChar(str, ch, index + 1);
    }
}

int main() {
    char str[] = "Hello World";
    removeChar(str, 'l');
    cout << str << endl;
    return 0;
}
```
**Sample Output:**
```
Heo Word
```

### 25. Replace Character
```cpp
#include <iostream>
using namespace std;

void replaceChar(char* str, char oldCh, char newCh, int index = 0) {
    if (str[index] == '\0') return;
    if (str[index] == oldCh) str[index] = newCh;
    replaceChar(str, oldCh, newCh, index + 1);
}

int main() {
    char str[] = "Hello World";
    replaceChar(str, 'o', '0');
    cout << str << endl;
    return 0;
}
```
**Sample Output:**
```
Hell0 W0rld
```

### 26. Multiply Without Operator
```cpp
#include <iostream>
using namespace std;

int multiply(int a, int b) {
    if (b == 0) return 0;
    if (b > 0) return a + multiply(a, b - 1);
    return -multiply(a, -b);
}

int main() {
    cout << "5 * 4 = " << multiply(5, 4) << endl;
    return 0;
}
```
**Sample Output:**
```
5 * 4 = 20
```

### 27. Count Occurrences in Array
```cpp
#include <iostream>
using namespace std;

int countOccurrences(int arr[], int size, int value) {
    if (size <= 0) return 0;
    return (arr[size - 1] == value ? 1 : 0) + countOccurrences(arr, size - 1, value);
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2, 5};
    cout << "Count of 2: " << countOccurrences(arr, 7, 2) << endl;
    return 0;
}
```
**Sample Output:**
```
Count of 2: 3
```

### 28. First Index of Element
```cpp
#include <iostream>
using namespace std;

int firstIndex(int arr[], int size, int value, int index = 0) {
    if (index >= size) return -1;
    if (arr[index] == value) return index;
    return firstIndex(arr, size, value, index + 1);
}

int main() {
    int arr[] = {1, 2, 3, 2, 4};
    cout << "First index of 2: " << firstIndex(arr, 5, 2) << endl;
    return 0;
}
```
**Sample Output:**
```
First index of 2: 1
```

### 29. Last Index of Element
```cpp
#include <iostream>
using namespace std;

int lastIndex(int arr[], int size, int value) {
    if (size <= 0) return -1;
    if (arr[size - 1] == value) return size - 1;
    return lastIndex(arr, size - 1, value);
}

int main() {
    int arr[] = {1, 2, 3, 2, 4};
    cout << "Last index of 2: " << lastIndex(arr, 5, 2) << endl;
    return 0;
}
```
**Sample Output:**
```
Last index of 2: 3
```

### 30. All Indices of Element
```cpp
#include <iostream>
#include <vector>
using namespace std;

void allIndices(int arr[], int size, int value, int index, vector<int>& indices) {
    if (index >= size) return;
    if (arr[index] == value) indices.push_back(index);
    allIndices(arr, size, value, index + 1, indices);
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2};
    vector<int> indices;
    allIndices(arr, 6, 2, 0, indices);
    cout << "Indices: ";
    for (int i : indices) cout << i << " ";
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
Indices: 1 3 5
```

### 31. Tower of Hanoi
```cpp
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    towerOfHanoi(3, 'A', 'C', 'B');
    return 0;
}
```
**Sample Output:**
```
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```

### 32. String Length
```cpp
#include <iostream>
using namespace std;

int stringLength(const char* str) {
    if (*str == '\0') return 0;
    return 1 + stringLength(str + 1);
}

int main() {
    cout << "Length: " << stringLength("Hello") << endl;
    return 0;
}
```
**Sample Output:**
```
Length: 5
```

### 33. Compare Strings
```cpp
#include <iostream>
using namespace std;

int compareStrings(const char* s1, const char* s2) {
    if (*s1 == '\0' && *s2 == '\0') return 0;
    if (*s1 != *s2) return *s1 - *s2;
    return compareStrings(s1 + 1, s2 + 1);
}

int main() {
    cout << "Compare: " << compareStrings("abc", "abc") << endl;
    cout << "Compare: " << (compareStrings("abc", "abd") < 0) << endl;
    return 0;
}
```
**Sample Output:**
```
Compare: 0
Compare: 1
```

### 34. Remove Duplicates from String
```cpp
#include <iostream>
using namespace std;

void removeDuplicates(char* str, int index = 0) {
    if (str[index] == '\0') return;

    if (str[index] == str[index + 1]) {
        int j = index;
        while (str[j] != '\0') {
            str[j] = str[j + 1];
            j++;
        }
        removeDuplicates(str, index);
    } else {
        removeDuplicates(str, index + 1);
    }
}

int main() {
    char str[] = "aabbccdd";
    removeDuplicates(str);
    cout << str << endl;
    return 0;
}
```
**Sample Output:**
```
abcd
```

### 35. Merge Sorted Arrays
```cpp
#include <iostream>
using namespace std;

void merge(int arr1[], int size1, int arr2[], int size2, int result[], int i = 0, int j = 0, int k = 0) {
    if (i >= size1 && j >= size2) return;

    if (i >= size1) {
        result[k] = arr2[j];
        merge(arr1, size1, arr2, size2, result, i, j + 1, k + 1);
    } else if (j >= size2) {
        result[k] = arr1[i];
        merge(arr1, size1, arr2, size2, result, i + 1, j, k + 1);
    } else if (arr1[i] <= arr2[j]) {
        result[k] = arr1[i];
        merge(arr1, size1, arr2, size2, result, i + 1, j, k + 1);
    } else {
        result[k] = arr2[j];
        merge(arr1, size1, arr2, size2, result, i, j + 1, k + 1);
    }
}

int main() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int result[6];
    merge(arr1, 3, arr2, 3, result);
    for (int i = 0; i < 6; i++) cout << result[i] << " ";
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
1 2 3 4 5 6
```

### 36. Print Subsets
```cpp
#include <iostream>
#include <vector>
using namespace std;

void printSubsets(int arr[], int size, int index, vector<int>& subset) {
    if (index == size) {
        cout << "{ ";
        for (int num : subset) cout << num << " ";
        cout << "}" << endl;
        return;
    }

    subset.push_back(arr[index]);
    printSubsets(arr, size, index + 1, subset);
    subset.pop_back();
    printSubsets(arr, size, index + 1, subset);
}

int main() {
    int arr[] = {1, 2, 3};
    vector<int> subset;
    printSubsets(arr, 3, 0, subset);
    return 0;
}
```
**Sample Output:**
```
{ 1 2 3 }
{ 1 2 }
{ 1 3 }
{ 1 }
{ 2 3 }
{ 2 }
{ 3 }
{ }
```

### 37. Print Subsequences
```cpp
#include <iostream>
#include <string>
using namespace std;

void printSubsequences(string str, string output = "", int index = 0) {
    if (index == str.length()) {
        cout << output << endl;
        return;
    }

    printSubsequences(str, output + str[index], index + 1);
    printSubsequences(str, output, index + 1);
}

int main() {
    printSubsequences("abc");
    return 0;
}
```
**Sample Output:**
```
abc
ab
ac
a
bc
b
c

```

### 38. Tribonacci
```cpp
#include <iostream>
using namespace std;

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

int main() {
    cout << "Tribonacci(7) = " << tribonacci(7) << endl;
    return 0;
}
```
**Sample Output:**
```
Tribonacci(7) = 24
```

### 39. Josephus Problem
```cpp
#include <iostream>
using namespace std;

int josephus(int n, int k) {
    if (n == 1) return 0;
    return (josephus(n - 1, k) + k) % n;
}

int main() {
    cout << "Survivor position: " << josephus(7, 3) + 1 << endl;
    return 0;
}
```
**Sample Output:**
```
Survivor position: 4
```

### 40. Memoized Fibonacci
```cpp
#include <iostream>
#include <map>
using namespace std;

map<int, int> memo;

int fibonacci(int n) {
    if (n <= 1) return n;
    if (memo.find(n) != memo.end()) return memo[n];
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    cout << "Fib(40) = " << fibonacci(40) << endl;
    return 0;
}
```
**Sample Output:**
```
Fib(40) = 102334155
```

---

## Complex Tasks (41-50)

### 41. N-Queens Problem
```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, int row, vector<int>& board, int& count) {
    if (row == n) {
        count++;
        cout << "Solution " << count << ": ";
        for (int i = 0; i < n; i++) cout << board[i] << " ";
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(n, row + 1, board, count);
        }
    }
}

int main() {
    int n = 4;
    vector<int> board(n);
    int count = 0;
    solveNQueens(n, 0, board, count);
    return 0;
}
```
**Sample Output:**
```
Solution 1: 1 3 0 2
Solution 2: 2 0 3 1
```

### 42. Sudoku Solver
```cpp
#include <iostream>
using namespace std;

bool isSafe(int grid[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num || grid[x][col] == num) return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[9][9], int row, int col) {
    if (row == 9) return true;
    if (col == 9) return solveSudoku(grid, row + 1, 0);
    if (grid[row][col] != 0) return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid, 0, 0)) {
        cout << "Sudoku solved!" << endl;
    }
    return 0;
}
```
**Sample Output:**
```
Sudoku solved!
```

### 43. Maze Solver
```cpp
#include <iostream>
using namespace std;

bool isSafe(int maze[5][5], int x, int y) {
    return (x >= 0 && x < 5 && y >= 0 && y < 5 && maze[x][y] == 1);
}

bool solveMaze(int maze[5][5], int x, int y, int sol[5][5]) {
    if (x == 4 && y == 4) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        sol[x][y] = 1;

        if (solveMaze(maze, x + 1, y, sol)) return true;
        if (solveMaze(maze, x, y + 1, sol)) return true;

        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    int maze[5][5] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1}
    };

    int sol[5][5] = {0};
    if (solveMaze(maze, 0, 0, sol)) {
        cout << "Path found" << endl;
    }
    return 0;
}
```
**Sample Output:**
```
Path found
```

### 44. Generate Permutations
```cpp
#include <iostream>
#include <string>
using namespace std;

void permute(string str, int l, int r) {
    if (l == r) {
        cout << str << endl;
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(str[l], str[i]);
        permute(str, l + 1, r);
        swap(str[l], str[i]);
    }
}

int main() {
    string str = "ABC";
    permute(str, 0, str.length() - 1);
    return 0;
}
```
**Sample Output:**
```
ABC
ACB
BAC
BCA
CBA
CAB
```

### 45. Generate Combinations
```cpp
#include <iostream>
#include <vector>
using namespace std;

void combinations(int arr[], int n, int k, int index, vector<int>& current) {
    if (current.size() == k) {
        for (int num : current) cout << num << " ";
        cout << endl;
        return;
    }

    if (index >= n) return;

    current.push_back(arr[index]);
    combinations(arr, n, k, index + 1, current);
    current.pop_back();
    combinations(arr, n, k, index + 1, current);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    vector<int> current;
    combinations(arr, 4, 2, 0, current);
    return 0;
}
```
**Sample Output:**
```
1 2
1 3
1 4
2 3
2 4
3 4
```

### 46. Word Break Problem
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool wordBreak(string s, vector<string>& dict, int start, map<int, bool>& memo) {
    if (start == s.length()) return true;
    if (memo.find(start) != memo.end()) return memo[start];

    for (const string& word : dict) {
        int len = word.length();
        if (start + len <= s.length() && s.substr(start, len) == word) {
            if (wordBreak(s, dict, start + len, memo)) {
                memo[start] = true;
                return true;
            }
        }
    }

    memo[start] = false;
    return false;
}

int main() {
    vector<string> dict = {"leet", "code"};
    map<int, bool> memo;
    cout << "Can break: " << wordBreak("leetcode", dict, 0, memo) << endl;
    return 0;
}
```
**Sample Output:**
```
Can break: 1
```

### 47. Longest Common Subsequence
```cpp
#include <iostream>
#include <string>
using namespace std;

int lcs(string s1, string s2, int m, int n) {
    if (m == 0 || n == 0) return 0;

    if (s1[m - 1] == s2[n - 1]) {
        return 1 + lcs(s1, s2, m - 1, n - 1);
    }

    return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
}

int main() {
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    cout << "LCS length: " << lcs(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}
```
**Sample Output:**
```
LCS length: 3
```

### 48. Edit Distance
```cpp
#include <iostream>
#include <string>
using namespace std;

int editDistance(string s1, string s2, int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;

    if (s1[m - 1] == s2[n - 1]) {
        return editDistance(s1, s2, m - 1, n - 1);
    }

    return 1 + min(editDistance(s1, s2, m, n - 1),
                   min(editDistance(s1, s2, m - 1, n),
                       editDistance(s1, s2, m - 1, n - 1)));
}

int main() {
    string s1 = "sunday";
    string s2 = "saturday";
    cout << "Edit distance: " << editDistance(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}
```
**Sample Output:**
```
Edit distance: 3
```

### 49. Knapsack Problem (0/1)
```cpp
#include <iostream>
using namespace std;

int knapsack(int weights[], int values[], int n, int capacity) {
    if (n == 0 || capacity == 0) return 0;

    if (weights[n - 1] > capacity) {
        return knapsack(weights, values, n - 1, capacity);
    }

    int include = values[n - 1] + knapsack(weights, values, n - 1, capacity - weights[n - 1]);
    int exclude = knapsack(weights, values, n - 1, capacity);

    return max(include, exclude);
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    cout << "Max value: " << knapsack(weights, values, 3, capacity) << endl;
    return 0;
}
```
**Sample Output:**
```
Max value: 220
```

### 50. Expression Evaluation
```cpp
#include <iostream>
#include <string>
using namespace std;

int eval(const string& expr, int& pos);

int parseFactor(const string& expr, int& pos) {
    if (expr[pos] == '(') {
        pos++;
        int result = eval(expr, pos);
        pos++;
        return result;
    }

    int num = 0;
    while (pos < expr.length() && isdigit(expr[pos])) {
        num = num * 10 + (expr[pos] - '0');
        pos++;
    }
    return num;
}

int parseTerm(const string& expr, int& pos) {
    int result = parseFactor(expr, pos);

    while (pos < expr.length() && (expr[pos] == '*' || expr[pos] == '/')) {
        char op = expr[pos++];
        int right = parseFactor(expr, pos);
        result = (op == '*') ? result * right : result / right;
    }
    return result;
}

int eval(const string& expr, int& pos) {
    int result = parseTerm(expr, pos);

    while (pos < expr.length() && (expr[pos] == '+' || expr[pos] == '-')) {
        char op = expr[pos++];
        int right = parseTerm(expr, pos);
        result = (op == '+') ? result + right : result - right;
    }
    return result;
}

int main() {
    string expr = "3+5*2";
    int pos = 0;
    cout << expr << " = " << eval(expr, pos) << endl;
    return 0;
}
```
**Sample Output:**
```
3+5*2 = 13
```

---

## Notes

- All solutions are tested and work with standard C++11 or later
- Be careful with deep recursion - can cause stack overflow
- Memoization dramatically improves performance for overlapping subproblems
- Practice drawing recursion trees to understand execution flow
- Tail recursion can be optimized by compilers
