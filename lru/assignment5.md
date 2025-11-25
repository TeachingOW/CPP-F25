Here is the **Markdown version with explicit image references included in each step’s text**, while still embedding the images from the `svgs/` directory.

You now have both the *embedded image* and a *verbal reference to the image filename*.

---

# **LRU Cache Replacement — Step-by-Step with Images**

This example illustrates how the **Least Recently Used (LRU)** page-replacement algorithm works using a **cache size of 3**. The cache keeps the **most recently used (MRU)** page on the left and the **least recently used (LRU)** page on the right.

Each step below shows the cache state and refers to the corresponding SVG image located in the `svgs/` directory.

---

## **Step 1 — Insert A**

**Image:** `svgs/lru_frame_1.svg`
![Step 1](svgs/lru_frame_1.svg)

At the beginning, the cache is empty, so page **A** is inserted into the MRU position. Since A is the only page present, it is also the least recently used page (see `svgs/lru_frame_1.svg`).

---

## **Step 2 — Insert B**

**Image:** `svgs/lru_frame_2.svg`
![Step 2](svgs/lru_frame_2.svg)

The next referenced page is **B**, which is not in the cache. Page B is placed into the MRU position, pushing page **A** to the right. After this update, A becomes the least recently used page (as shown in `svgs/lru_frame_2.svg`).

---

## **Step 3 — Insert C**

**Image:** `svgs/lru_frame_3.svg`
![Step 3](svgs/lru_frame_3.svg)

Page **C** is referenced next and is not in the cache. It is inserted at the MRU position, and pages **B** and **A** shift right. Page **A** remains the least recently used page (illustrated in `svgs/lru_frame_3.svg`).

---

## **Step 4 — Access A**

**Image:** `svgs/lru_frame_4.svg`
![Step 4](svgs/lru_frame_4.svg)

The page **A** is referenced again, even though it currently sits in the LRU position. According to the LRU policy, A must be promoted to the MRU position. Pages **C** and **B** shift right, and **B** becomes the least recently used page (see `svgs/lru_frame_4.svg`).

---

## **Step 5 — Insert D**

**Image:** `svgs/lru_frame_5.svg`
![Step 5](svgs/lru_frame_5.svg)

Page **D** is not in the cache and the cache is full. The LRU page, **B**, is evicted. Page D is inserted into the MRU slot, and the remaining pages shift to maintain recency order. Page **C** becomes the new LRU page (shown in `svgs/lru_frame_5.svg`).

---

## **Step 6 — Access B**

**Image:** `svgs/lru_frame_6.svg`
![Step 6](svgs/lru_frame_6.svg)

Page **B** is referenced again, but it was evicted earlier and is not in the cache. This results in a page fault. The current LRU page, **C**, is removed to make space. Page B is inserted into the MRU position, shifting pages **D** and **A** to the right. Page **A** becomes the new LRU (displayed in `svgs/lru_frame_6.svg`).

---

## **Step 7 — Insert E**

**Image:** `svgs/lru_frame_7.svg`
![Step 7](svgs/lru_frame_7.svg)

Finally, page **E** is referenced and is not currently in the cache. The LRU page, **A**, is evicted. Page E is inserted into the MRU position, and pages **B** and **D** shift accordingly. Page **D** becomes the new least recently used page (as shown in `svgs/lru_frame_7.svg`).

