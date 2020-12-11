[Editorial Page](../vm-ware-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Handling corner cases via Sentinels](#handling-corner-cases-via-sentinels)
* [Code](#code)

<!-- vim-markdown-toc -->

----

If you got a **WA/RE** on 256, you should read the constraints carefully next time.

Like I said earlier, you can create a vector of length 0, but not an array of length 0.

----

# Intuition

First, sort the packets according to the left end-points.

Notice that we are not concerned about the numbering of the packets. The important information is :

> What is the size of each un-uploaded chunk which is sandwiched between 2 uploaded ones.

Let's call this size as `gap`. Since we cannot merge or rearrange the un-uploaded packets, our goal should be to upload the packet of size `gap` in minimum number of moves possible.

Recall that you can only upload packets in `powers_of_2`. Also, `gap` can take any value between `1` and `1e18`.

So, we'd like to answer the general question : 

> Given a big integer, represent it as sum of `powers of 2` in minimum steps.

Here's a fact that might be obvious to some and new to others.

**Theorem** : Any number can be expressed as the sum of `powers of 2`.

**Proof** : Notice that every number has a binary representation. How do we switch to decimal representation from the binary representation? We just represent it as `2^0*a[0] + 2^1*a[1] + .... 2^(n-1)*a[n-1]`, where each `a[i]` is `1` if the corresponding bit is set and `0` otherwise.

**Lemma** : The above representation also gives us the minimum number of steps.   

**Proof** : Use the fact that `\sum{2^0 + 2^1 .... 2^(n-1)} = 2^n - 1`. In other words, if you ignore the highest set bit, you cannot compensate even by taking all the lower bits.


So, we just need to find the number of **set-bits** in `gap` and add it to our final result. Although you can do it in `O(log(n))` using a `while` loop, there exists a simple ~~`O(1)`~~ `O(log (n))` (but a lot faster) method via the STL function `__builtin_popcountll(num)`.

**Note** : Since the `gap` can be huge, use `__builtin_popcountll()` instead of `__builtin_popcount()` to avoid **WA**.

----

# Handling corner cases via Sentinels
Notice that you'd have to do a bit of case analysis depending on whether the first and last packet is uploaded or not. However, to make things simpler, you can just insert 2 uploaded packets at `(0, 0)` and `(total_packets + 1, total_packets + 1)`. 

----

# Code
[Popcount](solution.cpp)

----
