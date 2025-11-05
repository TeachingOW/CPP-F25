## 🧠 What Are Smart Pointers?

In C++, **smart pointers** are objects that manage the lifetime of dynamically allocated memory (created with `new`).
They automatically **free the memory** when it’s no longer needed — preventing **memory leaks**.

Smart pointers are part of the **C++ Standard Library**, in the `<memory>` header.

---

## 🔧 Why Use Smart Pointers?

Before smart pointers:

```cpp
int* ptr = new int(10);
std::cout << *ptr << std::endl;
delete ptr; // must remember this!
```

If you forget `delete`, you get a **memory leak**.
If you `delete` twice or use the pointer after deleting it, you get **undefined behavior**.

Smart pointers solve all that automatically.

---

## 🪄 Types of Smart Pointers

There are **three main types**:

### 1. `std::unique_ptr` – Exclusive Ownership

Only one pointer can own a resource at a time.

```cpp
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> p1 = std::make_unique<int>(42);
    std::cout << *p1 << std::endl;

    // Transfer ownership
    std::unique_ptr<int> p2 = std::move(p1);
    if (!p1) std::cout << "p1 is now empty" << std::endl;
}
```

✅ Automatically deletes the memory when `p2` goes out of scope.
❌ Cannot be copied (only moved).

---

### 2. `std::shared_ptr` – Shared Ownership

Multiple smart pointers can share the same resource.

```cpp
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> p1 = std::make_shared<int>(99);
    std::shared_ptr<int> p2 = p1; // share ownership

    std::cout << "Use count: " << p1.use_count() << std::endl; // 2
}
```

✅ Memory is freed when the **last** `shared_ptr` owning it is destroyed.
⚠️ Slight overhead (keeps a reference count).

---

### 3. `std::weak_ptr` – Non-owning Reference

A weak pointer observes a `shared_ptr` without owning it (prevents circular references).

```cpp
#include <iostream>
#include <memory>

struct Node {
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev; // use weak_ptr to avoid circular reference
};

int main() {
    auto a = std::make_shared<Node>();
    auto b = std::make_shared<Node>();
    a->next = b;
    b->prev = a; // no memory leak!
}
```

---

## 💡 When to Use Which?

| Smart Pointer | Ownership | Copyable | Typical Use                                     |
| ------------- | --------- | -------- | ----------------------------------------------- |
| `unique_ptr`  | Exclusive | ❌ No     | Default choice for ownership                    |
| `shared_ptr`  | Shared    | ✅ Yes    | Shared ownership (e.g., graph nodes, resources) |
| `weak_ptr`    | None      | ✅ Yes    | Break circular dependencies                     |

---

## ⚙️ Summary

* Always prefer `std::make_unique` and `std::make_shared`.
* Avoid `new` and `delete` directly unless absolutely necessary.
* Use `unique_ptr` by default, upgrade to `shared_ptr` only when needed.

---
