# Word Search

## [79. Word Search](https://leetcode.com/problems/word-search/)

**Problem statement:**

Given an `m x n` grid of characters `board` and a string `word`, return `true` if `word` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/185158742-27bf598b-a0a4-4faa-b5bf-b2746097bbeb.png)

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/185158842-365e763a-ba8c-49cb-84e4-bc4d77e263d6.png)

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```

**Example 3:**

![image](https://user-images.githubusercontent.com/20440403/185158942-1397ed20-b1f0-4708-be4e-7aed69feb0c6.png)

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```

**Constraints:**

* `m == board.length`
* `n = board[i].length`
* `1 <= m, n <= 6`
* `1 <= word.length <= 15`
* `board` and `word` consists of only lowercase and uppercase English letters.

**Follow up**: Could you use search pruning to make your solution faster with a larger `board`?
