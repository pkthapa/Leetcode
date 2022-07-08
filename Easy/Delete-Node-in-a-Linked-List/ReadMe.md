# Linked List Cycle

## [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

**Problem statement:**
Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/177378363-f3ada7af-3022-4e4b-864d-4e3c9e0e5fd9.png)

```
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/177378414-18d52966-5b55-4c4e-958b-4cec7fae0688.png)

```
Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
```

**Constraints:**

* The number of the nodes in the given list is in the range `[2, 1000]`.
* `-1000 <= Node.val <= 1000`
* The value of each node in the list is unique.
* The node to be deleted is in the list and is not a tail node.
