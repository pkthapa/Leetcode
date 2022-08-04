# Same Tree

## [100. Same Tree](https://leetcode.com/problems/same-tree/)

**Problem statement:**

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 
**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/182757367-5b654ae7-0c82-4f25-a9da-501c6022aa4f.png)

```
Input: p = [1,2,3], q = [1,2,3]
Output: true
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/182757395-ecfb1a97-d838-4b80-ac2c-d0701d44b86f.png)

```
Input: p = [1,2], q = [1,null,2]
Output: false
```

**Example 3:**

![image](https://user-images.githubusercontent.com/20440403/182757436-62ad16b8-cdae-4b81-8c2e-56efc99a4873.png)

```
Input: p = [1,2,1], q = [1,1,2]
Output: false
```

**Constraints:**

* The number of nodes in both trees is in the range `[0, 100]`.
* `-10^4 <= Node.val <= 10^4`
