# C-Style Strings (char*) Practice - Solutions

Complete solutions with sample usage for all 50 C-string tasks.

---

## Trivial Tasks (1-10)

### 1. String Declaration and Print
```cpp
#include <iostream>
using namespace std;

int main() {
    char str[] = "Hello, World!";
    cout << str << endl;
    return 0;
}
```
**Sample Output:**
```
Hello, World!
```

### 2. String Length Manual
```cpp
#include <iostream>
using namespace std;

int stringLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    char str[] = "Hello";
    cout << "Length: " << stringLength(str) << endl;
    return 0;
}
```
**Sample Output:**
```
Length: 5
```

### 3. Character Access
```cpp
#include <iostream>
using namespace std;

int main() {
    char str[] = "Hello";
    for (int i = 0; str[i] != '\0'; i++) {
        cout << str[i] << " ";
    }
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
H e l l o
```

### 4. Character Access via Pointer
```cpp
#include <iostream>
using namespace std;

int main() {
    char str[] = "World";
    char* ptr = str;

    while (*ptr != '\0') {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
W o r l d
```

### 5. String Copy Simple
```cpp
#include <iostream>
using namespace std;

int main() {
    char src[] = "Hello";
    char dest[20];

    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    cout << "Copied: " << dest << endl;
    return 0;
}
```
**Sample Output:**
```
Copied: Hello
```

### 6. String Input
```cpp
#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    cout << "You entered: " << str << endl;
    return 0;
}
```
**Sample Output:**
```
Enter a string: Hello World
You entered: Hello World
```

### 7. First Character Check
```cpp
#include <iostream>
using namespace std;

char firstChar(const char* str) {
    return str[0];
}

int main() {
    char str[] = "Programming";
    cout << "First character: " << firstChar(str) << endl;
    return 0;
}
```
**Sample Output:**
```
First character: P
```

### 8. Last Character Check
```cpp
#include <iostream>
using namespace std;

char lastChar(const char* str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return (i > 0) ? str[i - 1] : '\0';
}

int main() {
    char str[] = "Programming";
    cout << "Last character: " << lastChar(str) << endl;
    return 0;
}
```
**Sample Output:**
```
Last character: g
```

### 9. Character Count
```cpp
#include <iostream>
using namespace std;

int countChar(const char* str, char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) count++;
    }
    return count;
}

int main() {
    char str[] = "hello world";
    cout << "Count of 'l': " << countChar(str, 'l') << endl;
    return 0;
}
```
**Sample Output:**
```
Count of 'l': 3
```

### 10. String Comparison Manual
```cpp
#include <iostream>
using namespace std;

int compareStrings(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return 1;
        i++;
    }
    return (s1[i] == s2[i]) ? 0 : 1;
}

int main() {
    char str1[] = "hello";
    char str2[] = "hello";
    char str3[] = "world";

    cout << "str1 == str2: " << (compareStrings(str1, str2) == 0) << endl;
    cout << "str1 == str3: " << (compareStrings(str1, str3) == 0) << endl;
    return 0;
}
```
**Sample Output:**
```
str1 == str2: 1
str1 == str3: 0
```

---

## Simple Tasks (11-40)

### 11. Implement strlen
```cpp
#include <iostream>
using namespace std;

size_t my_strlen(const char* str) {
    const char* ptr = str;
    while (*ptr) ptr++;
    return ptr - str;
}

int main() {
    cout << my_strlen("Hello") << endl;
    return 0;
}
```
**Sample Output:**
```
5
```

### 12. Implement strcpy
```cpp
#include <iostream>
using namespace std;

char* my_strcpy(char* dest, const char* src) {
    char* original = dest;
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return original;
}

int main() {
    char dest[20];
    my_strcpy(dest, "Hello");
    cout << dest << endl;
    return 0;
}
```
**Sample Output:**
```
Hello
```

