
[Editorial Page](../microsoft-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)
* [My Solution](#my-solution)

<!-- vim-markdown-toc -->

----

# Intuition
If you think carefully, the number of elements in each level can become quite large. It can be solved in `O(L*M)` using DP.

Define `dp[v][layer]` as the count of elements in the subtree rooted at `v` at the layer `layer` (including itself).

First, let us see, how to perform the transitions in `O(M)`. Notice that

```cpp
dp[v][layer] = 1 + dp[0][layer + 1] ... dp[(v*V + 1)%mod - 1][layer + 1]
```

We have `L*M` states and `O(M)` transitions. Total complexity is `O(L*M*M)`.

If you've solved **Atcoder - Candies**, you can quickly recognize that we are interested in a contiguous block of elements.

Hence, we just populate the DP array in a reverse manner, and once we've finished a row, we convert it to a partial sum to allow `O(1)` RSQ.

----

# Code
# [My Solution](solution.cpp)

----
