# Path Sum

## [112. Path Sum](https://leetcode.com/problems/path-sum/)

**Problem statement:**

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

A **leaf** is a node with no children.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/199882781-edac02e3-bef2-448b-825c-5e0e9a5fb9e3.png)

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/199882831-977cf792-6392-481a-80fc-8866b19e8f45.png)

```
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
```

**Example 3:**

```
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
```

**Constraints:**

* *The number of nodes in the tree is in the range [0, 5000].*
* *-1000 <= Node.val <= 1000*
* *-1000 <= targetSum <= 1000*
