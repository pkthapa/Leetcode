# Convert Sorted Array to Binary Search Tree

## [108. Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

**Problem statement:**
Given an integer array `nums` where the elements are sorted in ascending order, convert it to a _**height-balanced** binary search tree_.

A **height-balanced** binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
 
**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/176491895-c6f7d735-ed31-456d-9f0b-7d9ab11d3a41.png)

```
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:
```

![image](https://user-images.githubusercontent.com/20440403/176491957-889de90b-d970-45dd-b674-49316dbe9b47.png)

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/176492089-94b9a59d-331f-4562-bc54-a39a9a58f117.png)

```
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
```

**Constraints:**

* `1 <= nums.length <= 10^4`
* `-10^4 <= nums[i] <= 10^4`
* `nums` is sorted in a **strictly increasing** order.
