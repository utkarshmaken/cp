[Editorial Page](../dream11-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
There are a lot of great solutions available on the **Submissions** page. You should definitely go through them as they are much better than the editorial. I'll also link the ones that I found interesting in the [Code](#code) section.

----

I'll outline my approach, which is a bit long (not because of logic, but because of code-repetition). I could've tried to compress it by using a 2D DP matrix, but why bother :)

----

If you try to define a simple DP, like `dp[i]` represents the longest subsequence of vowels in order, etc, you would find it almost impossible to perform the transitions.

Let us define 5 DP.

1. `dp_u[ind]` represents the longest sequence of the form `u*` of the segment `[ind...]`.
2. `dp_o[ind]` represents the longest sequence of the form `o*u*` of the segment `[ind...]`.
3. `dp_i[ind]` represents the longest sequence of the form `i*o*u*` of the segment `[ind...]`
4. `dp_e[ind]` represents the longest sequence of the form `e*i*o*u*` of the segment `[ind...]`.
5. `dp_a[ind]` represents the longest sequence of the form `a*e*i*o*u*` of the segment `[ind...]`. 

**Note** : Unlike **RegEx**, `*` here means multiple copies of the preceding character. So, `e*` means multiple copies of `e` (but it should not be empty).

----

Perform the transitions is easy(and repetitive).

1. **Transitions for** `dp_u`
	* If the current character is `u`, it can only contribute 1 to length of `dp_u[ind + 1]`.

2. **Transitions for** `dp_o`
	* If the current character is `o`, it can either support `dp_o[ind + 1]` by 1 unit, or start the series `ou*` for the first time (provided either of them has started).

3. **Transitions for** `dp_i`
	* If the current character is `i`, it can either support `dp_i[ind + 1]` by 1 unit, or start the series `io*u*` for the first time (provided either of them has started).
 
4. **Transitions for** `dp_e`
	* If the current character is `e`, it can either support `dp_e[ind + 1]` by 1 unit, or start the series `ei*o*u*` for the first time (provided either of them has started).

5. **Transitions for** `dp_a`
	* If the current character is `a`, it can either support `dp_a[ind + 1]` by 1 unit, or start the series `ae*i*o*u*` for the first time.

----

By looking at the transitions, we can easily populate the DP in a single pass if we iterate it backwards. The answer would be `dp_a[0]`.

Finally, the time complexity is `O(n)`.

----

# Code
* [My Solution](solution.cpp)
* [Submission 1](https://codeforces.com/gym/285752/submission/85553850)
* [Submission 2](https://codeforces.com/gym/285752/submission/85551999)
* [Submission 3](https://codeforces.com/gym/285752/submission/85552675)
* [Submission 4](https://codeforces.com/gym/285752/submission/85546716)
* [Submission 5](https://codeforces.com/gym/285752/submission/85546953)
* [Submission 6](https://codeforces.com/gym/285752/submission/85545170)

----

