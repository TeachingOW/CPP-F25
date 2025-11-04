
# 🧩 Merge Sort Implementation in C++

This program implements the **Merge Sort** algorithm using C++ and the Standard Template Library (**STL**).  
It recursively divides the array into subarrays, sorts them, and then merges them efficiently using an auxiliary array.

---

## 📘 Description

The algorithm follows the **divide and conquer** approach:

1. **Divide** — Split the array into two halves.
2. **Conquer** — Recursively sort both halves.
3. **Combine** — Merge the two sorted halves into a single sorted array.

This version uses an **auxiliary array** `B` for merging, avoiding repeated memory allocation by defining it once in the recursive process.

---

## ⚙️ Key Functions

### `merge(vector<int>& A, vector<int>& B, int start, int middle, int end)`
Merges two sorted subarrays from `A`:
- Left subarray: `A[start...middle]`
- Right subarray: `A[middle+1...end]`  
The merged result is placed into `B[start...end]`.

### `mergesort(vector<int>& A, int start, int end)`
Recursively sorts the subarray `A[start...end]`.

### `mergesort(vector<int>& A)`
Convenience wrapper that sorts the entire vector `A`.

---

## 🧠 Example Execution

Input:
```cpp
vector<int> A{ 2, 1, 3, 4, 0, 1, 10, 20 };
mergesort(A);
````

Output:

```
0 1 1 2 3 4 10 20
```

---

## 💻 Full Source Code

<div align="right">
  <button onclick="navigator.clipboard.writeText(document.getElementById('code').innerText)" style="padding:6px 12px;border:none;border-radius:6px;background:#007acc;color:white;cursor:pointer;">📋 Copy</button>
</div>

```cpp
#include <vector>
#include <iostream>
using namespace std;

// merge subarray A [start, middle] and A [middle+1, end] into B [start, end]
void merge(vector<int> &A, vector<int> &B, int start, int middle, int end) {
    int i1 = start;
    int i2 = middle + 1;
    int e1 = middle;
    int e2 = end;
    int b = start;

    for (;;) {
        if (A[i1] < A[i2]) {
            B[b] = A[i1];
            i1++;
        } else {
            B[b] = A[i2];
            i2++;
        }
        b++;
        if (i1 > e1) break;
        if (i2 > e2) break;
    }
    while (i1 <= e1) B[b++] = A[i1++];
    while (i2 <= e2) B[b++] = A[i2++];
}

void mergesort(vector<int>& A, int start, int end) {
    if (start >= end) return;
    int middle = (start + end) / 2;
    mergesort(A, start, middle);
    mergesort(A, middle + 1, end);
    vector<int> B(A.size(), 0);
    merge(A, B, start, middle, end);
    for (int i = start; i <= end; i++) A[i] = B[i];
}

void mergesort(vector<int>& A) {
    mergesort(A, 0, A.size() - 1);
}

int main() {
    vector<int> A{ 2, 1, 3, 4, 0, 1, 10, 20 };
    mergesort(A);
    for (auto x : A) cout << x << " ";
}
```


# 🚀 Optimized Merge Sort 

The previous version of **Merge Sort** recreated an auxiliary array `B` inside every recursive call, and copied sorted results back to the original array `A`.  
This introduced **extra memory movement** and **allocation overhead**.

This improved version **avoids redundant copying** by alternating between two arrays — `A` and `B` — during recursive calls.  
At each merge step, data flows from one array to the other, eliminating the need to repeatedly move sorted data back.

---

## 🧠 How It Works

- Two arrays are used:  
  - `A` — the **source** array (input).  
  - `B` — the **destination** array (temporary storage).  

- On each recursive step, the roles of `A` and `B` are **swapped**.  
  This way, we merge from `A` into `B`, then sort from `B` into `A`, and so on.


---

## 🧩 Example Execution

Input:
```cpp
vector<int> A{ 2, 1, 3, 4, 0, 1, 10, 20 };
mergesort(A);
````

Output:

```
0
1
1
2
3
4
10
20
```

---

## 💻 Full Source Code

<div align="right">
  <button onclick="navigator.clipboard.writeText(document.getElementById('code2').innerText)" style="padding:6px 12px;border:none;border-radius:6px;background:#007acc;color:white;cursor:pointer;">📋 Copy</button>
</div>

```cpp
#include <vector>
#include <iostream>
using namespace std;

// merge subarray A [start, middle] and A [middle+1, end] into B [start, end]
void merge(vector<int> &A, vector<int> &B, int start, int middle, int end) {
    int i1 = start;
    int i2 = middle + 1;
    int e1 = middle;
    int e2 = end;
    int b = start;

    for (;;) {
        if (A[i1] < A[i2]) {
            B[b++] = A[i1++];
        } else {
            B[b++] = A[i2++];
        }
        if (i1 > e1) break;
        if (i2 > e2) break;
    }
    while (i1 <= e1) B[b++] = A[i1++];
    while (i2 <= e2) B[b++] = A[i2++];
}

// optimized merge sort: alternate between A and B to avoid unnecessary copying
void mergesort(vector<int>& A, vector<int>& B, int start, int end) {
    if (start >= end) return;
    int middle = (start + end) / 2;

    // swap A and B roles between recursive calls
    mergesort(B, A, start, middle);
    mergesort(B, A, middle + 1, end);

    // merge from A into B
    merge(A, B, start, middle, end);
}

void mergesort(vector<int>& A) {
    vector<int> B = A; // allocate once
    mergesort(B, A, 0, A.size() - 1);
}

int main() {
    vector<int> A{ 2, 1, 3, 4, 0, 1, 10, 20 };
    mergesort(A);
    for (auto x : A) cout << x << "\n";
}
```

