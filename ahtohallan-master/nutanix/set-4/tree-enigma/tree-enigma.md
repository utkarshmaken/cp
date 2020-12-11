[Editorial Page](../nutanix-set-4.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This a typical **DP on Trees** question. You can go through this [Codeforces Blog](https://codeforces.com/blog/entry/20935) to learn this technique. Here's a [nice practice problem](https://www.e-olymp.com/en/problems/973) to get you started on this topic.

----

It's clear that when you apply an operation of the second kind, this effect propagates through every node in the subtree. Moreover, 2 propagations cancel each other. Hence, we also need to keep track of whether the propagation has been cancelled or not. Basically, a boolean value, where `0` indicates that the starting color has not been messed with, and `1` indicates that we need to invert the starting color. 

Define `dp[root][inv]` to be the minimum cost to correct the subtree rooted at `root` (including itself), when the propagation effect is stored in the variable `inv`.

Notice that to get the current color, you can just do `starting_color xor inv`.

Now, suppose that the current color of root is same as desired color. This means that we cannot apply operations of the first kind. To use the operations of second kind, we need to invert twice to cancel the effect. So, apply operation 2 on the subtreee, and then operation 1 on the root to cancel the effect. The cost at this stage is 2. You also have a choice of not applying any operations, in which case the cost is 0.

Now, what if the root is inverted? In this case, you don't have the option to leave both operations. So, you can either correct root itself by one operation (with no propagation), or invert the entire subtree which automatically corrects root. Notice that this would create propagation. Finally, you need to take the minimum of the two.

Since there are 2 parameters in DP, we can use memoization while doing a DFS. 

The time complexity is `O(2*n) = O(n)`.

----

# Code
* [My Solution](solution.cpp)

----

