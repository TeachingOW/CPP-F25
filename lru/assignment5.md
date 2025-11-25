# LRU  

An LRU Cache is a data structure that stores a limited number of items and automatically evicts the least recently used item when it reaches its capacity. It is designed to provide fast access and efficient eviction based on usage patterns.

The key idea behind LRU is simple,  If an item has not been used for the longest time, it is the best candidate to remove when space is needed.

LRU caches are widely used in:

- Operating systems (e.g., paging systems)
- Web browsers (storing recently visited pages)
- Databases (buffer pools)
- High-performance applications that require fast lookups

## Detailed Example

Assume a cache of size 3, assume the following access pattern: A, B, C, A, D, B, E. 


### Accessing  A 

![Step 1](svgs/lru_frame_1.svg)

At the beginning, the cache is empty, so page **A** is inserted into the MRU position. Since A is the only page present, it is also the least recently used page.

---

### Accessing B


![Step 2](svgs/lru_frame_2.svg)

The next referenced page is **B**, which is not in the cache. Page B is placed into the MRU position, pushing page **A** to the right. After this update, A becomes the least recently used page.

---

###  Accessing  C

![Step 3](svgs/lru_frame_3.svg)

Page **C** is referenced next and is not in the cache. It is inserted at the MRU position, and pages **B** and **A** shift right. Page **A** remains the least recently used page.

---

###  Accessing A

![Step 4](svgs/lru_frame_4.svg)

The page **A** is referenced again, even though it currently sits in the LRU position. According to the LRU policy, A must be promoted to the MRU position. Pages **C** and **B** shift right, and **B** becomes the least recently used page.

---

### Acessing  D

![Step 5](svgs/lru_frame_5.svg)

Page **D** is not in the cache and the cache is full. The LRU page, **B**, is evicted. Page D is inserted into the MRU slot, and the remaining pages shift to maintain recency order. Page **C** becomes the new LRU page.

---

### Accessing B

![Step 6](svgs/lru_frame_6.svg)

Page **B** is referenced again, but it was evicted earlier and is not in the cache. This results in a page fault. The current LRU page, **C**, is removed to make space. Page B is inserted into the MRU position, shifting pages **D** and **A** to the right. Page **A** becomes the new LRU. 

---

###  Acessing E

![Step 7](svgs/lru_frame_7.svg)

Finally, page **E** is referenced and is not currently in the cache. The LRU page, **A**, is evicted. Page E is inserted into the MRU position, and pages **B** and **D** shift accordingly. Page **D** becomes the new least recently used page.

