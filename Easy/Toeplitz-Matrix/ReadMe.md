# Toeplitz Matrix

## [766. Toeplitz Matrix](https://leetcode.com/problems/toeplitz-matrix/)

**Problem statement:**

Given an `m x n` matrix, return `true` if the matrix is Toeplitz. Otherwise, return `false`.

A matrix is **Toeplitz** if every diagonal from top-left to bottom-right has the same elements.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/198911397-4610c0b8-551a-4150-a110-3ab156d70044.png)

```
Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/198911428-4922d3f3-263c-4d08-ada0-3a253882afc2.png)

```
Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.
```

**Constraints:**

* *m == matrix.length*
* *n == matrix[i].length*
* *1 <= m, n <= 20*
* *0 <= matrix[i][j] <= 99*

**Follow up**:

* What if the `matrix` is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
* What if the `matrix` is so large that you can only load up a partial row into the memory at once?
