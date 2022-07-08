# Leetcode Solution

## [1791. Find Center of Star Graph](https://leetcode.com/problems/find-center-of-star-graph/)

**Problem statement:**

There is an undirected star graph consisting of `n` nodes labeled from `1` to `n`. A star graph is a graph where there is one center node and exactly `n - 1` edges that connect the center node with every other node.

You are given a 2D integer array `edges` where each `edges[i] = [ui, vi]` indicates that there is an edge between the nodes `ui` and `vi`. Return the center of the given star graph.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/172464827-650d5ebe-f0c8-4c94-8e1d-d786972a808c.png)

```
Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/172516238-63d995ab-76d1-4ddf-acbe-6cb4b7823c86.png)

```
Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1
``` 

**Constraints:**

* ```3 <= n <= 105```
* ```edges.length == n - 1```
* ```edges[i].length == 2```
* ```1 <= ui, vi <= n```
* ```ui != vi```
* ```The given edges represent a valid star graph.```
