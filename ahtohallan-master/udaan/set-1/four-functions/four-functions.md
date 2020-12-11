[Editorial Page](../udaan-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [A and B are a Red-Herring](#a-and-b-are-a-red-herring)
* [Utilizing Sieve for Prime Factorization](#utilizing-sieve-for-prime-factorization)
* [Prime Factorization using SPF](#prime-factorization-using-spf)
* [Time complexity of Factorization](#time-complexity-of-factorization)
* [Computing C in O(n log(n) )](#computing-c-in-on-logn-)
* [Computing C in O(n loglog(n) )](#computing-c-in-on-loglogn-)
* [Computing D in O(n)](#computing-d-in-on)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
The question is a simple modification of `Sieve`.

----

# A and B are a Red-Herring
Notice that `A(x)` is nothing but **Euler's Totient/Phi Function**. You can read about it [here](https://cp-algorithms.com/algebra/phi-function.html#:~:text=Euler's%20totient%20function%2C%20also%20known,be%20coprime%20to%20any%20number). 

Also, notice that `B(x)` is the sum of `phi(d)` where `d` divides `n`. This value comes out to be `n` for all positive integers. (It's not so trivial, and don't worry if you didn't know this beforehand, now you know!).

[Find a Good Proof Here](https://proofwiki.org/wiki/Sum_of_Euler_Phi_Function_over_Divisors)

**Conclusion** : `B(x) = x`. In other words, `B` is an identity function

----

# Utilizing Sieve for Prime Factorization
This is very famous technique, called `smallest-prime-factor`. Don't worry if you haven't heard about it, it's simple to grasp, provided you know *Why* Sieve works, rather than just *How*.

So, in Sieve, we pick a **prime number** and strike out every multiple of that prime (as those multiples can't be prime). We repeat this for every number.

Come to think about it, it's already pre-decided which number would be striked out by which prime. More specifically, let us call the smallest prime factor of a number as `spf`. Clearly, it would be striked out by `spf`. (In fact, it would be striked out by all its prime factors, but we are only interested in the first strike).

So, while performing Sieve, instead of storing `True/False`, we can just store the first prime which striked out this number.

----

# Prime Factorization using SPF
Now that we have the smallest prime factor for all integers, we can factorize any number in `O(log (n))`. We can find out all its prime factors as well as their multiplicity/expoent using `spf`.

Say, we want to factorize `num`. We know that the smallest `prime` factor is `spf[num]`. So, we keep on dividing it by this prime factor, until it's no longer divisible. Now, we get another number. And we just recurse on it by again calculating `spf`. Clearly, the number of times the divison occurs is the multiplicity, and all the distinct `spf` encountered in this process are the prime factors.

----

# Time complexity of Factorization
Why is the factorization bounded by `O(log (n))`? You need to realize that at each step we are dividing by `spf`, which is greater than or equal to 2. In the worst case, we may end up dividing by the smallest number at each step, i.e, 2. However, it is a well-known fact that if you repeatedly divide a number by `2`, you'd end up with 1 in no more than `log(n)` steps. Hence, it's bounded by `O( log(n))`.

----

# Computing C in O(n log(n) )
Just run a `spf` style Sieve, recording the smallest prime factor of each number. Then, for each number, just factorize it and compute `C(num)` as the sum of exponents.

----

# Computing C in O(n loglog(n) )
Just run a `spf` style Sieve, recording the smallest prime factor of each number. Now, notice that

```
C(num) = 1 + C(num/spf[num])
```

These are `O(1)` transitions, hence `C` can be filled in linear time after having computed `spf`.

----

# Computing D in O(n)
Just convert `C` to a prefix sum array

----

# Code
* [My Solution - O(n loglog(n)) ](solution.cpp)
* [My Solution - O(n log(n)) ](solution-v1-ac.cpp)

----

