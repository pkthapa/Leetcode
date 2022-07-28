# N-Queens

## [51. N-Queens](https://leetcode.com/problems/n-queens/)

**Problem statement:**

The **n-queens** puzzle is the problem of placing n queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where '`Q`' and '`.`' both indicate a queen and an empty space, respectively.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/181417310-46eac711-b6c6-4153-a778-574d3a1bc7dc.png)

```
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
```

**Example 2:**

```
Input: n = 1
Output: [["Q"]]
```

**Constraints:**

* `1 <= n <= 9`
