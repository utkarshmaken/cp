[Editorial Page](../udaan-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This is my go-to question for **sets** (after **Knight Tournament**, of course). If you really want to go [this](https://i.kym-cdn.com/entries/icons/original/000/028/139/cover.jpg) route, you can just build a segment tree to query bitwise *OR*.

This question is a bit difficult for arrays in general, but is quite easy for strings. Why? It's because the answer would always be less than 26. Hence, for each character in the alphabet, we can check if it is present in the range or not.

Maintain 26 **sets**, where each `set` represents the index of all the occurrence of the particular letter (in a sorted manner). To figure out if a certain character is in the given range, just query the `lower_bound` of `left` and see if it lies within `[left, right]`.

To update, simply remove the occurence from the previous characters's set and add the occurence to the new character's set.

Time complexity is `O( 26*log(n))` per query.

[Official Editorial](https://codeforces.com/blog/entry/70233) 


----

# Code
* [My Solution](solution.cpp)

----

