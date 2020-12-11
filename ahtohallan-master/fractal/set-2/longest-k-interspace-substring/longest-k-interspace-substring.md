[Editorial Page](../fractal-set-2.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

Wondering what the third test-case was? It was a string of length 1.

Some Tips :

1. If you are getting *WA* on test-case 3, your algo might be correct and you missed out on a corner case.
2. If you are getting *WA* on test-case 4, your algo is incorrect.
3. If you are getting *TLE* on test-case 14, the time complexity of your solution is too high.

----

# Intuition
The main idea is similar to the **Dynamic Programming** formulation in **Kadane's Algorithm**.

Define `dp[i]` as the longest `k` interspace substring starting at `i`. It has a one-liner transition :

```
if adj_diff is <= k
	dp[i] = 1 + dp[i + 1]
else
	dp[i] = 1
```

This works because if the current difference is less than or equal to `k`, then you can always prepend `i-th` element to the longest valid substring starting at `i + 1`.

Once you have calculated the DP array, find the maximal element and then return the substring at the first `i` such that `dp[i]` is maximal.

----

# Code
[Linear DP](solution.cpp)

----
