# Search in a Binary Search Tree

## [700. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)

**Problem statement:**
You are given the `root` of a binary search tree (BST) and an integer `val`.

Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `nullptr`.
 
**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/176335746-ec0c0141-32b6-41a3-b0f1-f607bacbbb76.png)

```
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/176335773-d6d94945-f0e8-402d-886c-884ea7c41604.png)

```
Input: root = [4,2,7,1,3], val = 5
Output: []
```

**Constraints:**

* `The number of nodes in the tree is in the range [1, 5000].`
* `1 <= Node.val <= 10^7`
* `root` is a binary search tree.
* `1 <= val <= 10^7`
