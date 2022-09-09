# The Number of Weak Characters in the Game

## [1996. The Number of Weak Characters in the Game](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/)

**Problem statement:**

You are playing a game that contains multiple characters, and each of the characters has two main properties: **attack** and **defense**. You are given a 2D integer array `properties` where *properties[i] = [attack<sub>i</sub>, defense<sub>i</sub>]* represents the properties of the *i<sup>th</sup>* character in the game.

A character is said to be **weak** if any other character has both attack and defense levels **strictly greater** than this character's attack and defense levels. More formally, a character `i` is said to be weak if there exists another character `j` where *attack<sub>j</sub> > attack<sub>i</sub>* and *defense<sub>j</sub> > defense<sub>i</sub>*.

Return the number of **weak** characters.

**Example 1:**

```
Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.
```

**Example 2:**

```
Input: properties = [[2,2],[3,3]]
Output: 1
Explanation: The first character is weak because the second character has a strictly greater attack and defense.
```

**Example 3:**

```
Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack and defense.
```

**Constraints:**

* *2 <= properties.length <= 10<sup>5</sup>*
* *properties[i].length == 2*
* *1 <= attack<sub>i</sub>, defense<sub>i</sub> <= 10<sup>5</sup>*
