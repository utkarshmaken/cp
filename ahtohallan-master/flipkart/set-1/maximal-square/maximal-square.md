

[Editorial Page](../flipkart-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This is a pretty standard question on [LeetCode](https://leetcode.com/problems/maximal-square/). The top voted solution on **Discuss** does a good job of explaining things. 

Define, `dp[i][j]` as the largest side square whose right-end point is `(i, j)`. To perform the transitions in O(1), notice that for `mat[i][i] == 1`, 

```
dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
```

Time complexity is `O(n^2)`.

Finally, note that this question can also be solved by resuing the code from **Maximal Rectangles**. (Once you've found out the left and right boundaries of each element, you need to take the `min` of them to create squares instead of rectangles.

----

# Code
* [Solution using DP](solution.cpp)
* [Solution using Stacks](solution-stacks.cpp)

----

