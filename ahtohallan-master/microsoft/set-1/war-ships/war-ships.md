
[Editorial Page](../microsoft-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
Looks like I under-estimated the difficulty of this problem.

You just need to run a **BFS** from the source and terminate when you've reached the desired number of levels.

Just make sure to take modulo at each step (as there is an exponential(?) rise in the number of elements in each level). There is a maximum of 10 levels in the test-cases.

----

# Code
* [My Solution](solution.cpp)

----
