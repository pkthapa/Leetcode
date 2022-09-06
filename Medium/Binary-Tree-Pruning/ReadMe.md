# Binary Tree Pruning

## [814. Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/)

**Problem statement:**

Given the `root` of a binary tree, return the same tree where every subtree (of the given tree) not containing a `1` has been removed.

A subtree of a node `node` is node plus every node that is a descendant of `node`.
 
**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/188544950-7c53bf6a-41ef-4510-9160-a5b8fa0d7b50.png)

```
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/188544987-4865b8c3-ded8-4de3-ac75-40781fbed87f.png)

```
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
```

**Example 3:**

![image](https://user-images.githubusercontent.com/20440403/188545015-7022c073-2112-40e8-af1a-4615f6ac1a46.png)

```
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
```

**Constraints:**

* *The number of nodes in the tree is in the range `[1, 200]`.*
* *`Node.val` is either `0` or `1`.*
