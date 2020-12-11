[Editorial Page](../udaan-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
	* [Do palindromes have a pattern for these numbers?](#do-palindromes-have-a-pattern-for-these-numbers)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This is a pretty good application of **bitmasking**.

Notice that we are only interested in the parity of a certain character, and hence the frequency doesn't matter. So, let us convert each string into a 26-Bit number, where the `i-th` bit is `1` if the parity of the `i-th` character of the alphabet is 1 in the given string. So, if `a` is present even number of times, the least significant bit would not be set. On the other hand, if `a` is present odd number of times the least significant bit would be set.

Now, we have an array consisting of `n` numbers. Let us see what "concatenation" means in terms of these numbers. After concatenation, the frequency of each character would be summed up. Since we only care about parity, 2 *even* would merge to *even*, 2 *odd* would merge to *odd*, *odd* + *even* would merge to odd. 

In other words, we need to take the bitwise **XOR** of the resulting numbers.

## Do palindromes have a pattern for these numbers?

Yes, notice that a palindrome can have atmost one set bit, i.e, atmost one character with odd parity. What's more, you also know this property is only followed by a number which is a power of 2.

So, we just need to find out the number of pairs `a[i]` and `a[j]` such that `a[i] xor a[j]` is a power of 2. Notice that we don't know which power of 2, but any power is acceptable. So, let us guess that the power is `2^k`. Clearly, we need to vary `k` over all possible values to ensure that we don't miss out on any guess.

So, the question boils down to, 

> Given an array of `n` numbers, and an integer `k`, find out how many pairs are there such that `a[i] xor a[j] = 2^k`.

A well known fact is that the additive inverse of xor-operation is the number itself, i.e,

```
unknown xor a = known ===> unknown = a xor known
```

Hence, for each `a[i]`, we need to find out the frequency of `a[i] xor 2^k` in the array. This can be easily done with a map of frequencies.

You also need to handle the case where there are no characters with odd frequency in the resulting concatenation.

Time complexity is `O( n log(n) )`.

**P.S** : I have no idea whether this tutorial is too-short/too-long (which depends on how much you are already familiay with **bitmasking** and **xor**. So, feel free to ask on the Slack channel if you feel I missed out on important points. Or read about Bitmasking in general, from any CF/CP blog).

[Official Editorial](https://bubblecup.org/Content/Media/Booklet2018.pdf) 

----

# Code
* [My Solution](solution.cpp)

----

