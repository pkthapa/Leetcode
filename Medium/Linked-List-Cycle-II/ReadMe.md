# Linked List Cycle II

## [142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

**Problem statement:**
Given the `head` of a linked list, return the node where the cycle begins. If there is no cycle, return `null`.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer.

**Do not modify** the linked list.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/177191990-f244d5b0-c1da-41fc-b7b5-dc077c86bf70.png)

```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/177192028-dc8a9174-221f-414b-8968-5e1118300e0f.png)

```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

**Example 3:**

![image](https://user-images.githubusercontent.com/20440403/177192058-cd8cc1dc-f9b9-4363-acc9-da9a898bad75.png)

```
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```

**Constraints:**

* The number of the nodes in the list is in the range [0, 10^4].
* `-10^5 <= Node.val <= 10^5`
