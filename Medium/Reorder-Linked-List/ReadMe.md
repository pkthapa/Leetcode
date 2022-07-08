# Reorder List

## [143. Reorder List](https://leetcode.com/problems/reorder-list/)

**Problem statement:**
You are given the head of a singly linked-list. The list can be represented as:

`L0 → L1 → … → Ln - 1 → Ln`

Reorder the list to be on the following form:

`L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …`

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/177247784-6bd46277-9617-4e8e-b46a-d56db4d77575.png)

```
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/177247816-8019aa19-0f94-468f-ab43-48dd864c57cd.png)

```
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
```

**Constraints:**

* The number of nodes in the list is in the range `[1, 5 * 10^4]`.
* `1 <= Node.val <= 1000`