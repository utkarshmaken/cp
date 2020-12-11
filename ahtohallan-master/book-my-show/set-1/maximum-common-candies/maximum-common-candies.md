
[Editorial Page](../book-my-show-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Debugging Tips](#debugging-tips)
* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Debugging Tips
* If you are getting a **WA**, open the current folder in **Github** and look into the file `gen-man-1.txt` and `gen-man-2.txt` for corner cases.
* If the error persists, consider [stress-testing](../../../documentation/stress-testing.md) your solution.

----

# Intuition
The graph structure is same as **Shared Interests** from **Clumio** (but with better explanation). As with the old question, I'll just state the problem precisely in terms of graph, after which I think it should be trivial.

> You are given a graph with 100 type of coloured edges. Let us fix a colour and forget all the edges without this color. Notice that this would give you an undirected graph. In this graph, find the size of the largest connected component, say `max_size`. Repeat this for all colours and find the global maximum, i.e, `global_max_size`. Now, for all the colours which contain a connected component of this size, find out the maximal pairwise product and take the maximum of them.

For the implementation, notice that once you fix a color, the question just tells you to find out the size of largest connected component. So, perform a `dfs` for each component and store all the elements in a vector. Once the `dfs` is complete, you have the size of the component. Once all the `dfs` is complete, you can find the largest vector, and record just the maximal pairwise product of this component.

----

# Code
* [My Solution](solution.cpp)
* [Tester's Solution](stupid.cpp)

----
