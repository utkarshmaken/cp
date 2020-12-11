

[Editorial Page](../book-my-show-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Editorial (by ...)](#editorial-by-)
* [Code](#code)

<!-- vim-markdown-toc -->

Initially, I had misinterpreted the question as **Finding the minimum vertex cover of a tree** (which is an interesting question and you should try it on [SPOJ](https://www.spoj.com/problems/PT07X/)). As we were testing the round today, I realized my mistake. I tried to come up with another solution, but couldn't. Luckily, ... saved the day!


**Note** : If you've come up with a solution, but can't figure out why it isn't correct, it's a good time to [stress-test](../../../documentation/stress-testing.md) your solution for smaller test-cases.

----

# Editorial (by ...)
First, note that there is an optimal solution which doesn't place a hospital on a leaf. Because you can always cover more nodes if you place the leaf above it and it'll still cover the leaf and it's parent.

Now, for the dfs, just keep 3 states (covered, not covered, hospital). All the leaf nodes are given a not covered state. Now in the dfs, if any node has a not covered child, the node must have a hospital, otherwise, if the node has any child which is a hospital, it will be covered. Otherwise, it is not covered.

You can show this is optimal. Look at the first place a discrepancy occurs in the dfs from the optimal solution. It can't occur at a leaf because we've shown there has to be an optimal solution without the leaves covered by hospitals.

So either we're placing a hospital when the optimal solution didn't need it, or we're not placing a hospital when the optimal solution has one. In both cases, note that we can assume the nodes visited so far are correct because this is the first discrepancy.

For the first case, we note that since there is a "not covered" child, we have to place a hospital. For the second case, we see that we can cover more nodes if we place a hospital on the parent of the current node, since the current node is covered.

----

# Code
* [Implementation of the above idea](solution.cpp)
* [Vertex Cover (SPOJ)](solution-vertex-cover.cpp)

----