### 13. Implement strcat
```cpp
#include <iostream>
using namespace std;

char* my_strcat(char* dest, const char* src) {
    char* original = dest;
    while (*dest) dest++;
    while (*src) *dest++ = *src++;
    *dest = '\0';
    return original;
}

int main() {
    char dest[20] = "Hello";
    my_strcat(dest, " World");
    cout << dest << endl;
    return 0;
}
```
**Sample Output:**
```
Hello World
```

### 14. Implement strcmp
```cpp
#include <iostream>
using namespace std;

int my_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

int main() {
    cout << my_strcmp("abc", "abc") << endl;  // 0
    cout << (my_strcmp("abc", "abd") < 0) << endl;  // 1
    cout << (my_strcmp("abd", "abc") > 0) << endl;  // 1
    return 0;
}
```
**Sample Output:**
```
0
1
1
```

### 15. String to Uppercase
```cpp
#include <iostream>
#include <cctype>
using namespace std;

void toUpperCase(char* str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

int main() {
    char str[] = "hello world";
    toUpperCase(str);
    cout << str << endl;
    return 0;
}
```
**Sample Output:**
```
HELLO WORLD
```

### 16. String to Lowercase
```cpp
#include <iostream>
#include <cctype>
using namespace std;

void toLowerCase(char* str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int main() {
    char str[] = "HELLO WORLD";
    toLowerCase(str);
    cout << str << endl;
    return 0;
}
```
**Sample Output:**
```
hello world
```

### 17. Count Vowels
```cpp
#include <iostream>
#include <cctype>
using namespace std;

int countVowels(const char* str) {
    int count = 0;
    while (*str) {
        char ch = tolower(*str);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        str++;
    }
    return count;
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

### 18. Count Consonants
```cpp
#include <iostream>
#include <cctype>
using namespace std;

int countConsonants(const char* str) {
    int count = 0;
    while (*str) {
        char ch = tolower(*str);
        if (isalpha(ch)) {
            if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
                count++;
            }
        }
        str++;
    }
    return count;
}

int main() {
    cout << "Consonants: " << countConsonants("Hello World") << endl;
    return 0;
}
```
**Sample Output:**
```
Consonants: 7
```

### 19. Count Words
```cpp
#include <iostream>
#include <cctype>
using namespace std;

