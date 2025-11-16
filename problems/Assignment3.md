
##  Assignment 3 – Duplicate File Scanner 

This project is a C++ command-line utility that scans a directory tree and identifies duplicate files **based on their contents**, not their filenames or locations.

The program reads the contents of each file and computes a lightweight hash value using a simple custom hashing function. Files that produce the same hash are considered potential duplicates. If desired, the program can also perform a full byte-by-byte comparison to confirm duplicates.



> [!Note]
> You may base your implementation on the following reference code:
> [https://raw.githubusercontent.com/TeachingOW/CPP-F25/refs/heads/main/code/filematcher3.cpp](https://raw.githubusercontent.com/TeachingOW/CPP-F25/refs/heads/main/code/filematcher3.cpp)



The focus of this assignment is on:

* navigating and iterating through the filesystem using C++17 `std::filesystem`
* implementing a simple custom hashing mechanism
* designing data structures to track hashes, filenames, and duplicate groups
* handling large directory trees gracefully
* allow to get the argument from the command line

## Optional Enhancements:

1- **Progress Logging and Resumability** 
    Implement an optional logging mechanism that records processed files, detected duplicates, and the current scan state. This log should allow the program to resume from where it left off after an interruption.

2- **Preview-Before-Delete and Retention Policy** 
    Add an option to display a list of duplicate files that are candidates for deletion. Include a feature that lets the user choose a deletion policy—for example, automatically removing the oldest copy.

3- **Lazy Hash Computation for Performance Optimization** 
    Improve performance by avoiding unnecessary hashing. Instead of hashing every file immediately, compute the hash only for files that share the same file size. This reduces the total number of hash operations and speeds up duplicate detection.

4- **Progress Bar Display** 
    Add a console-based progress bar that updates as files are scanned. The progress bar should reflect the percentage of files processed and provide visual feedback during long directory scans.