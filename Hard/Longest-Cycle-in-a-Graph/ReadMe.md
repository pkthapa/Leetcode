# Longest Cycle in a Graph

## [2360. Longest Cycle in a Graph](https://leetcode.com/problems/longest-cycle-in-a-graph/)

**Problem statement:**

You are given a **directed** graph of `n` nodes numbered from `0` to `n - 1`, where each node has at most one outgoing edge.

The graph is represented with a given **0-indexed** array edges of size `n`, indicating that there is a directed edge from node `i` to node `edges[i]`. If there is no outgoing edge from node `i`, then `edges[i] == -1`.

Return *the length of the **longest** cycle in the graph. If no cycle exists, return `-1`*.

A cycle is a path that starts and ends at the same node.

**Example 1:**

![image](https://user-images.githubusercontent.com/20440403/182014122-1c6184ef-3c7e-4f2b-9c68-92fb817a508a.png)

```
Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.
```

**Example 2:**

![image](https://user-images.githubusercontent.com/20440403/182014140-34fc7baf-6620-4dd5-8e26-08ec7b426e89.png)

```
Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.
```

**Constraints:**

* `n == edges.length`
* `2 <= n <= 10^5`
* `-1 <= edges[i] < n`
* `edges[i] != i`
