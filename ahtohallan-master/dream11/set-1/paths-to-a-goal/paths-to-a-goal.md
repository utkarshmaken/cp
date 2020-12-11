[Editorial Page](../dream11-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [An alternate approach (by ...)](#an-alternate-approach-by-)
* [A yet another approach (by gerrob)](#a-yet-another-approach-by-gerrob)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
As with **Fun with Vowels**, my solution is lengthy. Please look into the alternatives codes provided at the end.

----

The bottleneck of the question is to handle duplicate subsequences. In any DP question on subsequences, why do duplicates occur? It's because sometimes we leave an element and take the same element at the next step.

For example, for the string `rrlrlr`, the number of **unique** subsequences of length 2 containing just `r` is 1, i.e `rr`. However, with naive DP you overcount, as sometimes you leave the first `r` and immediately take the second/fouth/sixth  one.

So, to get rid of duplicates, we can create a rule,

> If you left an element at the last stage, you cannot take the same element at the next (immediate) step. (Because if it was important to you, why did you leave it in the last step?

In other words,

> We will always consider **lexicographically smallest sequence (by indices)** in-case of duplicates.

This gives us a hint that we also need to keep track of the last choice. There can be 4 choices.

1. At the last step, you `ignored_l`.
2. At the last step, you `ignored_r`.
3. At the last step, you `ignored_both`.
4. At the last step, you `ignored_none`.

Now, let us define a **DP** 

> `dp[ind][start][state]` represents the number of **unique** subsequences of `str[ind...]` that start at `start`, and `state` denotes what you did in the last step. Note that all subsequences finish at `finish`, hence it is not included as a DP parameter.

Although we are talking about iterative DP definition, we'll implement the same via **memoization**. 

To perform the transitions, note that : 

1. **State** : `ignored_l`
	* If at last step, you ignored `l`, and now you see another `l`, you **have** to exclude it, no matter what. However, if you see an `r` at the current step, you have a choice to take it, in which case the state becomes `ignored_none`, or leave it, in which case the state becomes `ignored_both`.

2. **State** : `ignored_r`
	* If at last step, you ignored `r`, and now you see another `r`, you **have** to exclude it, no matter what. However, if you see an `l` at the current step, you have a choice to take it, in which case the state becomes `ignored_none`, or leave it, in which case the state becomes `ignored_both`.

3. **State** : `ignored_both`
	* If at last step, you ignored both `l` and `r`, you **have** to exclude them now too.

4. **State** : `ignored_none`
	* If at last step, you didn't ignore anything, you have a choice to do anything with the current character. Just fill the next state carefully.

Of course, if at any step, you take `r`, you need to recurse on `dp(ind + 1, start + 1, next_state)`. If you take `l`, you need to recurse on `dp(ind + 1, start - 1, next_state)`.

----

**The Base Case** : This is surprisingly simple. If you go off the number line, return 0. If the string finishes off, return 1 **iff** you are at your target. 

Finally, the answer would be `dp[0][original_start][ignored_none]`

----

# An alternate approach (by ...)
This is an intuitive solution which builds upon a simple DP defintion. I haven't gone through it in detail yet, so I'll just quote the summary and link the code.

> I've done a simple 3D dp, where `dp[i][j][k]` is the subsequences till the ith character of the string which reaches `j`, and `k` is 0 or 1 depending on whether it ends with `r` or `l`.

> Then the transition is simply noting that if the current character is `c`, then the the remaining subsequence reaches `j+-1` (depending on `c`) and can use letters till `i-1`.

----

# A yet another approach (by [gerrob](https://leetcode.com/gerrob/))
Quoting the summary.

> OK, it was somewhat tricky solution for the original problem in `O(L^2)` time (basically in `O(L*min(n,L))` time). The time usage is also `O(L^2)`.

> (Tricky because in `O(L^3)` time it would be much easier, I had this quite quickly).

> Say we have still the characters in `S` from `i`, then in `dp[i]` store in an unordered map where could we be, with how many subsequences. As we need to count each subsequence only at once we "have" to choose in a greedy way: if we go left then choose the earliest left character in the string, if we go right then choose the earliest `r` character.

> To get this in `O(1)` time just precompute where are the next `l`, `r` in the string. Note that we don't store the number of characters used in the string that is why this is not an `O(L^3)` time algorithm. If we arrive at `y` then we just add this count to the answer.

----

# Code
* [My Solution](solution.cpp) : (First idea, Memoization)
* [Solution 1](solution-1.cpp) : (First idea, Iterative DP)
* [Solution 2](solution-2.cpp) : (Second idea)
* [Solution 3](solution-gerrob.cpp) : (Third idea)
* [Submission 4](https://codeforces.com/gym/285752/submission/85550879)
* [Submission 5](https://codeforces.com/gym/285752/submission/85553312)

----


