

# 📘 Reading and Writing Files in C++ (Text, Binary, and Directories)

File handling in C++ is done using the `<fstream>` and `<filesystem>` libraries.
The `<fstream>` library handles reading and writing, while `<filesystem>` (C++17+) handles directory and file management.

> [!NOTE]
> You can reference  the following videos:
> - Read and Write Text data https://www.youtube.com/watch?v=VsDGQug-5rA
> - Read and Write Binary data https://www.youtube.com/watch?v=pnoEgNt9B4E
> - Read and Write struct https://www.youtube.com/watch?v=lmcK9_0l73Y 


---

## 1. File Stream Classes

| Class      | Purpose                 |
| ---------- | ----------------------- |
| `ifstream` | Read from files         |
| `ofstream` | Write to files          |
| `fstream`  | Read and write to files |

Include `<fstream>` when working with these classes.

---

## 2. Writing and Reading Text Files

Text files store human-readable data (ASCII/UTF-8).

### ✏️ Writing to a Text File

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("example.txt");
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    outFile << "Hello, World!" << std::endl;
    outFile << "This is a sample text file." << std::endl;

    outFile.close();
    return 0;
}
```

### 📖 Reading from a Text File

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile("example.txt");
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    inFile.close();
    return 0;
}
```

---

## 3. Getting the Size of a File

You can determine file size using `seekg()` and `tellg()`.

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inFile("example.txt", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    inFile.seekg(0, std::ios::end);
    std::streampos fileSize = inFile.tellg();
    std::cout << "File size: " << fileSize << " bytes" << std::endl;

    inFile.close();
    return 0;
}
```

---

## 4. Writing and Reading Binary Files

Binary files store raw byte data, which is more efficient for structured information.

### ✏️ Writing a Binary File

```cpp
#include <iostream>
#include <fstream>

struct Data {
    int id;
    char name[20];
    double score;
};

int main() {
    std::ofstream outFile("data.bin", std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    Data record = {1, "Alice", 95.5};
    outFile.write(reinterpret_cast<char*>(&record), sizeof(record));

    outFile.close();
    return 0;
}
```

### 📖 Reading a Binary File (with EOF Handling)

```cpp
#include <iostream>
#include <fstream>

struct Data {
    int id;
    char name[20];
    double score;
};

int main() {
    std::ifstream inFile("data.bin", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    Data record;
    while (inFile.read(reinterpret_cast<char*>(&record), sizeof(record))) {
        std::cout << "ID: " << record.id
                  << "\nName: " << record.name
                  << "\nScore: " << record.score << "\n\n";
    }

    inFile.close();
    return 0;
}
```

---

## 5. Appending to Files

```cpp
#include <fstream>
#include <iostream>

int main() {
    std::ofstream outFile("example.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    outFile << "Appending new content." << std::endl;
    outFile.close();
    return 0;
}
```

---

## 6. Random Access in Binary Files

Use `seekg()` and `seekp()` to move the read/write pointers:

```cpp
file.seekg(position, std::ios::beg); // Move read pointer
file.seekp(position, std::ios::beg); // Move write pointer
```

This lets you jump to specific positions in a file (e.g., record #N).

---

## 7. Iterating Over Files in a Directory

C++17’s `<filesystem>` makes directory traversal easy.

### 📁 Listing All Files in a Directory

```cpp
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    std::string path = "."; // Current directory
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            std::cout << entry.path() << std::endl;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }

    return 0;
}
```

### 📂 Filtering `.txt` Files

```cpp
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    std::string path = ".";

    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.path().extension() == ".txt") {
            std::cout << "Text file: " << entry.path().filename() << std::endl;
        }
    }

    return 0;
}
```

### 🔍 Recursive Directory Iteration

```cpp
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    std::string path = ".";

    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        std::cout << entry.path() << std::endl;
    }

    return 0;
}
```

---

## 8. Reading All `.txt` Files in a Directory

This combines directory iteration with file reading.

```cpp
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    std::string path = "."; // Current directory

    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.path().extension() == ".txt") {
            std::cout << "\n--- Reading: " << entry.path().filename() << " ---\n";

            std::ifstream inFile(entry.path());
            if (!inFile) {
                std::cerr << "Error opening file: " << entry.path() << std::endl;
                continue;
            }

            std::string line;
            while (std::getline(inFile, line)) {
                std::cout << line << std::endl;
            }

            inFile.close();
        }
    }

    return 0;
}
```

### ✅ Output Example

If your directory has:

```
example.txt
notes.txt
data.bin
```

Output:

```
--- Reading: example.txt ---
Hello, World!
This is a sample text file.

--- Reading: notes.txt ---
C++ File Handling Example
```

---

## 9. Summary

| Operation           | Library        | Class / Function     | Notes                      |
| ------------------- | -------------- | -------------------- | -------------------------- |
| Write Text          | `<fstream>`    | `ofstream`           | Use `<<`                   |
| Read Text           | `<fstream>`    | `ifstream`           | Use `getline()`            |
| Write Binary        | `<fstream>`    | `ofstream`           | Use `write()`              |
| Read Binary         | `<fstream>`    | `ifstream`           | Use `read()`               |
| Append              | `<fstream>`    | `ofstream`           | Open with `std::ios::app`  |
| File Size           | `<fstream>`    | `seekg()`, `tellg()` | Works for all file types   |
| Random Access       | `<fstream>`    | `seekg()`, `seekp()` | Jump to specific positions |
| Directory Iteration | `<filesystem>` | `directory_iterator` | Traverse files and folders |

---

