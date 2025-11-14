
# **Assignment 3 – Duplicate File Scanner **

This project is a C++ command-line utility that scans a directory tree and identifies duplicate files **based on their contents**, not their filenames or locations.

The program reads the contents of each file and computes a lightweight hash value using a simple custom hashing function. Files that produce the same hash are considered potential duplicates. If desired, the program can also perform a full byte-by-byte comparison to confirm duplicates.

The utility maintains a **log file** that records:

* all files processed
* computed hash values
* detected duplicates
* errors (e.g., unreadable files)
* progress information

This log allows the program to be re-run and **resume processing** after interruptions without rescanning already-processed files.

The focus of this assignment is on:

* navigating and iterating through the filesystem using C++17 `std::filesystem`
* reading file contents safely and efficiently
* implementing a simple custom hashing mechanism
* designing data structures to track hashes, filenames, and duplicate groups
* handling large directory trees gracefully
* writing and reading from a structured log file

> [!Note]
> You may base your implementation on the following reference code:
> [https://raw.githubusercontent.com/TeachingOW/CPP-F25/refs/heads/main/code/filematcher3.cpp](https://raw.githubusercontent.com/TeachingOW/CPP-F25/refs/heads/main/code/filematcher3.cpp)

---
