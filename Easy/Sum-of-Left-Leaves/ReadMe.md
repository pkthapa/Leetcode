# Sum of Left Leaves

## [404. Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/)

**Problem statement:**
Given the `root` of a binary tree, return _the sum of all left leaves_.

A **leaf** is a node with no children. A left leaf is a leaf that is the left child of another node.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/176985039-6802de18-8033-461c-ba69-fe871c412530.png)

```
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
```

**Example 2:**

```
Input: root = [1]
Output: 0
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 1000]`.
* `-1000 <= Node.val <= 1000`
