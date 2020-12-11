[Editorial Page](../udaan-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This is **exactly** the same question as **String Formation** from **Clumio**. Serioulsy, if you aren' upsolving the questions, I just have one advice for you : **Stop giving these contests**.

We need to find out the number of subsequences of `source` which matches the `target` string. Define `dp[i][j]` as the number of subsequences of the first `i` characters of `source` which matches the first `j` characters of `target`. To perform the transitions, just notice that if `source[i] == target[j]`, you have 2 options : Either leave out the `i-th` character of source, in which case you recurse on `dp[i - 1][j]`, or you take it in which case you recurse on `dp[i - 1][j - 1]`. Since there are no constraints, you can make both choices, hence you need to sum up the values. Of course, if the characters don't match, you have to necessarily leave the `i-th` character of `source` and recurse on `dp[i - 1][j]`.

Time complexity is `O(26*n)`.

----

# Code
* [My Solution](solution.cpp)

----

