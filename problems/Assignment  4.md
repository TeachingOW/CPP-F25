# **📌 LRU (Least Recently Used) Cache Algorithm **

**LRU (Least Recently Used)** is a cache eviction policy that removes the **item that has not been used for the longest time**.

### **Key Ideas**

* The cache holds a fixed number of items (capacity).
* Each time an item is accessed:

  * If it is already in the cache → **move it to the most recently used (MRU) position**.
  * If it is not in the cache:

    * If the cache is not full → insert it.
    * If the cache is full → **evict the least recently used (LRU) item**, then insert.
* We maintain an ordering from **MRU → LRU**.

### **Common Implementation**

* **Doubly-linked list** to maintain usage order.
* **Hash map** to check membership in O(1).

---

# **📌 Example: LRU Cache (capacity = 3)**

We will simulate the cache with the following **reference string**:

```
Access sequence: A, B, C, A, D, B, E
```

We represent the cache as:

```
[MRU -----> LRU]
```

Empty cache initially.

---

# **Step-by-Step Walkthrough 

---

### 1- Access A**

Cache is empty → insert A.

```
Cache: [A]
MRU = A
LRU = A
```

---

### 2-Access B

Cache has space → insert B.

```
[ B | A ]
  ↑   ↑
 MRU LRU
```

(B is now most recently used.)

---

## **3️⃣ Access C**

Cache has space → insert C.

```
[ C | B | A ]
  ↑       ↑
 MRU      LRU
```

---

## **4️⃣ Access A**

A is already in cache → move A to MRU.

Before:

```
[ C | B | A ]
```

After accessing A:

```
[ A | C | B ]
  ↑       ↑
 MRU      LRU
```

---

## **5️⃣ Access D**

Cache is full → evict LRU (B).

Before:

```
[ A | C | B ]   LRU = B
```

Evict B → insert D at MRU:

After:

```
[ D | A | C ]
  ↑       ↑
 MRU      LRU
```

---

## **6️⃣ Access B**

B is NOT in cache → must evict LRU (C).

Before:

```
[ D | A | C ]   LRU = C
```

Evict C → insert B:

After:

```
[ B | D | A ]
  ↑       ↑
 MRU      LRU
```

---

## **7️⃣ Access E**

E is NOT in cache → evict LRU (A).

Before:

```
[ B | D | A ]   LRU = A
```

Evict A → insert E:

After:

```
[ E | B | D ]
  ↑       ↑
 MRU      LRU
```

---

# **📌 Final Cache State**

After processing all requests:

```
[ E | B | D ]
 MRU      LRU
```

---

# **Summary Table**

| Access | Cache Contents (MRU → LRU) | Hit/Miss | Eviction |
| ------ | -------------------------- | -------- | -------- |
| A      | A                          | Miss     | —        |
| B      | B A                        | Miss     | —        |
| C      | C B A                      | Miss     | —        |
| A      | A C B                      | Hit      | —        |
| D      | D A C                      | Miss     | C        |
| B      | B D A                      | Miss     | A        |
| E      | E B D                      | Miss     | D        |

---

If you want, I can also produce:
✅ A color ASCII diagram
✅ A graphical image diagram (just ask)
✅ C++/Python implementation of LRU
✅ Animation-style step-by-step visuals
