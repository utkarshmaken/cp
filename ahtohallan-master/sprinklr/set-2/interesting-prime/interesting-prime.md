[Editorial Page](../sprinklr-set-2.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
The first step is to "quickly" answer whether a given number is prime or not. This is a well known technique (which I'm sure you must've encountered in ESC101). So, before you process any queries, you need to run **Sieve** to detect all prime numbers. Since the constraints are less than `1e6`, there's no issue in creating that big an array/vector or running a Sieve style loop. If you don't know about Sieve, you can refer to any of the materials out there.

----

Now, we can detect whether a number is prime or not in `O(1)`. Next up is some mathematical observations.

1. We don't care about numbers greater than `1e6`. Also, the desired number contains `a^2` as a sum. What is the (loose) upper bound on `a`? (Notice that `b^4` is positive). Clearly, `a` has to be less than `10^3`.
2. Again, we don't care about numbers greater than `1e6`. Also, the desired number contains `b^4` as a sum. What is the (loose) upper bound on `b`? (Notice that `a^2` is positive). Clearly, `b` has to be less than `10^2`. (In fact, this upper bound is very lenient, but let's not fine tune that much).

----

Let us forget about primality and focus on all numbers which can be written as `a^2 + b^4`. We have `100` choices for `a`, and `1000` choices for `b`. So, by simple combinatorics, total numbers has to be less than `10^5`. We can run sieve for `10^6` length array, surely we can also brutefoce all possible `a` and `b` values without time-out.

----

Now that we have all the numbers which can be written as `a^2 + b^4`, just discard numbers bigger than `1e6` and numbers which are not prime (recall that you can quickly check primality). Keep the resulting number sorted (after having removed possible duplicates).

----

Now that we have all the candidates for the answer, for each query, we just need to binary search the the next candidate greater than `n`. This can be easily done via `upper_bound` in **STL**. The count of numbers to the left of it would be our answer.

----

Notice that due to low constraints, you can even work with a single vector, where `vec[i] = 1` denotes that it is a candidate. Finally, convert it to a prefix sum, and answer queries in `O(1)` instead of `O(Log(n))`.

# Code
* [My Solution](solution.cpp)

----

