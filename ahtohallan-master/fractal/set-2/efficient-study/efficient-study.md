
[Editorial Page](../fractal-set-2.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
Just double the values in the pages array. Now, it is just a classical **Knapsack Problem**.

Define `dp[n][weight]` as the maximum value that a thief can gain from first `n` objects if he has a knapsack of capacity `weight`.

The transistions are as usual, either take the last element (if possible), or don't take it.

----

# Code
[Knapsack](solution.cpp)

----
