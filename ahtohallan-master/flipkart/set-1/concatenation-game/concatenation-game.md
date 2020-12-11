
[Editorial Page](../flipkart-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This question is directly taken from [GFG](https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/). It's a nice little use-case of **custom comparators**.

Let's convert all the numbers to strings via the `to_string()` method in *STL*.

Now, say, we have 2 strings, 548 and 60. It doesn't make sense to place the bigger number, i.e, 548 first. However, what we do know is that the number that would be formed would be either `str_1 + str_2` or `str_2 + str_1`. So, we'll greedily pick the one which gives us the most benefit at each stage.

Note that you can compare strings for lexicographic order as you would numbers.

----

# Code
* [My Solution](solution.cpp)

----

