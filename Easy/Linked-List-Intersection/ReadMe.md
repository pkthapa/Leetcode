# Intersection of Two Linked Lists

## [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)

**Problem statement:**
Given the heads of two singly linked-lists `headA` and `headB`, return _the node at which the two lists intersect_. If the two linked lists have no intersection at all, return `null`.

For example, the following two linked lists begin to intersect at node `c1`:

![image](https://user-images.githubusercontent.com/20440403/175801518-f5f24a8d-1f28-4dfd-8251-88837d1e8d7b.png)

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/175801541-18d103ce-966e-476f-be2d-fff7e583c0ef.png)

```
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/175774314-14f6aed8-8a08-4237-9f20-a1ed88d88fd8.png)

```
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
```

**Example 3:**

![image](https://user-images.githubusercontent.com/20440403/175801558-f13de808-30b3-499c-99ae-49c5481af372.png)

```
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
```

**Constraints:**

* The number of nodes of `listA` is in the `m`.
* The number of nodes of `listB` is in the `n`.
* `1 <= m, n <= 3 * 10^4`
* `1 <= Node.val <= 10^5`
