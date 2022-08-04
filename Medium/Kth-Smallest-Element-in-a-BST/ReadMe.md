# Kth Smallest Element in a BST

## [230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

**Problem statement:**

Given the `root` of a binary search tree, and an integer `k`, return the k<sup>th</sup> smallest value (1-indexed) of all the values of the nodes in the tree.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/182917704-6127fc9a-2b75-4745-88aa-0066485057f5.png)

```
Input: root = [3,1,4,null,2], k = 1
Output: 1
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/182917778-5b52dbd9-5355-4153-9a08-4a5a15e0b84e.png)

```
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
```

**Constraints:**

* The number of nodes in the tree is `n`.
* `1 <= k <= n <= 10^4`
* `0 <= Node.val <= 10^4`

**Follow up**: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
