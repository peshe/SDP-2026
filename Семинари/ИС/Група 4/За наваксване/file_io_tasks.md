# File I/O Practice Tasks (50 Tasks)

Master file input/output operations through repetition and progressive complexity.

---

## Trivial Tasks (1-10)

### 1. Write Text to File
**Difficulty:** Trivial
**Task:** Create a program that writes "Hello, File!" to a text file using ofstream or fprintf.

### 2. Read Text from File
**Difficulty:** Trivial
**Task:** Read and print the entire contents of a text file to console.

### 3. Check File Exists
**Difficulty:** Trivial
**Task:** Write a function that checks if a file exists before attempting to open it.

### 4. Create Empty File
**Difficulty:** Trivial
**Task:** Create an empty file programmatically and verify it was created.

### 5. Append to File
**Difficulty:** Trivial
**Task:** Open a file in append mode and add a new line of text without overwriting existing content.

### 6. Count Lines in File
**Difficulty:** Trivial
**Task:** Count the number of lines in a text file.

### 7. Read Single Line
**Difficulty:** Trivial
**Task:** Read and print only the first line from a file.

### 8. Write Multiple Lines
**Difficulty:** Trivial
**Task:** Write 5 different lines of text to a file, each on a new line.

### 9. File Open Error Handling
**Difficulty:** Trivial
**Task:** Attempt to open a non-existent file and properly handle the error.

### 10. Get File Size
**Difficulty:** Trivial
**Task:** Write a function that returns the size of a file in bytes.

---

## Simple Tasks (11-40)

### 11. Copy File Contents
**Difficulty:** Simple
**Task:** Copy the entire contents of one file to another file.

### 12. Count Words in File
**Difficulty:** Simple
**Task:** Count the total number of words in a text file.

### 13. Count Characters in File
**Difficulty:** Simple
**Task:** Count total characters (including spaces) in a text file.

### 14. Find Longest Line
**Difficulty:** Simple
**Task:** Find and print the longest line in a text file.

### 15. Number Lines in File
**Difficulty:** Simple
**Task:** Read a file and write it to a new file with line numbers prepended.

### 16. Reverse File Lines
**Difficulty:** Simple
**Task:** Read a file and write its lines in reverse order to a new file.

### 17. Merge Two Files
**Difficulty:** Simple
**Task:** Merge the contents of two files into a third file.

### 18. Remove Empty Lines
**Difficulty:** Simple
**Task:** Read a file and write to a new file with all empty lines removed.

### 19. Convert to Uppercase File
**Difficulty:** Simple
**Task:** Read a file and write all content to uppercase in a new file.

### 20. Convert to Lowercase File
**Difficulty:** Simple
**Task:** Read a file and write all content to lowercase in a new file.

### 21. Search String in File
**Difficulty:** Simple
**Task:** Search for a specific string in a file and print all lines containing it.

### 22. Count String Occurrences
**Difficulty:** Simple
**Task:** Count how many times a specific word appears in a file.

### 23. Replace String in File
**Difficulty:** Simple
**Task:** Replace all occurrences of one string with another in a file.

### 24. Write Integer Array to File
**Difficulty:** Simple
**Task:** Write an array of integers to a file (one per line).

### 25. Read Integer Array from File
**Difficulty:** Simple
**Task:** Read integers from a file into an array/vector.

### 26. File Statistics
**Difficulty:** Simple
**Task:** Calculate and display lines, words, and characters count (like wc command).

### 27. Binary File Write
**Difficulty:** Simple
**Task:** Write an array of integers to a binary file using fwrite or write().

### 28. Binary File Read
**Difficulty:** Simple
**Task:** Read integers from a binary file into an array.

### 29. Write Structure to Binary File
**Difficulty:** Simple
**Task:** Create a struct (e.g., Student), write multiple instances to a binary file.

### 30. Read Structure from Binary File
**Difficulty:** Simple
**Task:** Read struct instances from a binary file and display them.

### 31. File Seek and Tell
**Difficulty:** Simple
**Task:** Use seekg/seekp to jump to specific positions in a file and read/write there.

### 32. Random Access Read
**Difficulty:** Simple
**Task:** Read the nth record from a binary file of fixed-size records.

### 33. Random Access Write
**Difficulty:** Simple
**Task:** Update the nth record in a binary file without rewriting the entire file.

### 34. CSV Write
**Difficulty:** Simple
**Task:** Write data to a CSV file with comma-separated values.

### 35. CSV Read
**Difficulty:** Simple
**Task:** Read and parse a simple CSV file (no quoted fields) into a 2D structure.

### 36. File Comparison
**Difficulty:** Simple
**Task:** Compare two files byte-by-byte and report if they're identical.

### 37. Line-by-Line Difference
**Difficulty:** Simple
**Task:** Compare two text files line-by-line and print differences.

### 38. Frequency Counter to File
**Difficulty:** Simple
**Task:** Count character frequency in a file and write results to another file.

### 39. Filter Lines by Pattern
**Difficulty:** Simple
**Task:** Read a file and write only lines starting with a specific character to a new file.

### 40. Split File by Size
**Difficulty:** Simple
**Task:** Split a large text file into multiple smaller files of specified line count.

---

## Complex Tasks (41-50)

### 41. Log File Parser
**Difficulty:** Complex
**Task:** Parse a log file with timestamp, level, and message; extract all ERROR entries to a new file.

### 42. Binary File Index
**Difficulty:** Complex
**Task:** Create an index file that stores positions of records in a binary file for fast lookup.

### 43. File Compression (RLE)
**Difficulty:** Complex
**Task:** Implement run-length encoding to compress a text file, write compressed version.

### 44. File Decompression (RLE)
**Difficulty:** Complex
**Task:** Decompress a run-length encoded file back to original.

### 45. Directory File Listing
**Difficulty:** Complex
**Task:** List all files in a directory (use filesystem library or platform-specific APIs).

### 46. Recursive File Search
**Difficulty:** Complex
**Task:** Recursively search for files with specific extension in directory tree.

### 47. File Encryption (XOR)
**Difficulty:** Complex
**Task:** Implement simple XOR encryption to encrypt/decrypt a file with a key.

### 48. Multi-File Grep
**Difficulty:** Complex
**Task:** Search for a pattern across multiple files and report filename, line number, and content.

### 49. Configuration File Parser
**Difficulty:** Complex
**Task:** Parse a key=value configuration file, support comments (#), store in a map/struct.

### 50. Transaction Log System
**Difficulty:** Complex
**Task:** Implement a simple transaction log: write operations to file, read and replay them, support rollback.

---

## Learning Objectives

By completing these tasks, you will develop instinctive understanding of:
- File streams (ifstream, ofstream, fstream)
- C-style file operations (fopen, fread, fwrite, fclose)
- Text vs binary file modes
- File positioning (seek, tell)
- Error handling and file state checking
- Sequential vs random access patterns
- Structured data serialization
- File parsing and data extraction
- Buffered vs unbuffered I/O
- Platform-independent file operations
- File system operations (when applicable)

**Practice Tip:** Start with text files using C++ streams, then move to binary files and C-style I/O. Understanding file operations is crucial for real-world applications. Repeat until file I/O becomes natural.
