
#  Using Command-Line Arguments in C++

In C++, programs can receive input directly from the command line. This is useful for utilities, file processors, scripts, automation, and more.

## 1. The `main` Function Signature

To access command-line arguments, define `main` with parameters:

```cpp
int main(int argc, char* argv[])
```

### Meaning:

* **`argc`** — *Argument Count*.
  The number of command-line arguments, including the program name.
* **`argv`** — *Argument Vector*.
  An array of C-strings (`char*`) holding each argument.

Example command:

```
./myprogram file.txt 10
```

Values:

* `argc == 3`
* `argv[0]` → `"./myprogram"`
* `argv[1]` → `"file.txt"`
* `argv[2]` → `"10"`

---

## 2. Simple Example: Print All Arguments

```cpp
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Argument count: " << argc << "\n";

    for (int i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "] = " << argv[i] << "\n";
    }

    return 0;
}
```

Compile and run:

```
g++ main.cpp -o demo
./demo hello world
```

Output:

```
Argument count: 3
argv[0] = ./demo
argv[1] = hello
argv[2] = world
```

---

## 3. Converting Arguments to Numbers

Arguments arrive as strings. To convert:

```cpp
#include <iostream>
#include <cstdlib>   // for std::stoi, std::stof

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: calc <a> <b>\n";
        return 1;
    }

    int a = std::stoi(argv[1]);
    int b = std::stoi(argv[2]);

    std::cout << "Sum = " << a + b << "\n";
}
```

Run:

```
./calc 5 7
```

---

## 4. Checking for Missing Arguments

Always protect your program:

```cpp
if (argc < 2) {
    std::cerr << "Error: No filename provided.\n";
    return 1;
}
```

---

## 5. Optional Arguments and Flags

A common pattern:

```cpp
if (std::string(argv[i]) == "--verbose") {
    verbose = true;
}
```

Example:

```
./tool input.txt --verbose --mode=fast
```


