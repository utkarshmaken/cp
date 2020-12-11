[Editorial Page](../dream11-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
First, you need to solved [Edit Distance](https://leetcode.com/problems/edit-distance/), which is **LC-Hard**. After you've solved it, this question would becomes **LC-Easy** if you are allowed to use **Edit-Distance** as a black box.

Notice that there can only be 26 different shifts of the source string (as the characters wrap around). So, for each of the 26 shifts, create the new source, calculate the edit distance and keep a global min.

Note that unlike **LeetCode**, `replace` would cost you 2 units (first delete and then insert).

Finally, take care to implement wrapping properly (which is an ESC101 Lab question. You need to use modulo 26).

----

# Code
* [My Solution](solution.cpp)

----

