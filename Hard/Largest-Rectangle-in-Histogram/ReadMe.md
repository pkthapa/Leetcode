# Largest Rectangle in Histogram

## [84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)

**Problem statement:**

Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`, return the area of the largest rectangle in the histogram.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/187251715-c54e6ef6-dd80-42de-a239-67f08eaae7da.png)

```
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/187251763-18e1c140-2c77-4819-82e2-e5fd244cd24e.png)

```
Input: heights = [2,4]
Output: 4
```

**Constraints:**

* *1 <= heights.length <= 10<sup>5</sup>*
* *0 <= heights[i] <= 10<sup>4</sup>*
