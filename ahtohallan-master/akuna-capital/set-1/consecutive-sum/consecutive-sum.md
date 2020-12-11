
[Editorial Page](../akuna-capital-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
Express the number as 

```
n = x + (x + 1) + (x + 2) + ... + (x + k - 1)
n = x*k + sum(i) for i in range[1, k - 1]
n = x*k + k*(k - 1)/2
x*k = n - k*(k - 1)/2
```

Notice that `k` is unkown. So, we just need to guess `k`. Also notice that the guess would be less than `sqrt(n)` which would fit in TL. So, let's bruteforce all possible guesses.

The `rhs` is obviously an integer, we just need to see if it is divisible by `k` or not. If it is, we divide it, and we get an answer.

Time complexity is `O(sqrt(n))`.

----

# Code
* [My Solution](solution.cpp)

----

