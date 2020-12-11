[Editorial Page](../fractal-set-2.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Reduction](#reduction)
* [You don't need the Reduction](#you-dont-need-the-reduction)
* [Practice Problems](#practice-problems)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
I'm not gonna explain **Dijkstra's Algorithm** (which has been already been done multiple times on the internet). You can refer to **Codeforces Blogs, CP-Algorithms, Youtube** and other resources that you find interesting. But I want to say 2 things : 
1. Don't just copy random/cool templates without understanding it. Each one has their own complications which might not be obvious to everyone. For example, handling duplicates in `min_heap` implementation, avoiding deletion of non-existent element in `set` implementation and so on. So, whatever you do, make sure that you understand each and every line in depth.
2. If you get the time, do read the correspoding chapter from **CLRS**. All other resources teach you the **How**, but this one teaches you the **why**. 

----

# Reduction
To apply standard Dijkstra's algorithm, you need to 

1. Remove **Slef-Loops**. It can be done very easily.
2. For every pair of adjacent vertiecs, remove all the edges except one (with the minimal weight). To accomplish this, store every edge-weight in map, where the `key` is the pair that it connects. As soon you see multiple edges, remove the heavier edge.

----

# You don't need the Reduction
I came up with the solution via edge-reduction. However, while going through other people's code during the contest, I realized that you don't need any of these reductions (self loops, and multi-edges). **Dijkstra's Algorithm** is designed to work on these type of graphs too. (As it would always pick the edges with minimal weight in case of multi-edges).

----

# Practice Problems
While we are dealing with weighted graphs, why don't I suggest something related to **APSP**.

[UVa - 10099 - The Tourist Guide](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1040)

----

# Code
* [Standard Dijkstra](solution.cpp)
* [Standard Dijkstra with edge-cleaning](solution-edge-clean.cpp)
