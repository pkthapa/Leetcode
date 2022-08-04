# Second Minimum Node In a Binary Tree

## [671. Second Minimum Node In a Binary Tree](https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/)

**Problem statement:**

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly `two` or `zero` sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property `root.val = min(root.left.val, root.right.val)` always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output `-1` instead.
 
**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/182931558-9c852787-b553-448d-a614-c93dc05a853e.png)

```
Input: root = [2,2,5,null,null,5,7]
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/182931631-26f936ed-3ab4-4e1a-8b02-35624622171d.png)

```
Input: root = [2,2,2]
Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 25]`.
* `1 <= Node.val <= 2^31 - 1`
* `root.val == min(root.left.val, root.right.val)` for each internal node of the tree.
