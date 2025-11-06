---
layout: default
title: MathJax Test
---

# MathJax Rendering Test

This page demonstrates that MathJax works on GitHub Pages.

## Inline Math
The equation for the slope between two points is \( m = \frac{y_2 - y_1}{x_2 - x_1} \).

The line equation is \( y = m x + b \).

## Display Math
$$
m = \frac{y_2 - y_1}{x_2 - x_1}
$$

$$
y = m x + b
$$

## Example (Integer Line Drawing)
Given endpoints \( (x_1, y_1) \) and \( (x_2, y_2) \):

1. Compute \( dx = x_2 - x_1 \), \( dy = y_2 - y_1 \)
2. Initialize the error term \( err = dx - dy \)
3. Update the pixel position while \( (x, y) \) has not reached the end

$$
\begin{align}
2 \times err &\leftarrow 2 \times err \\
\text{if } (2 \times err) > -dy &: err \mathrel{-}= dy;\; x \mathrel{+}= 1 \\
\text{if } (2 \times err) <  dx &: err \mathrel{+}= dx;\; y \mathrel{+}= 1
\end{align}
$$

## Gradient Fill Formula
For a rectangle from top color \( C_t = (r_t, g_t, b_t) \)  
to bottom color \( C_b = (r_b, g_b, b_b) \), each scan line \( y \) has:

$$
C(y) = C_t + \frac{y - y_1}{y_2 - y_1} (C_b - C_t)
$$

Then use your `set_pixel(x, y, r, g, b)` function to draw each pixel.
