# Construct String from Binary Tree

## [606. Construct String from Binary Tree](https://leetcode.com/problems/construct-string-from-binary-tree/)

**Problem statement:**

Given the `root` of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.
 
**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/188781046-6c5ac676-a5f2-49ee-89ed-0487057567da.png)

```
Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/188781075-fddb69d2-cf77-4133-bc04-791b08b2633b.png)

```
Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
```

**Constraints:**

* *The number of nodes in the tree is in the range [1, 10<sup>4</sup>]*.
* *-1000 <= Node.val <= 1000*
