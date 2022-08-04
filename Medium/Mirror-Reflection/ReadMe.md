# Mirror Reflection

## [858. Mirror Reflection](https://leetcode.com/problems/mirror-reflection/)

**Problem statement:**

There is a special square room with mirrors on each of the four walls. Except for the southwest corner, there are receptors on each of the remaining corners, numbered `0`, `1`, and `2`.

The square room has walls of length `p` and a laser ray from the southwest corner first meets the east wall at a distance `q` from the `0th` receptor.

Given the two integers `p` and `q`, return the number of the receptor that the ray meets first.

The test cases are guaranteed so that the ray will meet a receptor eventually.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/182752907-181f5f24-1dcb-4c5c-b6fb-aafe52b95fda.png)

```
Input: p = 2, q = 1
Output: 2
Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.
```

**Example 2:**

```
Input: p = 3, q = 1
Output: 1
```

**Constraints:**

* `1 <= q <= p <= 1000`
