# Word Search II

## [212. Word Search II](https://leetcode.com/problems/word-search-ii/)

**Problem statement:**

Given an `m x n` board of characters and a list of strings `words`, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/198863175-45aa379e-e841-4d3d-b61d-2c875428c0d9.png)

```
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/198863183-9435aad7-f1db-49de-bda6-03636efee379.png)

```
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
```

**Constraints:**

* *m == board.length*
* *n == board[i].length*
* *1 <= m, n <= 12*
* *board[i][j] is a lowercase English letter.*
* *1 <= words.length <= 3 * 10<sup>4</sup>*
* *1 <= words[i].length <= 10*
* *words[i] consists of lowercase English letters.*
* *All the strings of words are unique.*
