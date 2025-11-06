# ** Line Drawing and Gradient Coloring**

---

## **Part A — Drawing a Line Using Integer Arithmetic**

### **1. Concept**

A straight line between two points
[
(x_1, y_1) \text{ and } (x_2, y_2)
]
can be described mathematically by the equation
[
y = m x + b
]
where ( m = \frac{y_2 - y_1}{x_2 - x_1} ).

A naïve algorithm computes `y` for each step in `x` using floating-point arithmetic.
Although simple, this approach suffers from rounding errors, uneven pixel placement, and high computational cost due to multiplication and division operations.

---

### **2. Floating-Point Method (Conceptual Description)**

1. Compute the slope ( m ) and intercept ( b ).
2. Step through all integer values of `x` between `x1` and `x2`.
3. For each step:

   * Compute ( y = m x + b ).
   * Round ( y ) to the nearest integer pixel.
   * Draw a pixel at `(x, round(y))`.

**Limitations:**

* Requires floating-point division and multiplication.
* Cumulative rounding errors can skip or duplicate pixels.
* Works well only when the slope magnitude is less than 1 unless extra handling is added.

---

### **3. Integer Optimization (Bresenham’s Approach) (Bonus) **

Bresenham’s algorithm replaces all floating-point operations with **integer addition and subtraction** by introducing an **error accumulator**.

#### **Key Idea**

* Maintain an integer variable that measures how far the plotted point is from the true line.
* Increment the error each time a step is made along the major axis.
* When the error exceeds a threshold, step once along the minor axis and correct the error.

#### **Algorithmic Logic**

1. Compute the absolute horizontal and vertical distances (`dx`, `dy`).
2. Determine the step directions in `x` and `y`.
3. Initialize the error term as `err = dx - dy`.
4. Plot the starting pixel `(x1, y1)`.
5. Repeat:

   * Update the error term based on twice its current value.
   * If the doubled error exceeds `-dy`, move one step in `x` and adjust the error.
   * If the doubled error is less than `dx`, move one step in `y` and adjust the error.
   * Continue until the endpoint `(x2, y2)` is reached.

#### **Why It’s an Optimization**

* Avoids all floating-point arithmetic.
* Uses only integer additions, subtractions, and comparisons.
* Produces perfectly connected lines for all slope directions.
* Operates in linear time proportional to the number of pixels in the line.

#### **Applications**

* Low-level graphics (framebuffers, rasterizers)
* Embedded or microcontroller displays
* Efficient drawing routines for games or simulations

---

## **Part B — Gradient Coloring of a Rectangle**

### **1. Concept**

A gradient fill gradually changes color across a surface.
For a rectangular region, the color at each pixel is **interpolated** between two or more reference colors.

Typical example:

* Left edge color → `(r1, g1, b1)`
* Right edge color → `(r2, g2, b2)`

The fill color of each pixel is a weighted blend based on its position.

---

### **2. Gradient Computation Principle**


> **Note:** You are free to use other the gradient effect.  
> For example, you might experiment with different interpolation formulas


For a horizontal gradient:
[
R = r_1 + (r_2 - r_1) \cdot \frac{x - x_1}{x_2 - x_1}
]
[
G = g_1 + (g_2 - g_1) \cdot \frac{x - x_1}{x_2 - x_1}
]
[
B = b_1 + (b_2 - b_1) \cdot \frac{x - x_1}{x_2 - x_1}
]

Each pixel’s color depends on how far it lies between the two edges.

---

### **3. Integer Interpolation Optimization**

To avoid floating-point operations, replace the fractional ratio
[
\frac{x - x_1}{x_2 - x_1}
]
with an **integer-scaled fraction**, such as:
[
t = \frac{(x - x_1) \times 255}{x_2 - x_1}
]
and use integer arithmetic to interpolate each color channel.

This allows smooth gradients computed entirely with integer math, using addition and multiplication only.

---

### **4. Algorithmic Description**

1. Determine the rectangular region boundaries: `(x1, y1)` to `(x2, y2)`.
2. For each pixel position `(x, y)` inside the rectangle:

   * Compute the interpolation factor `t` based on horizontal position.
   * Calculate the red, green, and blue components using integer interpolation.
   * Set the pixel color using `set_pixel(x, y, R, G, B)`.
3. Repeat for every scanline until the rectangle is filled.

---

### **5. Properties and Advantages**

| Property                 | Description                                                                                  |
| ------------------------ | -------------------------------------------------------------------------------------------- |
| **Integer-based**        | Avoids costly floating arithmetic                                                            |
| **Linear interpolation** | Produces visually smooth gradients                                                           |
| **Scalable**             | Works for large or small rectangles                                                          |
| **Efficient**            | Constant-time per pixel operation                                                            |
| **Versatile**            | Easily extended to vertical or diagonal gradients by blending in both `x` and `y` directions |

---

### **6. Extensions**

* **Vertical gradients:** Interpolate colors along the `y` axis instead of `x`.
* **Two-dimensional gradients:** Blend both horizontally and vertically using bilinear interpolation.
* **Dynamic shading:** Use position-dependent color functions to simulate lighting or depth.

---

## **Summary**

| Feature         | Floating Line        | Integer Line            | Gradient Fill                 |
| --------------- | -------------------- | ----------------------- | ----------------------------- |
| **Core idea**   | Compute y from slope | Use error accumulation  | Interpolate color by position |
| **Arithmetic**  | Floating point       | Integer                 | Integer                       |
| **Precision**   | Approximate          | Exact pixel mapping     | Smooth color variation        |
| **Performance** | Slow                 | Fast                    | Fast                          |
| **Use case**    | Conceptual drawing   | Real-time rasterization | Shading and coloring          |

---

**In essence:**

* **Part A** demonstrates how replacing floating-point arithmetic with integer accumulation (Bresenham) drastically improves performance for line drawing.
* **Part B** applies the same principle of **integer-based interpolation** to compute smooth color gradients efficiently for pixel-based rectangle fills.
