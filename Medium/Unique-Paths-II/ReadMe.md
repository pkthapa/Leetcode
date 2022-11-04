# Unique Paths II

## [63. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)

**Problem statement:**

You are given an `m x n` integer array `grid`. There is a robot initially located at the top-left corner (i.e., `grid[0][0]`). The robot tries to move to the bottom-right corner (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or right at any point in time.

An obstacle and space are marked as `1` or `0` respectively in `grid`. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to *2 * 10<sup>9</sup>*.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/200059768-931b1592-5c4f-491a-84bb-fe249134a136.png)

```
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/200059829-5e93ea64-b1e7-4c91-bf2c-1c957ef09319.png)

```
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
```

**Constraints:**

* `m == obstacleGrid.length`
* `n == obstacleGrid[i].length`
* `1 <= m, n <= 100`
* `obstacleGrid[i][j]` is `0` or `1.`
