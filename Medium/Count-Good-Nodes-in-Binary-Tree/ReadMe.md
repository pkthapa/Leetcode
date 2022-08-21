# Count Good Nodes in Binary Tree

## [1448. Count Good Nodes in Binary Tree](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)

**Problem statement:**

Given a binary tree `root`, a node `X` in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/185797712-a4a48ec9-df31-4777-aceb-f328ee58aca8.png)

```
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/185797719-f6402d45-b0d4-4172-addd-f1ce672d2106.png)

```
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
```

**Example 3:**

```
Input: root = [1]
Output: 1
Explanation: Root is considered as good.
```

**Constraints:**

* *The number of nodes in the binary tree is in the range [1, 10<sup>5</sup>]*.
* *Each node's value is between [-10<sup>4</sup>, 10<sup>4</sup>]*.
