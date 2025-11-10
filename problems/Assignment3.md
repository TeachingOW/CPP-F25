Project Description

This project is a C++ utility that scans a local directory to find duplicate files based on their contents, not filenames.
It works in a single thread for simplicity and reliability.
The program computes a simple hash value for each file’s contents using a custom lightweight hash function.
It maintains a log file that records all processed files, detected duplicates, and progress, allowing the process to resume after interruption.
The focus is on navigating the file system efficiently, reading file contents safely, and implementing a straightforward but effective hashing mechanism.

```c++
unsigned long simple_file_hash(const std::string& file_path) {
    std::ifstream file(file_path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open: " << file_path << std::endl;
        return 0;
    }

    unsigned long hash = 5381;  // Starting seed (DJB2 style)
    char c;

    while (file.get(c)) {
        hash = ((hash << 5) + hash) + static_cast<unsigned char>(c); // hash * 33 + c
    }

    return hash;
}
```