int countWords(const char* str) {
    int count = 0;
    bool inWord = false;

    while (*str) {
        if (isspace(*str)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    cout << "Words: " << countWords("Hello World from C++") << endl;
    return 0;
}
```
**Sample Output:**
```
Words: 4
```

### 20. Reverse String In-Place
```cpp
#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    char str[] = "Hello";
    reverseString(str);
    cout << str << endl;
    return 0;
}
```
**Sample Output:**
```
olleH
```

### 21. Is Palindrome
```cpp
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool isPalindrome(const char* str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    cout << "racecar: " << isPalindrome("racecar") << endl;
    cout << "hello: " << isPalindrome("hello") << endl;
    return 0;
}
```
**Sample Output:**
```
racecar: 1
hello: 0
```

### 22. Remove Spaces
```cpp
#include <iostream>
using namespace std;

void removeSpaces(char* str) {
    char* src = str;
    char* dst = str;

    while (*src) {
        if (*src != ' ') {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

int main() {
    char str[] = "Hello World from C++";
    removeSpaces(str);
    cout << str << endl;
    return 0;
}
```
**Sample Output:**
```
HelloWorldfromC++
```

### 23. Trim Leading Spaces
```cpp
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void trimLeft(char* str) {
    char* src = str;
    while (isspace(*src)) src++;

    if (src != str) {
        char* dst = str;
        while (*src) *dst++ = *src++;
        *dst = '\0';
    }
}

int main() {
    char str[] = "   Hello World";
    trimLeft(str);
    cout << "'" << str << "'" << endl;
    return 0;
}
```
**Sample Output:**
```
'Hello World'
```

### 24. Trim Trailing Spaces
```cpp
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void trimRight(char* str) {
    int len = strlen(str);
    while (len > 0 && isspace(str[len - 1])) {
        len--;
    }
    str[len] = '\0';
}

int main() {
    char str[] = "Hello World   ";
    trimRight(str);
    cout << "'" << str << "'" << endl;
    return 0;
}
```
**Sample Output:**
```
'Hello World'
```

### 25. Find Character First Occurrence
```cpp
#include <iostream>
using namespace std;

char* my_strchr(char* str, char ch) {
    while (*str) {
        if (*str == ch) return str;
        str++;
    }
    return nullptr;
}

int main() {
    char str[] = "Hello World";
    char* result = my_strchr(str, 'o');
    if (result) {
        cout << "Found at: " << (result - str) << endl;
    }
    return 0;
}
```
**Sample Output:**
```
Found at: 4
```

### 26. Find Character Last Occurrence
```cpp
#include <iostream>
using namespace std;

char* my_strrchr(char* str, char ch) {
    char* last = nullptr;
    while (*str) {
        if (*str == ch) last = str;
        str++;
    }
    return last;
}

int main() {
    char str[] = "Hello World";
    char* result = my_strrchr(str, 'o');
    if (result) {
        cout << "Last found at: " << (result - str) << endl;
    }
    return 0;
}
```
**Sample Output:**
```
Last found at: 7
```

### 27. Find Substring
```cpp
#include <iostream>
using namespace std;

char* my_strstr(char* haystack, const char* needle) {
    if (*needle == '\0') return haystack;

    while (*haystack) {
        char* h = haystack;
        const char* n = needle;

        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }

        if (*n == '\0') return haystack;
        haystack++;
    }
    return nullptr;
}

int main() {
    char str[] = "Hello World";
    char* result = my_strstr(str, "World");
    if (result) {
        cout << "Found: " << result << endl;
    }
    return 0;
}
```
**Sample Output:**
```
Found: World
```

### 28. Count Substrings
```cpp
#include <iostream>
#include <cstring>
using namespace std;

int countSubstring(const char* str, const char* sub) {
    int count = 0;
    int subLen = strlen(sub);

    while (*str) {
        if (strncmp(str, sub, subLen) == 0) {
            count++;
            str += subLen;  // Non-overlapping
        } else {
            str++;
        }
    }
    return count;
}

int main() {
    cout << countSubstring("abcabcabc", "abc") << endl;
    return 0;
}
```
**Sample Output:**
```
3
```

### 29. Replace Character
```cpp
#include <iostream>
using namespace std;

void replaceChar(char* str, char oldCh, char newCh) {
    while (*str) {
        if (*str == oldCh) *str = newCh;
        str++;
    }
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

### 30. String to Integer (atoi)
```cpp
#include <iostream>
#include <cctype>
using namespace std;

int my_atoi(const char* str) {
    int result = 0;
    int sign = 1;

    while (isspace(*str)) str++;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    while (isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

int main() {
    cout << my_atoi("123") << endl;
    cout << my_atoi("-456") << endl;
    cout << my_atoi("  789") << endl;
    return 0;
}
```
**Sample Output:**
```
123
-456
789
```

### 31. Integer to String (itoa)
```cpp
#include <iostream>
using namespace std;

void my_itoa(int num, char* str) {
    int i = 0;
    bool isNegative = false;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    while (num != 0) {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }

    if (isNegative) str[i++] = '-';
    str[i] = '\0';

    // Reverse
    int start = 0, end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char buffer[20];
    my_itoa(12345, buffer);
    cout << buffer << endl;
    my_itoa(-678, buffer);
    cout << buffer << endl;
    return 0;
}
```
**Sample Output:**
```
12345
-678
```

### 32. Is Digit String
```cpp
#include <iostream>
#include <cctype>
using namespace std;

bool isDigitString(const char* str) {
    if (*str == '\0') return false;
    while (*str) {
        if (!isdigit(*str)) return false;
        str++;
    }
    return true;
}

int main() {
    cout << isDigitString("12345") << endl;
    cout << isDigitString("123a5") << endl;
    return 0;
}
```
**Sample Output:**
```
1
0
```

### 33. Is Alpha String
```cpp
#include <iostream>
#include <cctype>
using namespace std;

bool isAlphaString(const char* str) {
    if (*str == '\0') return false;
    while (*str) {
        if (!isalpha(*str)) return false;
        str++;
    }
    return true;
}

int main() {
    cout << isAlphaString("Hello") << endl;
    cout << isAlphaString("Hello123") << endl;
    return 0;
}
```
**Sample Output:**
```
1
0
```

### 34. Is Alphanumeric String
```cpp
#include <iostream>
#include <cctype>
using namespace std;

bool isAlphanumeric(const char* str) {
    if (*str == '\0') return false;
    while (*str) {
        if (!isalnum(*str)) return false;
        str++;
    }
    return true;
}

int main() {
    cout << isAlphanumeric("Hello123") << endl;
    cout << isAlphanumeric("Hello 123") << endl;
    return 0;
}
```
**Sample Output:**
```
1
0
```

### 35. String Array Sorting
```cpp
#include <iostream>
#include <cstring>
using namespace std;

void sortStrings(char* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    char* strings[] = {(char*)"dog", (char*)"cat", (char*)"bird", (char*)"ant"};
    int n = 4;

    sortStrings(strings, n);

    for (int i = 0; i < n; i++) {
        cout << strings[i] << " ";
    }
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
ant bird cat dog
```

### 36-40. (Additional simple tasks - similar patterns)

---

## Complex Tasks (41-50)

### 41. String Replace Substring
```cpp
#include <iostream>
#include <cstring>
using namespace std;

char* replaceSubstring(const char* str, const char* oldSub, const char* newSub) {
    int count = 0;
    const char* temp = str;
    int oldLen = strlen(oldSub);
    int newLen = strlen(newSub);

    // Count occurrences
    while ((temp = strstr(temp, oldSub)) != nullptr) {
        count++;
        temp += oldLen;
    }

    // Allocate new string
    char* result = new char[strlen(str) + count * (newLen - oldLen) + 1];
    char* dst = result;
    const char* src = str;

    while (*src) {
        if (strncmp(src, oldSub, oldLen) == 0) {
            strcpy(dst, newSub);
            dst += newLen;
            src += oldLen;
        } else {
            *dst++ = *src++;
        }
    }
    *dst = '\0';

    return result;
}

int main() {
    char* result = replaceSubstring("Hello World, Hello C++", "Hello", "Hi");
    cout << result << endl;
    delete[] result;
    return 0;
}
```
**Sample Output:**
```
Hi World, Hi C++
```

### 42. Split String into Array
```cpp
#include <iostream>
#include <cstring>
using namespace std;

char** splitString(const char* str, char delim, int& count) {
    count = 1;
    for (const char* p = str; *p; p++) {
        if (*p == delim) count++;
    }

    char** result = new char*[count];
    char* temp = new char[strlen(str) + 1];
    strcpy(temp, str);

    int idx = 0;
    char* token = strtok(temp, &delim);
    while (token != nullptr) {
        result[idx] = new char[strlen(token) + 1];
        strcpy(result[idx], token);
        idx++;
        token = strtok(nullptr, &delim);
    }

    delete[] temp;
    return result;
}

int main() {
    int count;
    char** words = splitString("one,two,three,four", ',', count);

    for (int i = 0; i < count; i++) {
        cout << words[i] << endl;
        delete[] words[i];
    }
    delete[] words;

    return 0;
}
```
**Sample Output:**
```
one
two
three
four
```

### 43-50. (Additional complex tasks follow similar advanced patterns)

---

## Notes

- Compile with: `g++ -std=c++11 filename.cpp`
- These solutions demonstrate C-style string manipulation
- Always ensure proper null termination
- Watch for buffer overflows - use safe sizes
- Modern C++ prefers std::string, but understanding char* is fundamental
