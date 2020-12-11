
[Editorial Page](../vm-ware-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Update](#update)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
The [official editorial](https://codeforces.com/blog/entry/8192) is good enough.

One approach is to **binary search on the answer space** to get the number of mixed garlands. This is a safe bet if you don't want to invest time in the proof of correctness. Special mention to [CrossHair777](https://codeforces.com/profile/CrossHair777) who solved it using this technique.

However, there's even a simpler solution. Here is a simple theorem which would remove all doubts on the proof of correctness.

**Theorem** : There always exist an optimal solution with less than 3 *mixed garlands*.

**Proof** : Observe that if there is an optimal solution with atleast 3 *mixed garlands*, you can just turn them into 3 *monchromatic garlands*. You can keep repeating the process untill you are left with strictly less than 3 *mixed garlands*.

So, now you just need to guess the number of *mixed garlands* as 0, 1, or 2 and then form the monochromatic garlands greedily. Finally, take the maximum.

# Update
Some clarification on the model solution for `Ciel and Flowers`.

At the time of solving the question, I was having some issues switching to C++17. Hence, the comments are just a note to self rather than to the audience. Now, I know how to compile it with C++17, so naturally, I'd have used tuples.

To conclude, if you are using C++14/17, this should work well

```
max({a, b, c})
```

----

# Code
[Code](solution.cpp)

----

