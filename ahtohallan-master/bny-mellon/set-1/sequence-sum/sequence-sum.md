[Editorial Page](../bny-mellon-set-1.md)

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
The question is just plain observation. It should be clear that we want to sum up all the numbers in the range `[i, j]` and `[k, j)`. 

Consider the first summation. Suppose, there are `len` numbers between `i` and `j` (inclusive). The summation is nothing but `i*len + sum[1 : len - 1]`, where `sum[1 : len - 1]` denotes the sum of first `len - 1` natural numbers, which is nothing but `len*(len - 1)/2`.

We do the exact same thing for `[k, j)` noting that the formula for length would be altered as the interval is `closed-open`.

Finally, remember to handle overflows.

----

# Code
[Formula Based](sequence-sum-solution.cpp)

