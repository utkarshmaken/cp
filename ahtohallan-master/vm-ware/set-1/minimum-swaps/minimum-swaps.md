[Editorial Page](../vm-ware-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition (via Graphs)](#intuition-via-graphs)
* [An alternate approach (by Lavish)](#an-alternate-approach-by-lavish)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition (via Graphs)
Let us visualize this a **directed graph** on `n` vertices. We say that there is an edge from `i` to `j` if the sorted position of `i` is `j`. Of course, each vertex would either contain a self-loop or contain exactly one outgoing and one incoming edge.

Observe that this graph would contain several **disjoint cycles**. A cycle represents a series of swaps that must be done to correct the elements which are part of the cycle.

**Theorem** : A cycle of length `len` can be corrected in `len - 1` steps. 

**Proof** : Start with any vertex as the buffer, and keep swapping it with the correct position of the current number. At the end of the operations, the buffer would be corrected automatically. 

All that remains is to find the number of vertices in each simple cycle. This is easy, given the special structure of the graph. You just start a **DFS** from each unvisited vertex and keep track of the number of vertices seen so far. Each of them would be a part of the same cycle.

----

# An alternate approach (by Lavish)
Sort the given array ( so now we know correct position of each element).

To bring any number at its current position, we need 1 swap. Do it, and make appropriate changes ( use a map to store index of each number in given array )

----

# Code
* [DFS](solution.cpp)
* [Tester's Solution](solution-tester.cpp)

----

