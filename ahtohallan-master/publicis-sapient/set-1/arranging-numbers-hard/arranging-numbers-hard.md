[Editorial Page](../publicis-sapient-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [The Intended Solution](#the-intended-solution)
	* [Are all the states visited?](#are-all-the-states-visited)
* [Drop a parameter and recover it from other dimensions](#drop-a-parameter-and-recover-it-from-other-dimensions)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This is the same question as **Atcoder Educational DP -- Matching**. The only difference is that a backtracking solution with good pruning would pass the time limit for easy and medium version). (Not sure about the hard version though).

The backtracking one is easy, just try all combinations. To squeeze into time limit, terminate the recursion as soon as you see an odd placement, rather than checking at the end.

----

# The Intended Solution
Define `dp[i][mask]` as the number of arrangements of positions `[0...i]` when the set bits in mask are available. To perform the transitions, try every set bit and see if it divides the position. If it does, recurse on `[i - 1]` by turning off the used bit.

Our final answer is `dp[n - 1][full_set_mask]`.

There are `O(n*2^n)` states and `O(n)` transitions. The time complexity is `O(n*n*2^n)`. Clearly, this won't fit in TL of hard version.

----

## Are all the states visited?
However, if you use memoization instead of iterative procedue, you'll get AC with the same DP definition. Why does this happen? (For more insights, you can read the CF announcement blog for the Atcoder contest). Here's a short summary.

If you use memoization, for each `i`, only those states would be visited whose set bits is `(i + 1)`.

Hence the number of nodes in each level is : 

```
nC1
nC2
nC3
.
.
.
nC0
```

Clearly their sum is `nC0 + ... nCn  =  2^n`. Hence, we visit `2^n` states and transition is `O(n)`. Time complexity is `O(n*2^n)`, which would pass easily for the hard version.

This is one of the rare questions where people who prefer memoization might get lucky. (Although they are at a disadvantage in **Atcoder -- Candies**).

----

# Drop a parameter and recover it from other dimensions
How do we implement the idea iteratively?

As was the case with **Diamond Mine** from **MathWorks**, you don't need 2 dimensions. Notice that the first dimension can be extracted by counting the number of set bits. So, you just define `dp[mask]` to be the number of arrangements where the number of positions is determined by the mask. During the transition, set bit count increases by 1.

The time complexity of this is also `O(n*2^n)`.

----

# Code
* [My Solution - Memoization](solution.cpp)
* [My Solution - Iterative, TLE](solution-iterative.cpp)

----

