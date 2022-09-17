# Maximum Depth of N-ary Tree

## [559. Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)

**Problem statement:**

Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

*Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples)*.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/190867391-dbbdddd8-837a-4c62-96d1-3723cf556293.png)

```
Input: root = [1,null,3,2,4,null,5,6]
Output: 3
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/190867403-11fa25db-66b5-45a2-921a-743525523af6.png)

```
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5
```

**Constraints:**

* *The total number of nodes is in the range [0, 10<sup>4</sup>]*.
* *The depth of the n-ary tree is less than or equal to 1000.*
