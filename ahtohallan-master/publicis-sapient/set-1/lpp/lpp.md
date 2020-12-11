
[Editorial Page](../publicis-sapient-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
	* [Finding LPP](#finding-lpp)
* [String Hashing](#string-hashing)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
The pre-requisite is **KMP Algorithm**. Make sure you learn it first through **CP-Algorithms** or any other resource. However, for this question, we'll use KMP as a **black-box**, without modifying the base code.

So, say we have an algorithm that can give us the **Longest prefix which is also a suffix** of any substring `str[0....]` in `O(1)`.However, there's a catch, i.e, the prefix and suffix can overlap. For example the LPS of `aaaa` is 3, as `aaa` occurs as an overlapping suffix and prefix.

> How do we modify this algorithm to compute disjoint prefix and suffix?

It's a well known trick. You can simply attach a character, say `$` at the end of the substring after which you want the disjoint prefix-suffix relation. Since `$` is not present in the alphabet, any prefix would not exceed `$` and any suffix would not start before `$`. Hence, we get disjoint prefix-suffix.

How do we solve the original question? Notice that as the name of the question suggests, you need to find `LPP`, i.e **Longest Palindromic Prefix**. The remaining characters can be mirrored to make a palindrome.

----

## Finding LPP
Let us assume that the LPP is `S`. So, the original string must be of the form

```
str = S + T
```

where `S` is the LPP, implying `rev(S) = S`.

We need to determine the length of `S` using KMP. Consider the string

```
new = str + $ + rev(str)
new = S + T + $ + rev(S + T)
new = S + T + $ + rev(T) + rev(S)
new = S + T + $ + rev(T) + S
```

Notice that the longest prefix which is also a suffix for the new string is `S`. However, we don't know what `S` is.

If you run KMP on the new string, the last value in the KMP array would be the length of `S`. Why?

Finally, the answer is `n - LPP`

# String Hashing
It can also be done in `O(n log(n))` using string hashing. 

> For LPP using hashing, we need to consider two hashes, one in forward direction and other in backward .. the key observation is  that for a substring to be a palindrome, it's forward hash == backward hash .. we can use this to get LPP.
The follow up question is, given several queries l to r, we need to answer if substring (l..r) is palindromic or not in O(1) (

* [Resource 1](https://cp-algorithms.com/string/string-hashing.html)
* [Resource 2](https://cp-algorithms.com/string/rabin-karp.html)

This blog would be updated once I learn "string hashing".

----

# Code
* [My Solution](solution.cpp)
* [Tester's Solution - Hashing](solution-hashing.cpp)

----

