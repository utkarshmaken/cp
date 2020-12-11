
[Editorial Page](../microsoft-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
For each character, let us record the index of the first and last occurence. Now, just guess the final character at the first and last positions and calculate the cost. (Naturally, you'd move first occurrence to the left, and last occurrence to the right). Fix these 2 positions, and the remaining order would be untouched. You just need to recurse on the inner string of length `(n-2)`.

Time complexity is `O(n^2)`.


I don't see a nice proof of correctness, but it's correct. (or atleast it was the AC solution in the original contest, and on the question on **Codechef** by the name **Distorted Palindromes**).

----

# Code
* [My Solution](solution.cpp)

----
