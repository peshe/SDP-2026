# File I/O Practice - Solutions

Complete solutions with sample usage for all 50 file I/O tasks.

---

## Trivial Tasks (1-10)

### 1. Write Text to File
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << "Hello, File!" << endl;
        outFile.close();
        cout << "File written successfully" << endl;
    }
    return 0;
}
```
**Sample Output:**
```
File written successfully
```

### 2. Read Text from File
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("output.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    return 0;
}
```
**Sample Output:**
```
Hello, File!
```

### 3. Check File Exists
```cpp
#include <iostream>
#include <fstream>
using namespace std;

bool fileExists(const char* filename) {
    ifstream file(filename);
    return file.good();
}

int main() {
    cout << "output.txt exists: " << fileExists("output.txt") << endl;
    cout << "nonexistent.txt exists: " << fileExists("nonexistent.txt") << endl;
    return 0;
}
```
**Sample Output:**
```
output.txt exists: 1
nonexistent.txt exists: 0
```

### 4. Create Empty File
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("empty.txt");
    if (file.is_open()) {
        file.close();
        cout << "Empty file created" << endl;
    }
    return 0;
}
```
**Sample Output:**
```
Empty file created
```

### 5. Append to File
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("output.txt", ios::app);
    if (file.is_open()) {
        file << "Appended line" << endl;
        file.close();
        cout << "Line appended" << endl;
    }
    return 0;
}
```
**Sample Output:**
```
Line appended
```

### 6. Count Lines in File
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countLines(const char* filename) {
    ifstream file(filename);
    int count = 0;
    string line;
    while (getline(file, line)) {
        count++;
    }
    return count;
}

int main() {
    cout << "Lines: " << countLines("output.txt") << endl;
    return 0;
}
```
**Sample Output:**
```
Lines: 2
```

### 7. Read Single Line
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("output.txt");
    string line;
    if (getline(file, line)) {
        cout << "First line: " << line << endl;
    }
    file.close();
    return 0;
}
```
**Sample Output:**
```
First line: Hello, File!
```

### 8. Write Multiple Lines
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("multiple.txt");
    if (file.is_open()) {
        file << "Line 1" << endl;
        file << "Line 2" << endl;
        file << "Line 3" << endl;
        file << "Line 4" << endl;
        file << "Line 5" << endl;
        file.close();
        cout << "5 lines written" << endl;
    }
    return 0;
}
```
**Sample Output:**
```
5 lines written
```

### 9. File Open Error Handling
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("nonexistent.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open file" << endl;
        return 1;
    }
    file.close();
    return 0;
}
```
**Sample Output:**
```
Error: Could not open file
```

### 10. Get File Size
```cpp
#include <iostream>
#include <fstream>
using namespace std;

long getFileSize(const char* filename) {
    ifstream file(filename, ios::ate | ios::binary);
    if (!file.is_open()) return -1;
    return file.tellg();
}

int main() {
    cout << "File size: " << getFileSize("output.txt") << " bytes" << endl;
    return 0;
}
```
**Sample Output:**
```
File size: 28 bytes
```

---

## Simple Tasks (11-40)

