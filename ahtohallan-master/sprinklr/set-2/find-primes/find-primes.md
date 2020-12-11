[Editorial Page](../sprinklr-set-2.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
It uses a new concept called **Binary Search on the answer**. If you aren't familiar with it, try solving [Split Array Largest Sum on LC](https://leetcode.com/problems/split-array-largest-sum/), [Allocate Books on IB](https://www.interviewbit.com/problems/allocate-books/) (which is a re-wording of the famous **Painter's Partition Problem**), [Mafia on CF](https://codeforces.com/problemset/problem/348/A) and [Monkey and Oiled Bamboo on UVa](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3183).

----

I'll assume that you're now familiar with the concept of binary search on the answer (which is really handy while solving `min/max` problems).

As with the first question, first run **Sieve** to quickly find out whether a number is prime or not.

We do not know the answer, but suppose I **guess** the answer. Can you tell me whether my guess is "valid" given the constraints. (Notice that we care about "valid" and not minimal. This means, if I guess the answer as `k`, then every window of size `k` should contain atleast `p` primes).

As succintly described in the [official editorial](https://codeforces.com/blog/entry/5648), you can easily observe that if your guess is "valid", you can easily discard the right half (because you know that the answer is atlest "k").

If your guess is invalid, you can discard the left half too. Why? This is because any guess from the left half would also be invalid. (because if some window of size `k` contains less than `p` primes, then surely all windows of size less than `k` cannot contain atleast `p` primes).

----

Diving deep, let us see how to validate a guess, say `k`. We want to ensure that every window of size `k` contains atleast `p` primes. To compute this quickly, convert the sieve array to a **prefix-sum** array. After this, you can quickly find the number of primes in a given interval. So, for each starting point of the window, compute the number of primes in that interval and terminate if it violates the condition. 

Notice that (almost) all of the element would be the start of some window. And the answer of each window is computed in `O(1)` by RSQ. So, in a single traversal we can verify our guess.

----

So, as we do in Binary search on Answer, start with the middle guess, check validity, and discard one half. Eventually, you'll reach the answer. Since, at each step you are dividing by 2, you need to make atmost `Log(n)` guess. Verification is done in `O(n)` for each guess. Hence, the total time complexity is `O(n * log(n))`. Here, `n` represents the length of the interval.

----

# Code
* [My Solution](solution.cpp)

----

