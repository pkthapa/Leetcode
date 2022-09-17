# Binary Tree Zigzag Level Order Traversal

## [103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

**Problem statement:**

Given the `root` of a binary tree, return *the zigzag level order traversal of its nodes' values*. (i.e., from left to right, then right to left for the next level and alternate between).

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/190853591-f7ed9dab-14c6-4fae-8185-3a31631538be.png)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
```

**Example 2:**

```
Input: root = [1]
Output: [[1]]
```

**Example 3:**

```
Input: root = []
Output: []
```

**Constraints:**

* *The number of nodes in the tree is in the range [0, 2000]*.
* *-100 <= Node.val <= 100*