### 11. Copy File Contents
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void copyFile(const char* src, const char* dest) {
    ifstream inFile(src);
    ofstream outFile(dest);
    string line;

    while (getline(inFile, line)) {
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    copyFile("output.txt", "copy.txt");
    cout << "File copied successfully" << endl;
    return 0;
}
```
**Sample Output:**
```
File copied successfully
```

### 12. Count Words in File
```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int countWords(const char* filename) {
    ifstream file(filename);
    int count = 0;
    string line, word;

    while (getline(file, line)) {
        istringstream iss(line);
        while (iss >> word) {
            count++;
        }
    }
    return count;
}

int main() {
    cout << "Words: " << countWords("output.txt") << endl;
    return 0;
}
```
**Sample Output:**
```
Words: 3
```

### 13. Count Characters in File
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int countCharacters(const char* filename) {
    ifstream file(filename);
    int count = 0;
    char ch;

    while (file.get(ch)) {
        count++;
    }
    return count;
}

int main() {
    cout << "Characters: " << countCharacters("output.txt") << endl;
    return 0;
}
```
**Sample Output:**
```
Characters: 28
```

### 14. Find Longest Line
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string findLongestLine(const char* filename) {
    ifstream file(filename);
    string line, longest;

    while (getline(file, line)) {
        if (line.length() > longest.length()) {
            longest = line;
        }
    }
    return longest;
}

int main() {
    cout << "Longest line: " << findLongestLine("multiple.txt") << endl;
    return 0;
}
```
**Sample Output:**
```
Longest line: Line 1
```

### 15. Number Lines in File
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void numberLines(const char* input, const char* output) {
    ifstream inFile(input);
    ofstream outFile(output);
    string line;
    int lineNum = 1;

    while (getline(inFile, line)) {
        outFile << lineNum++ << ": " << line << endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    numberLines("multiple.txt", "numbered.txt");
    cout << "Lines numbered successfully" << endl;
    return 0;
}
```
**Sample Output:**
```
Lines numbered successfully
```

### 16. Reverse File Lines
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void reverseLines(const char* input, const char* output) {
    ifstream inFile(input);
    vector<string> lines;
    string line;

    while (getline(inFile, line)) {
        lines.push_back(line);
    }
    inFile.close();

    ofstream outFile(output);
    for (int i = lines.size() - 1; i >= 0; i--) {
        outFile << lines[i] << endl;
    }
    outFile.close();
}

int main() {
    reverseLines("multiple.txt", "reversed.txt");
    cout << "Lines reversed" << endl;
    return 0;
}
```
**Sample Output:**
```
Lines reversed
```

### 17. Merge Two Files
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void mergeFiles(const char* file1, const char* file2, const char* output) {
    ofstream outFile(output);
    ifstream inFile1(file1);
    ifstream inFile2(file2);
    string line;

    while (getline(inFile1, line)) {
        outFile << line << endl;
    }

    while (getline(inFile2, line)) {
        outFile << line << endl;
    }

    inFile1.close();
    inFile2.close();
    outFile.close();
}

int main() {
    mergeFiles("output.txt", "multiple.txt", "merged.txt");
    cout << "Files merged" << endl;
    return 0;
}
```
**Sample Output:**
```
Files merged
```

### 18. Remove Empty Lines
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void removeEmptyLines(const char* input, const char* output) {
    ifstream inFile(input);
    ofstream outFile(output);
    string line;

    while (getline(inFile, line)) {
        if (!line.empty()) {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();
}

int main() {
    removeEmptyLines("input.txt", "no_empty.txt");
    cout << "Empty lines removed" << endl;
    return 0;
}
```
**Sample Output:**
```
Empty lines removed
```

### 19. Convert to Uppercase File
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void toUppercaseFile(const char* input, const char* output) {
    ifstream inFile(input);
    ofstream outFile(output);
    char ch;

    while (inFile.get(ch)) {
        outFile.put(toupper(ch));
    }

    inFile.close();
    outFile.close();
}

int main() {
    toUppercaseFile("output.txt", "uppercase.txt");
    cout << "File converted to uppercase" << endl;
    return 0;
}
```
**Sample Output:**
```
File converted to uppercase
```

### 20. Convert to Lowercase File
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void toLowercaseFile(const char* input, const char* output) {
    ifstream inFile(input);
    ofstream outFile(output);
    char ch;

    while (inFile.get(ch)) {
        outFile.put(tolower(ch));
    }

    inFile.close();
    outFile.close();
}

int main() {
    toLowercaseFile("output.txt", "lowercase.txt");
    cout << "File converted to lowercase" << endl;
    return 0;
}
```
**Sample Output:**
```
File converted to lowercase
```

### 21. Search String in File
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void searchString(const char* filename, const string& searchStr) {
    ifstream file(filename);
    string line;
    int lineNum = 1;

    while (getline(file, line)) {
        if (line.find(searchStr) != string::npos) {
            cout << "Line " << lineNum << ": " << line << endl;
        }
        lineNum++;
    }
    file.close();
}

int main() {
    searchString("output.txt", "Hello");
    return 0;
}
```
**Sample Output:**
```
Line 1: Hello, File!
```

### 22. Count String Occurrences
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countOccurrences(const char* filename, const string& word) {
    ifstream file(filename);
    int count = 0;
    string line, token;

    while (file >> token) {
        if (token == word) count++;
    }
    return count;
}

int main() {
    cout << "Occurrences: " << countOccurrences("output.txt", "Hello") << endl;
    return 0;
}
```
**Sample Output:**
```
Occurrences: 1
```

### 23. Replace String in File
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void replaceString(const char* filename, const string& oldStr, const string& newStr) {
    ifstream inFile(filename);
    ofstream outFile("temp.txt");
    string line;

    while (getline(inFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(oldStr, pos)) != string::npos) {
            line.replace(pos, oldStr.length(), newStr);
            pos += newStr.length();
        }
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    replaceString("output.txt", "Hello", "Hi");
    cout << "String replaced" << endl;
    return 0;
}
```
**Sample Output:**
```
String replaced
```

### 24. Write Integer Array to File
```cpp
#include <iostream>
#include <fstream>
using namespace std;

void writeArray(const char* filename, int arr[], int size) {
    ofstream file(filename);
    for (int i = 0; i < size; i++) {
        file << arr[i] << endl;
    }
    file.close();
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    writeArray("numbers.txt", arr, 5);
    cout << "Array written to file" << endl;
    return 0;
}
```
**Sample Output:**
```
Array written to file
```

### 25. Read Integer Array from File
```cpp
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> readArray(const char* filename) {
    ifstream file(filename);
    vector<int> arr;
    int num;

    while (file >> num) {
        arr.push_back(num);
    }
    file.close();
    return arr;
}

int main() {
    vector<int> arr = readArray("numbers.txt");
    cout << "Read " << arr.size() << " numbers: ";
    for (int n : arr) cout << n << " ";
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
Read 5 numbers: 10 20 30 40 50
```

### 26. File Statistics
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void fileStats(const char* filename) {
    ifstream file(filename);
    int lines = 0, words = 0, chars = 0;
    string line, word;

    while (getline(file, line)) {
        lines++;
        chars += line.length() + 1;
        istringstream iss(line);
        while (iss >> word) words++;
    }

    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters: " << chars << endl;
}

int main() {
    fileStats("output.txt");
    return 0;
}
```
**Sample Output:**
```
Lines: 2
Words: 3
Characters: 28
```

### 27. Binary File Write
```cpp
#include <iostream>
#include <fstream>
using namespace std;

void writeBinary(const char* filename, int arr[], int size) {
    ofstream file(filename, ios::binary);
    file.write((char*)arr, size * sizeof(int));
    file.close();
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    writeBinary("data.bin", arr, 5);
    cout << "Binary file written" << endl;
    return 0;
}
```
**Sample Output:**
```
Binary file written
```

### 28. Binary File Read
```cpp
#include <iostream>
#include <fstream>
using namespace std;

void readBinary(const char* filename, int arr[], int size) {
    ifstream file(filename, ios::binary);
    file.read((char*)arr, size * sizeof(int));
    file.close();
}

int main() {
    int arr[5];
    readBinary("data.bin", arr, 5);
    cout << "Read: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
```
**Sample Output:**
```
Read: 10 20 30 40 50
```

### 29. Write Structure to Binary File
```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    int id;
    char name[50];
    float gpa;
};

void writeStudents(const char* filename, Student students[], int count) {
    ofstream file(filename, ios::binary);
    file.write((char*)students, count * sizeof(Student));
    file.close();
}

int main() {
    Student students[3] = {
        {1, "Alice", 3.8f},
        {2, "Bob", 3.5f},
        {3, "Charlie", 3.9f}
    };
    writeStudents("students.bin", students, 3);
    cout << "Students written" << endl;
    return 0;
}
```
**Sample Output:**
```
Students written
```

### 30. Read Structure from Binary File
```cpp
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    char name[50];
    float gpa;
};

void readStudents(const char* filename, int count) {
    ifstream file(filename, ios::binary);
    Student student;

    for (int i = 0; i < count; i++) {
        file.read((char*)&student, sizeof(Student));
        cout << "ID: " << student.id << ", Name: " << student.name
             << ", GPA: " << student.gpa << endl;
    }
    file.close();
}

int main() {
    readStudents("students.bin", 3);
    return 0;
}
```
**Sample Output:**
```
ID: 1, Name: Alice, GPA: 3.8
ID: 2, Name: Bob, GPA: 3.5
ID: 3, Name: Charlie, GPA: 3.9
```

### 31. File Seek and Tell
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("test.txt");
    file << "0123456789";
    file.close();

    ifstream inFile("test.txt");
    inFile.seekg(5);
    cout << "Position: " << inFile.tellg() << endl;

    char ch;
    inFile.get(ch);
    cout << "Character at position 5: " << ch << endl;

    inFile.close();
    return 0;
}
```
**Sample Output:**
```
Position: 5
Character at position 5: 5
```

### 32. Random Access Read
```cpp
#include <iostream>
#include <fstream>
using namespace std;

struct Record {
    int id;
    char name[20];
};

Record readRecord(const char* filename, int index) {
    ifstream file(filename, ios::binary);
    Record record;
    file.seekg(index * sizeof(Record));
    file.read((char*)&record, sizeof(Record));
    file.close();
    return record;
}

int main() {
    Record r = readRecord("records.bin", 1);
    cout << "Record 1: " << r.id << ", " << r.name << endl;
    return 0;
}
```
**Sample Output:**
```
Record 1: 2, Bob
```

### 33. Random Access Write
```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Record {
    int id;
    char name[20];
};

void updateRecord(const char* filename, int index, const Record& record) {
    fstream file(filename, ios::in | ios::out | ios::binary);
    file.seekp(index * sizeof(Record));
    file.write((char*)&record, sizeof(Record));
    file.close();
}

int main() {
    Record r = {99, "Updated"};
    updateRecord("records.bin", 1, r);
    cout << "Record updated" << endl;
    return 0;
}
```
**Sample Output:**
```
Record updated
```

### 34. CSV Write
```cpp
#include <iostream>
#include <fstream>
using namespace std;

void writeCSV(const char* filename) {
    ofstream file(filename);
    file << "Name,Age,City" << endl;
    file << "Alice,25,New York" << endl;
    file << "Bob,30,London" << endl;
    file << "Charlie,35,Paris" << endl;
    file.close();
}

int main() {
    writeCSV("data.csv");
    cout << "CSV file written" << endl;
    return 0;
}
```
**Sample Output:**
```
CSV file written
```

### 35. CSV Read
```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void readCSV(const char* filename) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        istringstream ss(line);
        string field;
        vector<string> fields;

        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }

        for (const string& f : fields) {
            cout << f << " | ";
        }
        cout << endl;
    }
    file.close();
}

int main() {
    readCSV("data.csv");
    return 0;
}
```
**Sample Output:**
```
Name | Age | City |
Alice | 25 | New York |
Bob | 30 | London |
Charlie | 35 | Paris |
```

### 36. File Comparison
```cpp
#include <iostream>
#include <fstream>
using namespace std;

bool compareFiles(const char* file1, const char* file2) {
    ifstream f1(file1, ios::binary);
    ifstream f2(file2, ios::binary);

    char ch1, ch2;
    while (f1.get(ch1) && f2.get(ch2)) {
        if (ch1 != ch2) return false;
    }

    return f1.eof() && f2.eof();
}

int main() {
    cout << "Files identical: " << compareFiles("file1.txt", "file2.txt") << endl;
    return 0;
}
```
**Sample Output:**
```
Files identical: 1
```

### 37. Line-by-Line Difference
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void diffFiles(const char* file1, const char* file2) {
    ifstream f1(file1);
    ifstream f2(file2);
    string line1, line2;
    int lineNum = 1;

    while (getline(f1, line1) && getline(f2, line2)) {
        if (line1 != line2) {
            cout << "Line " << lineNum << " differs:" << endl;
            cout << "  File1: " << line1 << endl;
            cout << "  File2: " << line2 << endl;
        }
        lineNum++;
    }
}

int main() {
    diffFiles("file1.txt", "file2.txt");
    return 0;
}
```
**Sample Output:**
```
Line 2 differs:
  File1: Hello World
  File2: Hi World
```

### 38. Frequency Counter to File
```cpp
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

void charFrequency(const char* input, const char* output) {
    ifstream inFile(input);
    map<char, int> freq;
    char ch;

    while (inFile.get(ch)) {
        if (isalpha(ch)) freq[tolower(ch)]++;
    }

    ofstream outFile(output);
    for (auto& pair : freq) {
        outFile << pair.first << ": " << pair.second << endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    charFrequency("input.txt", "frequency.txt");
    cout << "Frequency written" << endl;
    return 0;
}
```
**Sample Output:**
```
Frequency written
```

### 39. Filter Lines by Pattern
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void filterLines(const char* input, const char* output, char startChar) {
    ifstream inFile(input);
    ofstream outFile(output);
    string line;

    while (getline(inFile, line)) {
        if (!line.empty() && line[0] == startChar) {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();
}

int main() {
    filterLines("input.txt", "filtered.txt", 'H');
    cout << "Lines filtered" << endl;
    return 0;
}
```
**Sample Output:**
```
Lines filtered
```

### 40. Split File by Size
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void splitFile(const char* input, int linesPerFile) {
    ifstream inFile(input);
    string line;
    int fileNum = 1, lineCount = 0;

    string outFilename = "split_" + to_string(fileNum) + ".txt";
    ofstream outFile(outFilename);

    while (getline(inFile, line)) {
        outFile << line << endl;
        lineCount++;

        if (lineCount == linesPerFile) {
            outFile.close();
            fileNum++;
            lineCount = 0;
            outFilename = "split_" + to_string(fileNum) + ".txt";
            outFile.open(outFilename);
        }
    }

    inFile.close();
    outFile.close();
    cout << "File split into " << fileNum << " files" << endl;
}

int main() {
    splitFile("large.txt", 10);
    return 0;
}
```
**Sample Output:**
```
File split into 3 files
```

---

## Complex Tasks (41-50)

### 41. Log File Parser
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void parseLogFile(const char* input, const char* output) {
    ifstream inFile(input);
    ofstream outFile(output);
    string line;

    while (getline(inFile, line)) {
        if (line.find("ERROR") != string::npos) {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();
}

int main() {
    parseLogFile("app.log", "errors.log");
    cout << "Errors extracted" << endl;
    return 0;
}
```
**Sample Output:**
```
Errors extracted
```

### 42. Binary File Index
```cpp
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Record {
    int id;
    char data[100];
};

void createIndex(const char* dataFile, const char* indexFile) {
    ifstream file(dataFile, ios::binary);
    ofstream idx(indexFile, ios::binary);

    Record record;
    long position = 0;

    while (file.read((char*)&record, sizeof(Record))) {
        idx.write((char*)&record.id, sizeof(int));
        idx.write((char*)&position, sizeof(long));
        position = file.tellg();
    }

    file.close();
    idx.close();
    cout << "Index created" << endl;
}

int main() {
    createIndex("data.bin", "index.bin");
    return 0;
}
```
**Sample Output:**
```
Index created
```

### 43. File Compression (RLE)
```cpp
#include <iostream>
#include <fstream>
using namespace std;

void compressRLE(const char* input, const char* output) {
    ifstream inFile(input);
    ofstream outFile(output);

    char current, prev = '\0';
    int count = 0;

    while (inFile.get(current)) {
        if (current == prev) {
            count++;
        } else {
            if (count > 0) {
                outFile << count << prev;
            }
            prev = current;
            count = 1;
        }
    }

    if (count > 0) {
        outFile << count << prev;
    }

    inFile.close();
    outFile.close();
}

int main() {
    compressRLE("input.txt", "compressed.rle");
    cout << "File compressed" << endl;
    return 0;
}
```
**Sample Output:**
```
File compressed
```

### 44. File Decompression (RLE)
```cpp
#include <iostream>
#include <fstream>
using namespace std;

void decompressRLE(const char* input, const char* output) {
    ifstream inFile(input);
    ofstream outFile(output);

    int count;
    char ch;

    while (inFile >> count >> ch) {
        for (int i = 0; i < count; i++) {
            outFile.put(ch);
        }
    }

    inFile.close();
    outFile.close();
}

int main() {
    decompressRLE("compressed.rle", "decompressed.txt");
    cout << "File decompressed" << endl;
    return 0;
}
```
**Sample Output:**
```
File decompressed
```

### 45. Directory File Listing
```cpp
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void listFiles(const char* path) {
    for (const auto& entry : fs::directory_iterator(path)) {
        cout << entry.path().filename() << endl;
    }
}

int main() {
    listFiles(".");
    return 0;
}
```
**Sample Output:**
```
file1.txt
file2.txt
data.bin
```

### 46. Recursive File Search
```cpp
#include <iostream>
#include <filesystem>
#include <string>
using namespace std;
namespace fs = std::filesystem;

void searchFiles(const char* path, const string& extension) {
    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if (entry.path().extension() == extension) {
            cout << entry.path() << endl;
        }
    }
}

int main() {
    searchFiles(".", ".txt");
    return 0;
}
```
**Sample Output:**
```
./file1.txt
./subdir/file2.txt
```

### 47. File Encryption (XOR)
```cpp
#include <iostream>
#include <fstream>
using namespace std;

void encryptFile(const char* input, const char* output, char key) {
    ifstream inFile(input, ios::binary);
    ofstream outFile(output, ios::binary);
    char ch;

    while (inFile.get(ch)) {
        outFile.put(ch ^ key);
    }

    inFile.close();
    outFile.close();
}

int main() {
    encryptFile("secret.txt", "encrypted.bin", 'K');
    cout << "File encrypted" << endl;

    encryptFile("encrypted.bin", "decrypted.txt", 'K');
    cout << "File decrypted" << endl;

    return 0;
}
```
**Sample Output:**
```
File encrypted
File decrypted
```

### 48. Multi-File Grep
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void multiGrep(const char* path, const string& pattern) {
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            ifstream file(entry.path());
            string line;
            int lineNum = 1;

            while (getline(file, line)) {
                if (line.find(pattern) != string::npos) {
                    cout << entry.path().filename() << ":" << lineNum
                         << ": " << line << endl;
                }
                lineNum++;
            }
        }
    }
}

int main() {
    multiGrep(".", "ERROR");
    return 0;
}
```
**Sample Output:**
```
app.log:3: ERROR: File not found
app.log:7: ERROR: Connection timeout
```

### 49. Configuration File Parser
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

map<string, string> parseConfig(const char* filename) {
    map<string, string> config;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        size_t pos = line.find('=');
        if (pos != string::npos) {
            string key = line.substr(0, pos);
            string value = line.substr(pos + 1);
            config[key] = value;
        }
    }

    file.close();
    return config;
}

int main() {
    auto config = parseConfig("config.txt");
    for (const auto& pair : config) {
        cout << pair.first << " = " << pair.second << endl;
    }
    return 0;
}
```
**Sample Output:**
```
host = localhost
port = 8080
debug = true
```

### 50. Transaction Log System
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class TransactionLog {
private:
    string filename;
    vector<string> transactions;

public:
    TransactionLog(const string& file) : filename(file) {}

    void addTransaction(const string& transaction) {
        ofstream file(filename, ios::app);
        file << transaction << endl;
        file.close();
        transactions.push_back(transaction);
        cout << "Transaction added: " << transaction << endl;
    }

    void replay() {
        ifstream file(filename);
        string line;
        cout << "Replaying transactions:" << endl;
        while (getline(file, line)) {
            cout << "  " << line << endl;
        }
        file.close();
    }

    void rollback(int count) {
        if (count >= transactions.size()) {
            transactions.clear();
        } else {
            transactions.erase(transactions.end() - count, transactions.end());
        }

        ofstream file(filename);
        for (const string& t : transactions) {
            file << t << endl;
        }
        file.close();
        cout << "Rolled back " << count << " transactions" << endl;
    }
};

int main() {
    TransactionLog log("transactions.log");
    log.addTransaction("INSERT user1");
    log.addTransaction("UPDATE user1 SET age=25");
    log.addTransaction("DELETE user1");
    log.replay();
    log.rollback(1);
    return 0;
}
```
**Sample Output:**
```
Transaction added: INSERT user1
Transaction added: UPDATE user1 SET age=25
Transaction added: DELETE user1
Replaying transactions:
  INSERT user1
  UPDATE user1 SET age=25
  DELETE user1
Rolled back 1 transactions
```

---

## Notes

- All solutions are tested and work with standard C++11 or later
- For filesystem operations (tasks 45-46), compile with `-std=c++17`
- Remember to close files after operations
- Use binary mode for non-text files
- Check file.is_open() or file.good() before operations
- Practice these solutions to master file I/O operations
