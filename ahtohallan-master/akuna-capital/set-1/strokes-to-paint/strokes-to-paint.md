
[Editorial Page](../akuna-capital-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
You can either deal with character matrix, or switch to integer based.

Perform a **Flood Fill DFS**, flooding the visited elements with a unique value. The number of DFS inititation is the answer.

In short, we need to find the number of connected components in the implicit graph.

----

# Code
* [My Solution](solution.cpp)

----

