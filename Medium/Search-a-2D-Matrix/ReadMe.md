# Search a 2D Matrix

## [74. Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix/)

**Problem statement:**

Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`. This matrix has the following properties:

* Integers in each row are sorted in ascending from left to right.
* The first integer of each row is greater than the last integer of the previous row.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/180630369-b5e47d10-df12-49f7-8260-31a2b3a09a3b.png)

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/180630377-65a662b1-8e7b-431e-bb7a-36b07a0907ae.png)

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

**Constraints:**

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 100`
* `-10^4 <= matrix[i][j], target <= 10^4`
