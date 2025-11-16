
#  C++ Lambda Expressions 

---

##  What Is a Lambda?

A **lambda expression** is an **anonymous function** — a small, inline function you can define on the spot, without giving it a name.

You can store a lambda in a variable, or pass it directly to algorithms like `std::sort`, `std::for_each`, or `std::transform`.

---
> [!NOTE]
> You can reference the following videos:
> - [C++ Lambdas Part 1  Unnamed function objects](https://www.youtube.com/watch?v=qpgJvl3To3M)
> - [C++ Lambdas Part 2 The capture](https://www.youtube.com/watch?v=R1bwTAarnz4)
> - [C++ Lambdas Part 3 Capturing ‘this’  ](https://www.youtube.com/watch?v=W18BxzS42dc)

---
##  Basic Syntax

```cpp
[capture](parameters) -> return_type {
    // body
}
```

Example:

```cpp
#include <iostream>

int main() {
    auto hello = []() {
        std::cout << "Hello, Lambda!" << std::endl;
    };

    hello(); // prints "Hello, Lambda!"
}
```

---

##  Parts of a Lambda

1. **Capture list `[ ]`** — defines what external variables the lambda can access.
2. **Parameters `( )`** — like regular function parameters.
3. **Return type `->`** — optional; usually inferred automatically.
4. **Body `{ }`** — the function’s code.

---

##  Capture Lists Explained

You can use lambdas to access variables from the surrounding scope.

### 1. Capture by Value `[=]`

Copies variables into the lambda.

```cpp
int x = 10;
auto show = [=]() { std::cout << x << std::endl; };
show(); // prints 10
```

Changes inside won’t affect the original variable.

---

### 2. Capture by Reference `[&]`

Uses references, allowing modification.

```cpp
int x = 10;
auto increment = [&]() { x++; };
increment();
std::cout << x << std::endl; // prints 11
```

---

### 3. Capture Specific Variables

```cpp
int a = 1, b = 2;
auto print = [a, &b]() {
    std::cout << a << ", " << b << std::endl;
};
```

* `a` is copied (by value)
* `b` is referenced (by reference)

---

## ⚙️ Parameters and Return Values

```cpp
auto add = [](int a, int b) {
    return a + b;
};

std::cout << add(3, 4) << std::endl; // 7
```

If the return type isn’t clear (like mixing `int` and `double`), specify it explicitly:

```cpp
auto divide = [](int a, int b) -> double {
    return (double)a / b;
};
```

---

##  Using Lambdas with STL Algorithms

### 1. `std::for_each` – Apply a Function to Each Element

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 2, 3, 4};

    std::for_each(nums.begin(), nums.end(), [](int n) {
        std::cout << n * n << " ";
    });
    // Output: 1 4 9 16
}
```

---

### 2. `std::transform` – Modify Elements in Place

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums = {1, 2, 3, 4};

    std::transform(nums.begin(), nums.end(), nums.begin(), [](int n) {
        return n * 10;
    });

    for (int n : nums) std::cout << n << " ";
    // Output: 10 20 30 40
}
```

---

### 3. `std::sort` – Custom Sorting

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums = {5, 2, 8, 1};

    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b; // sort descending
    });

    for (int n : nums) std::cout << n << " ";
    // Output: 8 5 2 1
}
```

---

### 4. `std::count_if` – Conditional Counting

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};

    int evens = std::count_if(nums.begin(), nums.end(), [](int n) {
        return n % 2 == 0;
    });

    std::cout << "Even numbers: " << evens << std::endl; // 3
}
```

---

### 5. `std::remove_if` – Filter Elements

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};

    nums.erase(
        std::remove_if(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; }),
        nums.end()
    );

    for (int n : nums) std::cout << n << " ";
    // Output: 1 3 5
}
```

---

##  Stateful (Closure) Lambdas

Lambdas can remember variables captured from the outside:

```cpp
int count = 0;
auto counter = [&]() {
    count++;
    return count;
};

std::cout << counter() << std::endl; // 1
std::cout << counter() << std::endl; // 2
```

---

##  Summary

| Concept              | Example                                                        | Description               |
| -------------------- | -------------------------------------------------------------- | ------------------------- |
| Basic Lambda         | `[](){}`                                                       | No captures or parameters |
| Capture by Value     | `[=]`                                                          | Copies variables          |
| Capture by Reference | `[&]`                                                          | Uses references           |
| Parameters           | `(int x, int y)`                                               | Like normal functions     |
| Return Type          | `-> double`                                                    | Optional explicit type    |
| In STL               | `std::sort(v.begin(), v.end(), [](int a,int b){return a<b;});` | Inline usage              |

---
