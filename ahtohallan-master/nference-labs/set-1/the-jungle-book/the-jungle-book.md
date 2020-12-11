

[Editorial Page](../nference-labs-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This is exactly the same problem as **Atcoder Educational DP -- Longest Path**. Finding LP in a DAG is a pretty famous problem and I'm sure you can find lots of good resources on the internet. If I recall correctly, **CLRS** also has a good discussion on it. Here's my short summary : 

Noitce that you are given a **DAG**. Consider the longest path in the `DAG` (w.r.t to the vertices). Clearly, the answer has to be atleast `len` as you need to keep these species in separate boxes. However, notice that there exists a solution with exactly `len` boxes. How? For each shorter path, just place all the nodes in the path in adjacent boxes. We'll never run out of boxes, as the length of any path cannot be greater than `len`.

To compute longest path, one way is to use **Kahn's Topological Sorting Algorithm** to obtain one topological order. Now, define `dp[source]` as the longest path starting at `source`. Clearly, 

```
dp[source] = 1 + max(dp[child])
```

If we fill the DP in **reverse** order of any topological ordering, we'll get the time complexity of `O(V + E)`.

Another approach is to use `DFS` to compute the topological order, as well as populate the DP on the fly. Assume the same DP definition. To populate it without doing a topo-sort first, notice that `dp[source]` depends on `dp[child]`. So, you can recursively compute `dp[child]` before updating `dp[source]`. If you maintain a `visited` array, the time complexity is `O(V + E)`. 

**Catch** : If you're using the recursive version, make sure to the start the DFS call from every unvisited vertex.

----

# Code
* [My Solution - Kahn's + DP](solution.cpp)
* [My Solution - DFS + DP](solution-dfs.cpp)

----

