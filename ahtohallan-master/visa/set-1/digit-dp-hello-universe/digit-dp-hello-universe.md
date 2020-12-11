
[Editorial Page](../visa-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [DP + Combinatorics (by youKnowWho)](#dp--combinatorics-by-youknowwho)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
Notice that the author forgot to mention that the code would give incorrect output if `d == 0`. This is because you'd end up counting prefix zeroes too.

To handle this, we just need an extra parameter that tells us whether the number has started or not. If it hasn't started, don't count the zero, if it has, count it. So, 

> `dp[pos][cnt][flag][started]` represents the total number less than `high` when the digit upto `pos - 1` is already decided, and the digit `d` is already used `cnt` times, and `flag` tells us whether you've placed a strictly smaller digit in a significant place and `started` tell us whether the number has started.

The transitions are exactly the same (with the addition of cases for `started`). You can see my code for reference.


# DP + Combinatorics (by youKnowWho)
Let us first solve the **Hello World** question. To summarize, we need to find the number of numbers which lies between `a` and `b` (inclusive), and contains the digit `d` exactly `cnt` times.

Let's say we have a function `F(n) = number of numbers <= n` , such that the number contains digit `d` exactly `cnt` times. It’s easy to observe that our final answer will be `F(b) - F(a-1)`.

Let us learn how to calculate `F(n)`. For the sake of example, let `n = 7245`, `d = 4`, `cnt = 2`.

Let us start with the most significant digit, having face value 7. If I place a smaller digit than 7 at this position, the resulting number will be less than `n`, independent of how we choose further digits. So it naturally makes sense to make 2 cases, first - we choose a smaller digit. Second - we choose the same digit.

To handle case 1, now we want to fill remaining positions with 2 `d`, and remaining positions have 9 options (other than `d`). (Note that if the first digit is `d` itself, then we want to fill only 1 `d`). This is a simple combinatorics task. See my code to check the formula in case you are not sure.

Now, if the first digit is 7, we need to perform the above task again, with an effective number as 245, `d = 4, cnt = 2`. This points towards recursion. See the function - `function_` in my code, it does the exact same thing.

**Hello Universe**

Now, what is so special about the digit 0 ? Well, in 0070 - we only count the number of zeros as 1, instead of 3. So let us handle the case of 0 separately.

Let say we have `i` (>= 1) zeros in the starting of the number. Note that putting at least 1 zero in the front ensures that the resulting number will be less than `n`, and hence we can freely choose further digits (and hence, apply combinatorics). After `i` zeros, there must be non-zero digits (9 choices), and then we need to fill `cnt` 0s and remaining places by non-zero digits. Get the formula for the number of ways.

If we have a non-zero digit in the starting, then note that 0 will act as any other digit. So you can use the above function `(function_)` for calculating the answer.

----

# Code
* [My Solution](solution.cpp)
* [Tester's Solution](tester.cpp)

----

