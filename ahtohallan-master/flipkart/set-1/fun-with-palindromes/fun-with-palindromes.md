

[Editorial Page](../flipkart-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
If you've solved [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/), this question should've been a cake-walk. However, after talking to a couple of people after the contest, I realized that they couldn't solve it, even after having done LPS before.

**The reason?** : They did **LPS** by reversing the string and finding the **LCS** between them. Although it does solve the LPS question, it takes away the intuition behind the DP and you cannot blindly use the code for this question. (However, it's still solvable using this trick if you think about what `dp[i][j]` represents. But let's not get into that). Note that this is a trick to solve LPS, but LPS deserves its own DP as you would create for **Edit Distance, Subset Sum, Knapsack, LCS**, etc.

If you'd solved LPS by creating its own DP table, you'd recall the definition, `dp[i][j]` is the longest palindromic subsequence of `str[i...j]`. So, not only are we solving LPS for original string, we are solving a lot of questions inside one. For example, after having computed the DP table, I can quickly answer the LPS of any substring.

How can this help us? Notice that the 2 subsequences would be disjoint (as they cannot be interleaved). Let us fix a boundary, say, `k`. Once this boundary is fixed, we can greedily select the LPS for left half and for right half to maximize the product.

Finally, we do not know the actual boundary, so we'll just make a guess from `0` to `n-2` and take the best out of them.

How to calculate the answer once the boundary is fixed? It is simply `dp[0][k]` for the left half and `dp[k + 1][n - 1]` for the right half.

----

# Code
* [My Solution](solution.cpp)

----

