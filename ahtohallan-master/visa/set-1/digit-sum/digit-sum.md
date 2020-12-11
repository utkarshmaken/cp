
[Editorial Page](../visa-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
If you've solved the last 2 questions, this is quite easy as compared to them. Notice that the number can be of length atmost 18. Hence, the sum of digits would always be less than `165`. So, our plan is to find out the frequency for each sum, and print the maximal frequency. Notice that this has been converted to a simple Digit DP problem

> How many numbers less than or equal to high are there whose sum of digits is `req_sum`.

As with `Digit DP - Hello World`, define 

> `dp[pos][sum][flag]` represents the total numbers less than or equal to high, when digits upto `pos - 1` have already been placed and their sum is `sum` and `flag` tells us whether we have placed a strictly smaller digit in a siginificant position.

The transitions are exactly same as the last 2 questions. You can see my code for reference.

----

# Code
* [My Solution](solution.cpp)

----

