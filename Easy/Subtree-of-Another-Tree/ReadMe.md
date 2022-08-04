# Subtree of Another Tree

## [572. Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)

**Problem statement:**

Given the roots of two binary trees `root` and `subRoot`, return `true` if there is a subtree of `root` with the same structure and node values of `subRoot` and `false` otherwise.

A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.
 
**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/182763859-6e290088-98a9-4c81-ad45-888e9095c451.png)

```
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/182763906-c31eecdf-8990-4b7d-9011-77a1cb440cdf.png)

```
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
```

**Constraints:**

* The number of nodes in the `root` tree is in the range `[1, 2000]`.
* The number of nodes in the `subRoot` tree is in the range `[1, 1000]`.
* `-10^4 <= root.val <= 10^4`
* `-10^4 <= subRoot.val <= 10^4`
