
[Editorial Page](../publicis-sapient-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Smallest Period of a string](#smallest-period-of-a-string)
* [A Linear Time Solution](#a-linear-time-solution)
* [Application of KMP](#application-of-kmp)
* [String Hashing](#string-hashing)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
To check if the big string is divisible by the smaller one, we can first check if the length of `small` divides the length of `big`. If it does, we concatenate `small` to itself untill it becomes the same length as `big`. After that we can just check for equality using `==`.


**Catch 1** : Don't concatenate `small` with `small` with each time. (Why?) Use a backup copy and concatenate the copy to the starting string at each stage.

**Catch 2** : There's a difference between `str = str + conc` and `str += conc`. One would lead to TLE. Which is which and why?

Note : You can also check the condition without concatenatating. Just check if `big.substr(i, small_len)` is equal to `small` for every `i` in `{0, k, 2k, ....}`.

The time complexity is `O(n)`.

----

# Smallest Period of a string
Assume that the big string is divisible and we need to find the smallest period of the small string.

**Let us see a solution with time complexity** `O(n^2)`

Just try every prefix and see if it can be concatenated to form the original string using the described above.

**How can we improve the time complexity to** `O(pow(n, 4/3))`?

Notice that not every prefix is a possible candidate. In other words, only try the prefixes of length `len` such that `len` divides the length of the original string. 

> The number of divisors of a number is roughly of the order of `pow(n, 1/3)`

For each divisor, verification is done in `O(n)`. Hence the total time complexity is `O(pow(n, 4/3))`.

# A Linear Time Solution
The pre-requisite is **KMP Algorithm**. Make sure you learn it first through **CP-Algorithms** or any other resource. However, for this question, we'll use KMP as a **black-box**, without modifying the base code. (Of course, it can also be done using `Z array`).

This was the intended solution. However, come to think about it, with the given constraints, `O(pow(n, 4/3))` works just fine. We over-estimated the difficulty of the problem.

Let us say the smallest period is `S`. The string looks like : 

```
str = S + S + S + .... + S

str = k*S
str = (k - 1)*S + S
str = S + (k - 1)*S
```

Notice that if you run KMP on this string, the length of the longest prefix which is also a suffix is `(k - 1)*S`. In other words, the LPS contains everything except one period. So, if we subtract this LPS value from the length, we get the period's length.

In other words, the period length is 

```
period_len = string_len - LPS.back
```

**Catch 1** : With the above reasoning, it looks trivial that LPS would leave out just one period. However, it's not so trivial. We can guarantee that is atleast `(k - 1)*S`, but why shouldn't it be more than that? Think about smallest period.

**Catch 2** : Once you get the guess of the period length, you still need to verify the guess through divisibility and concatenation. The above method guarantees that if the string is periodic, it would give you the correct answer. However, it might return some random(!) values when the string is not periodic. 

As a fun fact, notice that you can verify the guess by just checking if period divides the length. You don't even need to concatenate. Why does this work?


# Application of KMP
The next question is a good application. However, you should also try **Pattern Matching** in **Linear Time**.

# String Hashing
It can also be done in `O(n log(n))` using string hashing. 

>  The divisibility question is straightforward (check all prefix of length `k` such that `k` is a factor of `t.size()`)

* [Resource 1](https://cp-algorithms.com/string/string-hashing.html)
* [Resource 2](https://cp-algorithms.com/string/rabin-karp.html)

This blog would be updated once I learn "string hashing".

----

# Code
* [My Solution](solution.cpp)
* [Tester's Solution - Hashing](solution-hashing.cpp)

----

